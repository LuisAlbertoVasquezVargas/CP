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

#define sc1(x) scanf("%d", &(x))
#define sc2(x, y) scanf("%d%d", &(x), &(y))
#define sc3(x, y, z) scanf("%d%d%d", &(x), &(y), &(z))
#define sc4(x, y, z, w) scanf("%d%d%d%d", &(x), &(y), &(z), &(w))

#define GET_SC(_1, _2, _3, _4, NAME, ...) NAME
#define sc(...) GET_SC(__VA_ARGS__, sc4, sc3, sc2, sc1)(__VA_ARGS__)

#define REP(i, n) for(int i = 0; i < (int)(n); i++)

int main() {

}