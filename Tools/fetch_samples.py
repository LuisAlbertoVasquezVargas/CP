#!/usr/bin/env python3
"""Save Codeforces sample inputs and outputs using only the standard library."""

import argparse
from html.parser import HTMLParser
from pathlib import Path
import re
import sys
from urllib.error import URLError
from urllib.parse import urlsplit
from urllib.request import Request, urlopen


def problem_index(url):
    parts = urlsplit(url)
    if parts.scheme != 'https' or parts.hostname not in (
        'codeforces.com', 'www.codeforces.com', 'sas.codeforces.com',
    ):
        raise ValueError('Use an HTTPS Codeforces problem URL.')
    match = re.fullmatch(
        r'/(?:contest/(\d+)/problem|problemset/problem/(\d+))/([A-Za-z][0-9]*)/?',
        parts.path,
    )
    if not match:
        raise ValueError('Expected /contest/ID/problem/B or /problemset/problem/ID/B.')
    return match[3].upper()


class SampleParser(HTMLParser):
    """Read only pre blocks inside sample-test input/output sections."""

    VOID_TAGS = {'area', 'base', 'br', 'col', 'embed', 'hr', 'img', 'input',
                 'link', 'meta', 'param', 'source', 'track', 'wbr'}

    def __init__(self):
        super().__init__(convert_charrefs=True)
        self.stack = []
        self.samples = []
        self.parts = None
        self.kind = None
        self.line_start = None

    def handle_starttag(self, tag, attrs):
        classes = set(dict(attrs).get('class', '').split())
        if tag == 'pre' and self.parts is None:
            if any('sample-test' in c for _, c in self.stack):
                for _, ancestor_classes in reversed(self.stack):
                    kinds = ancestor_classes & {'input', 'output'}
                    if kinds:
                        self.kind = kinds.pop()
                        self.parts = []
                        break
        elif self.parts is not None:
            if tag == 'br':
                self.parts.append('\n')
            elif tag == 'div':
                # Codeforces also represents each sample line as a div.
                if self.parts and not self.parts[-1].endswith('\n'):
                    self.parts.append('\n')
                self.line_start = len(self.parts)
        if tag not in self.VOID_TAGS:
            self.stack.append((tag, classes))

    def handle_startendtag(self, tag, attrs):
        self.handle_starttag(tag, attrs)
        if tag not in self.VOID_TAGS:
            self.handle_endtag(tag)

    def handle_endtag(self, tag):
        if self.parts is not None:
            if tag == 'div' and self.line_start is not None:
                if len(self.parts) == self.line_start or not self.parts[-1].endswith('\n'):
                    self.parts.append('\n')
                self.line_start = None
            elif tag == 'pre':
                content = ''.join(self.parts).replace('\r\n', '\n').replace('\r', '\n')
                if content and not content.endswith('\n'):
                    content += '\n'
                self.samples.append((self.kind, content))
                self.parts = None
                self.kind = None
        for index in range(len(self.stack) - 1, -1, -1):
            if self.stack[index][0] == tag:
                del self.stack[index:]
                break

    def handle_data(self, data):
        if self.parts is not None:
            self.parts.append(data)


def parse_samples(html):
    parser = SampleParser()
    parser.feed(html)
    parser.close()
    samples = parser.samples
    if not samples or len(samples) % 2:
        raise ValueError('No complete samples found. Save the loaded problem page, not a challenge/login page.')
    if [kind for kind, _ in samples] != ['input', 'output'] * (len(samples) // 2):
        raise ValueError('Unexpected sample layout: input/output pairs do not match.')
    return [(samples[i][1], samples[i + 1][1]) for i in range(0, len(samples), 2)]


def save_samples(samples, directory, index):
    files = {}
    for number, (sample_input, sample_output) in enumerate(samples, 1):
        stem = index if len(samples) == 1 else f'{index}.{number}'
        files[directory / f'{stem}.in'] = sample_input
        files[directory / f'{stem}.expected'] = sample_output
    # Also reject older numbered/unnumbered sets, preventing stale samples.
    if directory.exists():
        pattern = re.compile(rf'{re.escape(index)}(?:\.\d+)?\.(?:in|expected)')
        if any(pattern.fullmatch(path.name) for path in directory.iterdir()):
            raise ValueError(f'Samples for {index} already exist in {directory}; move them before importing again.')
    directory.mkdir(parents=True, exist_ok=True)
    for path, content in files.items():
        with path.open('x', encoding='utf-8', newline='') as output:
            output.write(content)
    return list(files)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('url', help='Codeforces problem URL (also identifies the problem with --html)')
    parser.add_argument('--output-dir', required=True, type=Path, help='Contest directory')
    parser.add_argument('--html', type=Path, help='Read a page saved from Brave instead of downloading')
    args = parser.parse_args()
    try:
        index = problem_index(args.url)
        if args.html:
            html = args.html.read_text(encoding='utf-8')
        else:
            request = Request(args.url, headers={'User-Agent': 'CP-Sample-Importer/1.0'})
            with urlopen(request, timeout=20) as response:
                html = response.read().decode('utf-8')
        samples = parse_samples(html)
        for path in save_samples(samples, args.output_dir, index):
            print(path)
        print(f'Saved {len(samples)} sample pair(s).')
    except (ValueError, OSError, URLError) as error:
        print(f'Error: {error}', file=sys.stderr)
        if not args.html:
            print('If Codeforces blocks downloads, save the loaded page in Brave and retry with --html PATH.', file=sys.stderr)
        return 1
    return 0


if __name__ == '__main__':
    sys.exit(main())
