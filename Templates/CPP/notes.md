# C++ template explained

These notes explain [README.md](README.md), following the same order as its code. These explanations describe the purpose and tradeoffs of the current implementation.

## Headers and namespace

The template includes individual headers so its dependencies are visible:

| Header | What it provides here |
| --- | --- |
| `<algorithm>` | Algorithms such as `sort`, usable with `ALL`. |
| `<cstring>` | `memset`, used by `CLR`. |
| `<iostream>` | `cin`, `cout`, `cerr`, and stream configuration. |
| `<sstream>` | `stringstream`, used by the conversion functions. |
| `<string>` | `string`, also used by `VS`. |
| `<utility>` | `pair` and `make_pair`. |
| `<vector>` | Dynamic arrays and the vector aliases. |

Some are conveniences for the solution rather than requirements of the empty `main`. `using namespace std;` removes repeated `std::` prefixes in a short, single-file submission. The tradeoff is that names from the standard library can collide with names introduced by the solution.

## Type aliases

`typedef` gives common types short names without creating new types:

| Alias | Meaning and purpose |
| --- | --- |
| `LL` | `long long`, for larger integer values and totals. |
| `VI` | `vector<int>`, a dynamic sequence of integers. |
| `VVI` | `vector<VI>`, for rows or adjacency lists. |
| `VS` | `vector<string>`, a sequence of strings. |
| `PII` | `pair<int, int>`, for two associated integers. |
| `VPII` | `vector<PII>`, a sequence of such pairs. |

These aliases prioritize typing speed. They preserve the underlying types' limits: `VI` still stores `int`, and assigning an `int` product to `LL` does not widen the multiplication. An expression such as `1LL * a * b` widens it before multiplication.

## Newlines and short names

`EOL` expands to the character `'\n'`. It ends an output line without the forced flush performed by `endl`, avoiding unnecessary flushing in ordinary batch output. Interactive output may need an explicit flush.

`pb`, `mp`, `fi`, and `se` abbreviate `push_back`, `make_pair`, `first`, and `second`. They keep container and pair expressions short. Because these are preprocessor substitutions, their names also replace matching tokens elsewhere; they are not scoped member aliases.

## Input macros

`sc1` through `sc4` chain one to four extractions from `cin`. Streams determine how to read each argument from its type, so the same macros can read `int`, `LL`, or a whitespace-delimited `string`.

`GET_SC` selects the appropriate macro by argument count. For `sc(a, b)`, the appended names make `NAME` resolve to `sc2`, and the result is `cin >> a >> b`. This provides one short interface for common input groups without repeating the stream expression.

The interface supports one to four arguments, not arbitrary argument counts. It does not handle whole lines or validate successful input; those assumptions fit well-formed contest input.

## Local debugging

`#ifdef LOCAL` includes the debugging implementation only when the compiler defines `LOCAL`. `cerr` keeps diagnostics separate from the answer written to `cout`.

The `dbgVal` overloads separate formatting from the debug macros:

- The generic overload prints values supported by `operator<<`.
- The pair overload prints two members in parentheses.
- The vector overload prints elements between brackets, with spaces between them.

Passing values as `const` references avoids copying containers and prevents these functions from modifying them. Pair and vector formatting calls `dbgVal` for their contents, allowing supported combinations to reuse the printers. This is not a printer for every container or every nesting arrangement; overload visibility can matter for nested types.

`db1` through `db4` print labels and values. The preprocessor's `#x` turns the expression into its textual label, so `debug(n)` identifies what was printed. `GET_DB` chooses by argument count in the same way as `GET_SC`.

Without `LOCAL`, `debug(...)` expands to nothing. Its arguments therefore must not perform required work: `debug(i++)` would increment only in the local build. The enabled macros expand into multiple statements, so an enclosing `if` or loop needs braces around a debug call.

## Container, memory, and loop helpers

`SZ(x)` casts `.size()` to `int`, making it convenient to use with the template's signed loop indices. It assumes the size fits in `int`.

`CLR(a, v)` uses `memset` to fill `sizeof(a)` bytes. It is concise for zeroing a full integer array, but it fills bytes rather than assigning element values: `CLR(a, 1)` does not produce an array of integer ones. It also requires the actual array at the call site; for a pointer, `sizeof(a)` measures the pointer. It is unsuitable for clearing objects such as vectors or strings.

`REP(i, n)` declares an `int` index and visits `[0, n)`, matching zero-based indexing. `FOR(i, a, b)` visits the inclusive interval `[a, b]`, making inclusive numeric ranges convenient. Their bounds must fit the index type, and their conditions are evaluated on each iteration.

`EACH(it, v)` creates an iterator with GNU `__typeof__`, avoiding a long explicit iterator type in the older C++ dialect. It visits the container from `begin()` to `end()`. Modifications that invalidate the iterator make this traversal unsafe.

`ALL(x)` expands to `begin()` and `end()` as two arguments, allowing expressions such as `sort(ALL(v))`. The container expression is used twice, so it should not have side effects.

## Minimum and maximum

`MIN` and `MAX` use a conditional expression, with parentheses to protect operator precedence when substituted into larger expressions. Macros avoid specifying parameter types, but may evaluate an argument twice. Expressions such as `MIN(i++, j)` are therefore unsafe. The existing `<algorithm>` header also provides `std::min` and `std::max` as function alternatives.

## String conversions

`toStr` and `toStrLL` insert a number into a `stringstream` and return its string. `toInt` and `toLL` extract a number from a string. Separate names distinguish the integer widths.

Using streams fits the older C++ style of this template; newer conveniences such as `std::to_string` are unavailable in C++98. The input conversion functions assume valid, in-range numbers and do not check extraction failure or reject trailing text, so they are convenience functions rather than validators.

## Entry point and I/O configuration

`ios::sync_with_stdio(false)` disables synchronization between C++ streams and C standard I/O, which can reduce overhead. The template consequently uses streams consistently; mixing them with `scanf` or `printf` can produce surprising ordering.

`cin.tie(NULL)` removes the automatic flush of `cout` before reads from `cin`. This also reduces unnecessary flushing for batch input. `NULL` fits the older language mode used here.

`tc` and `REP(t, tc)` assume a leading test count and provide a place for each case's solution. That is an input-format assumption, not a universal contest format. Variables declared within that block are recreated for each case. `return 0` signals normal program completion.

## Compilation command

`g++` selects the C++ compiler. `-std=gnu++98` selects the GNU C++98 dialect, matching the template's older syntax and use of GNU extensions such as `__typeof__`. Variadic macros and `long long` also rely on extensions in this mode; the template is not strictly ISO C++98.

`-DLOCAL` defines the switch used by the debug block. Omitting it removes those diagnostics. `main.cpp` names the source file, and with no `-o` option the compiler normally writes `a.out` on this Linux setup.
