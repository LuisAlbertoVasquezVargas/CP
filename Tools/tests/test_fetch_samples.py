import importlib.util
from pathlib import Path
import tempfile
import unittest

spec = importlib.util.spec_from_file_location('fetch_samples', Path(__file__).parents[1] / 'fetch_samples.py')
module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)


class SampleTests(unittest.TestCase):
    def test_legacy_breaks_entities_and_spaces(self):
        html = '<pre>ignore me</pre><div class="sample-test"><div class="input"><pre>2<br/>  a &lt; b<br>&amp;</pre></div><div class="output"><pre>yes\n\nno\n</pre></div></div>'
        self.assertEqual(module.parse_samples(html), [('2\n  a < b\n&\n', 'yes\n\nno\n')])

    def test_line_divs_include_blank_lines(self):
        html = '<div class="sample-test"><div class="input"><pre><div class="test-example-line">2</div><div></div><div> x </div></pre></div><div class="output"><pre>ok</pre></div></div>'
        self.assertEqual(module.parse_samples(html), [('2\n\n x \n', 'ok\n')])

    def test_challenge_and_incomplete_samples_rejected(self):
        for html in ['<h1>Verify you are human</h1>', '<div class="sample-test"><div class="input"><pre>1</pre></div></div>']:
            with self.assertRaises(ValueError):
                module.parse_samples(html)

    def test_multiple_samples_and_overwrite_protection(self):
        with tempfile.TemporaryDirectory() as tmp:
            directory = Path(tmp)
            module.save_samples([('1\n', '2\n'), ('3\n', '4\n')], directory, 'B')
            self.assertEqual((directory / 'B.2.expected').read_text(), '4\n')
            with self.assertRaises(ValueError):
                module.save_samples([('changed', 'changed')], directory, 'B')
            self.assertFalse((directory / 'B.in').exists())
            self.assertEqual((directory / 'B.1.in').read_text(), '1\n')

    def test_problem_urls(self):
        self.assertEqual(module.problem_index('https://codeforces.com/contest/2276/problem/B'), 'B')
        self.assertEqual(module.problem_index('https://codeforces.com/problemset/problem/2276/A1?locale=en'), 'A1')
        with self.assertRaises(ValueError):
            module.problem_index('https://example.com/contest/2276/problem/B')


if __name__ == '__main__':
    unittest.main()
