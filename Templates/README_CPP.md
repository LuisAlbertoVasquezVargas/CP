<!-- Templates/README_CPP.md -->

# C++ Competitive Programming Template

```cpp
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int MAX_N = 200005;
const int INF = 1000000000;

#define sc1(x) scanf("%d", &(x))
#define sc2(x, y) scanf("%d%d", &(x), &(y))
#define sc3(x, y, z) scanf("%d%d%d", &(x), &(y), &(z))
#define sc4(x, y, z, w) scanf("%d%d%d%d", &(x), &(y), &(z), &(w))

#define GET_SC(_1, _2, _3, _4, NAME, ...) NAME
#define sc(...) GET_SC(__VA_ARGS__, sc4, sc3, sc2, sc1)(__VA_ARGS__)

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)

#ifdef LOCAL
    #define debug(...) fprintf(stderr, __VA_ARGS__)
#else
    #define debug(...)
#endif

int main() {
    int n;
    sc(n);

    REP(i, n) {
        /* solve */
    }

    return 0;
}
```

---

## Notes

This template follows an old portable C++ style, close to C++98/C++03, while still using common `g++` extensions.

Compile locally with:

```bash
g++ -std=gnu++98 -DLOCAL main.cpp
```

Submit without `-DLOCAL`.

The template intentionally uses:

- `scanf` and `printf`
- `typedef` instead of `using`
- explicit types instead of `auto`
- classic `for` loops instead of range-based loops
- references for pass-by-reference
- STL containers only when useful

The variadic macros used by `sc(...)` and `debug(...)` are not strict C++98, but they work with `g++ -std=gnu++98`.

---

## References

C++ supports pass-by-reference:

```cpp
void updateBest(int value, int &best) {
    if(value > best) {
        best = value;
    }
}
```

Usage:

```cpp
int best = 0;
updateBest(10, best);
```

---

## Vector Example

```cpp
vector<int> v;

v.push_back(10);
v.push_back(20);
v.push_back(30);

REP(i, v.size()) {
    printf("%d\n", v[i]);
}
```

---

## Pair Example

```cpp
vector<PII> v;

v.push_back(PII(2, 5));
v.push_back(PII(1, 9));

sort(v.begin(), v.end());
```

Pairs are sorted by `.first`, then by `.second`.

---

## String Example

```cpp
string s;
char buffer[1005];

scanf("%s", buffer);
s = buffer;

printf("%s\n", s.c_str());
```

---

## Future Direction

For now, the template stays documented in this README.

A ready-to-copy `template.cpp` file may be added later when the pattern becomes stable.
````

