# Sample importer

`fetch_samples.py` extracts Codeforces sample inputs and expected outputs. It uses Python 3's standard library; no browser extension or extra packages are required. It downloads only the problem page, not editorials or solutions.

From the repository root:

```bash
python3 Tools/fetch_samples.py https://codeforces.com/contest/2276/problem/B \
  --output-dir Platforms/Codeforces/ECR_195
```

One sample pair produces `B.in` and `B.expected`. Multiple pairs produce `B.1.in`, `B.1.expected`, `B.2.in`, and so on. Inputs are kept separate, since concatenating samples can change the input format. Existing sample files are never overwritten. No solution file is generated.

## When Codeforces blocks downloads

In Brave, open the problem and wait until the statement is visible. Press `Ctrl+S`, choose **Webpage, HTML Only**, and save it, for example as `/tmp/problem-B.html`. Then run:

```bash
python3 Tools/fetch_samples.py https://codeforces.com/contest/2276/problem/B \
  --html /tmp/problem-B.html --output-dir Platforms/Codeforces/ECR_195
```

The URL supplies the output filename; when using `--html`, make sure the saved page is the same problem. This mode makes no network requests. The parser reads sample `<pre>` blocks, including Codeforces' line `<div>` elements, HTML entities, and `<br>` line breaks. It rejects pages without complete sample pairs. It does not fetch hidden judge tests.

## Check the importer

```bash
python3 -B -m unittest discover -s Tools/tests -v
```

Compare a solution's output after compiling it:

```bash
./a.out < B.in > /tmp/cp-actual
diff -u B.expected /tmp/cp-actual
```
