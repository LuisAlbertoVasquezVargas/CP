# C template explained

These notes explain [README.md](README.md), following the same order as its code. These explanations describe the purpose and tradeoffs of the current implementation.

## Headers and language choice

The template uses C's formatted I/O and simple macros to keep a submission compact:

| Header | What it provides here |
| --- | --- |
| `<stdio.h>` | `scanf`, `printf`, `fprintf`, `sprintf`, and `sscanf` for input, output, diagnostics, and conversions. |
| `<string.h>` | Utilities such as `memset` for array initialization in a solution; unused by the empty scaffold. |
| `<stdbool.h>` | `bool`, `true`, and `false` for solution logic; unused by the empty scaffold. |

The last two headers are conveniences already available when writing a solution, rather than dependencies of the current `main`.

## Integer alias

`typedef long long LL;` gives the wider integer type a short name for values and totals that exceed `int`'s range. It does not automatically widen intermediate expressions: `1LL * a * b` widens multiplication, whereas assigning `a * b` to an `LL` can overflow before assignment.

## Input macros

`sc1` through `sc4` call `scanf` with one to four `%d` conversions. Each argument is wrapped in `&(...)` because `scanf` needs the address at which to store the result. This allows `sc(n)` instead of repeating the format string and address operator.

`GET_SC` dispatches by argument count. For `sc(a, b)`, the appended macro names place `sc2` in the `NAME` position, yielding `scanf("%d%d", &(a), &(b))`. Numeric conversions skip leading whitespace, so adjacent `%d` conversions accept spaces or newlines between numbers.

This interface accepts one to four `int` destinations only. An `LL` requires `%lld`, for example `scanf("%lld", &value)`; passing its address to `%d` is a type mismatch. Calls in the scaffold assume valid input and do not inspect the number of successful conversions returned by `scanf`.

## Comparisons and loops

`MIN` and `MAX` use conditional expressions to select a value without a typed helper function. Parentheses preserve grouping after macro substitution. An argument may be evaluated twice, so side effects such as `MIN(i++, j)` are unsafe.

`REP(i, n)` declares an `int` index and iterates over `[0, n)`, matching zero-based arrays. Its cast of `n` keeps the comparison in the index's type but assumes the bound fits in `int`.

`FOR(i, a, b)` includes both endpoints, expressing an inclusive numeric range. Unlike `REP(i, n)`, `FOR(i, 0, n)` executes `n + 1` iterations for nonnegative `n`. Both macros reevaluate their loop condition each iteration; changing a bound changes the traversal.

## Local debugging

`#ifdef LOCAL` makes diagnostics a compile-time choice. `db1` through `db4` print one to four labeled integer values with `fprintf(stderr, ...)`, keeping them separate from answers on standard output.

The `#x` operator turns an argument's source text into a label. `GET_DB` chooses the debug macro by argument count, just as `GET_SC` does for input. This makes `debug(a, b)` a compact way to inspect both named values.

All value formats are `%d`, so these helpers support `int` values, not arbitrary types. An `LL` diagnostic needs a separate `%lld` call. Without `LOCAL`, `debug(...)` expands to nothing, including its arguments; required work must never be placed inside a debug argument.

## String conversions

`toStr` and `toStrLL` write decimal numbers into caller-owned buffers with `sprintf`. C does not return an owned string object here, so the caller supplies storage. The advertised sizes of 16 and 32 bytes leave room for digits, a sign, and the terminating null byte on the usual contest integer widths.

Array syntax in a function parameter does not enforce those sizes: `char buff[16]` is adjusted to a pointer parameter. `sprintf` does not check capacity, so the caller must provide enough space.

`toInt` and `toLL` use `sscanf` to parse numbers with the matching `%d` and `%lld` formats. They assume valid, in-range input, do not check conversion success, and accept a numeric prefix without requiring the whole string to be consumed. They are convenience conversions rather than validation functions.

## Compile-time constants

The unnamed `enum` introduces `MAX_N` and `INF` as integer constant expressions without creating variables. This permits uses such as fixed-size array bounds, where an ordinary C `const int` is not an integer constant expression.

`MAX_N = 200000` supplies a convenient initial capacity. It is a placeholder that must fit the actual problem and indexing convention; an array of this size has indices from zero through 199999.

`INF = 2111222333` supplies a large finite sentinel that fits a 32-bit signed `int`. Its exact digits are not essential to the helper's role. It is not mathematical infinity: valid values may exceed it, and adding to it can overflow. Its suitability depends on the operations and bounds in the solution.

## Entry point

`main` reads `tc` and repeats the empty solution block with `REP(t, tc)`. This makes multiple test cases the default input shape. A problem without a leading count needs a different entry structure.

Case-specific variables declared inside the block are recreated for each iteration. `return 0` signals normal completion to the environment.

## Compilation and input redirection

`gcc` selects the C compiler, and `-std=gnu11` selects the GNU C11 dialect. This supports the template's variadic macros, `long long`, boolean header, and declarations inside `for` loops.

`-DLOCAL` defines the symbol enabling diagnostics. Omitting it removes the debug macro calls. `B.c` names the source file; with no explicit output name, the compiler normally creates `a.out` on this Linux setup.

`./a.out < B.in` runs that executable with the contents of `B.in` as standard input. The shell performs the redirection, so the source needs no file-opening code and continues to read through `scanf`. Standard output and standard error still go to the terminal.
