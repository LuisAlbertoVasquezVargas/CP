<!-- Templates/README.md -->

# Competitive Programming

This repository contains solutions to various competitive programming problems and contests, primarily focused on **Codeforces**.

---

## 🏆 Platforms / Contests

- **Codeforces**

---

## 🛠️ Template

This template intentionally follows a **C approach**:

- Uses `<stdio.h>`
- Uses `scanf` / `printf` for input and output
- Uses macros for short contest-style syntax
- Keeps the code compact and easy to type during contests

```c
#include <stdio.h>  // scanf, printf, fprintf, sprintf, sscanf
#include <string.h> // memset

typedef long long LL;

#define sc1(x) scanf("%d", &(x))
#define sc2(x, y) scanf("%d%d", &(x), &(y))
#define sc3(x, y, z) scanf("%d%d%d", &(x), &(y), &(z))
#define sc4(x, y, z, w) scanf("%d%d%d%d", &(x), &(y), &(z), &(w))
#define GET_SC(_1, _2, _3, _4, NAME, ...) NAME
#define sc(...) GET_SC(__VA_ARGS__, sc4, sc3, sc2, sc1)(__VA_ARGS__)

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

void toStr(int x, char buff[16]) { sprintf(buff, "%d", x); }
void toStrLL(LL x, char buff[32]) { sprintf(buff, "%lld", x); }
int toInt(char s[]) { int x; sscanf(s, "%d", &x); return x; }
LL toLL(char s[]) { LL x; sscanf(s, "%lld", &x); return x; }

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
gcc -std=c99 -DLOCAL main.c
```
