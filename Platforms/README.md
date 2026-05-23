<!-- Platforms/README.md -->

# Competitive Programming

This repository contains solutions to various competitive programming problems and contests, primarily focused on **Codeforces**.

---

## 🏆 Platforms / Contests

- **Codeforces**

---

## 🛠️ Template

This template intentionally follows a **C-style approach** inside C++:

- Uses `<cstdio>` instead of `<iostream>`
- Uses `scanf` for input
- Uses macros for short contest-style syntax
- Keeps the code compact and easy to type during contests

```cpp
#include <cstdio>
#include <vector>

typedef long long LL;
typedef std::vector<int> VI;

#define sc1(x) scanf("%d", &(x))
#define sc2(x, y) scanf("%d%d", &(x), &(y))
#define sc3(x, y, z) scanf("%d%d%d", &(x), &(y), &(z))
#define sc4(x, y, z, w) scanf("%d%d%d%d", &(x), &(y), &(z), &(w))
#define GET_SC(_1, _2, _3, _4, NAME, ...) NAME
#define sc(...) GET_SC(__VA_ARGS__, sc4, sc3, sc2, sc1)(__VA_ARGS__)

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define PB push_back
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define REP(i, n) for(int i = 0; i < (int)(n); i++)

#ifdef LOCAL
    #define db1(x) fprintf(stderr, "[D] %s=%d\n", #x, x)
    #define db2(x, y) fprintf(stderr, "[D] %s=%d | %s=%d\n", #x, x, #y, y)
    #define db3(x, y, z) fprintf(stderr, "[D] %s=%d | %s=%d | %s=%d\n", #x, x, #y, y, #z, z)
    #define db4(x, y, z, w) fprintf(stderr, "[D] %s=%d | %s=%d | %s=%d | %s=%d\n", #x, x, #y, y, #z, z, #w, w)
    #define GET_DB(_1, _2, _3, _4, NAME, ...) NAME
    #define debug(...) GET_DB(__VA_ARGS__, db4, db3, db2, db1)(__VA_ARGS__)
#else
    #define debug(...)
#endif

int main() {
    int tc;
    sc(tc);

    REP(t, tc) {

    }

    return 0;
}
````

---

## ⚙️ Compilation

```bash
g++ -std=c++98 -DLOCAL main.cpp
```

---

## 📌 Coding Standards

### Spacing

Use a space after real C++ control keywords:

```cpp
if (ok) {
}

for (int i = 0; i < n; i++) {
}

while (x > 0) {
}
```

Do not use a space after template helpers or macros:

```cpp
REP(i, n) {
}

sc(n);
debug(i, ans);
SZ(v);
ALL(v);
```

Preferred style:

```cpp
if (ok) {
    REP(i, n) {
        sc(x);
        debug(i, x);
    }
}
```

---

### Naming

Use short lowercase names for classic competitive-programming variables:

```cpp
int n, m, k, q;
int i, j;
int x, y;
int l, r;
int u, v;
```

Use `camelCase` for meaningful multi-word variables:

```cpp
int currentSum;
int bestAnswer;
int maxValue;
int minCost;
int leftBound;
int rightBound;
```

Use uppercase for constants, macros, and type aliases:

```cpp
const int INF = 1000000000;
const int MOD = 1000000007;
const int MAXN = 200005;

LL totalSum;
VI values;
```

Avoid `snake_case` unless copying names from a problem statement or external source.

---

### Type Aliases

Use `typedef` for type aliases instead of macros:

```cpp
typedef long long LL;
typedef std::vector<int> VI;
```

Good:

```cpp
LL totalSum = 0;
VI values;
```

Avoid:

```cpp
#define LL long long
#define VI std::vector<int>
```

---

### Macro Usage

Use uppercase for compact macro utilities:

```cpp
SZ(values);
ALL(values);
MIN(a, b);
MAX(a, b);
REP(i, n) {
}
```

Do not pass expressions with side effects to macros.

Good:

```cpp
bestAnswer = MAX(bestAnswer, currentSum);
minCost = MIN(minCost, cost);
maxValue = MAX(maxValue, values[i]);
```

Bad:

```cpp
bestAnswer = MAX(bestAnswer++, currentSum);
minCost = MIN(minCost, cost++);
```

---

### Example Usage

```cpp
#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long LL;
typedef std::vector<int> VI;

#define sc1(x) scanf("%d", &(x))
#define sc2(x, y) scanf("%d%d", &(x), &(y))
#define sc3(x, y, z) scanf("%d%d%d", &(x), &(y), &(z))
#define sc4(x, y, z, w) scanf("%d%d%d%d", &(x), &(y), &(z), &(w))
#define GET_SC(_1, _2, _3, _4, NAME, ...) NAME
#define sc(...) GET_SC(__VA_ARGS__, sc4, sc3, sc2, sc1)(__VA_ARGS__)

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define PB push_back
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define REP(i, n) for(int i = 0; i < (int)(n); i++)

#ifdef LOCAL
    #define db1(x) fprintf(stderr, "[D] %s=%d\n", #x, x)
    #define db2(x, y) fprintf(stderr, "[D] %s=%d | %s=%d\n", #x, x, #y, y)
    #define db3(x, y, z) fprintf(stderr, "[D] %s=%d | %s=%d | %s=%d\n", #x, x, #y, y, #z, z)
    #define db4(x, y, z, w) fprintf(stderr, "[D] %s=%d | %s=%d | %s=%d | %s=%d\n", #x, x, #y, y, #z, z, #w, w)
    #define GET_DB(_1, _2, _3, _4, NAME, ...) NAME
    #define debug(...) GET_DB(__VA_ARGS__, db4, db3, db2, db1)(__VA_ARGS__)
#else
    #define debug(...)
#endif

int main() {
    int n;
    sc(n);

    VI values;
    LL totalSum = 0;
    int currentSum = 0;
    int bestAnswer = 0;
    int minValue = 1000000000;

    REP(i, n) {
        int x;
        sc(x);

        values.PB(x);
        currentSum += x;
        totalSum += x;

        bestAnswer = MAX(bestAnswer, currentSum);
        minValue = MIN(minValue, x);

        debug(i, x, currentSum, bestAnswer);
    }

    std::sort(ALL(values));

    REP(i, SZ(values)) {
        printf("%d%c", values[i], i + 1 == SZ(values) ? '\n' : ' ');
    }

    printf("%lld\n", totalSum);

    return 0;
}
```
