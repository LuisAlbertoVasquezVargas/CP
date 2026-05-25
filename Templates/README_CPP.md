<!-- Templates/README_CPP.md -->

# C++ Competitive Programming Template

```cpp
#include <iostream>
#include <string>

using namespace std;

typedef long long LL;

#define sc1(x) cin >> x
#define sc2(x, y) cin >> x >> y
#define sc3(x, y, z) cin >> x >> y >> z
#define sc4(x, y, z, w) cin >> x >> y >> z >> w

#define GET_SC(_1, _2, _3, _4, NAME, ...) NAME
#define sc(...) GET_SC(__VA_ARGS__, sc4, sc3, sc2, sc1)(__VA_ARGS__)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    LL x;
    string s;

    sc(n, x, s);

    return 0;
}
```

## Compilation

```bash
g++ -std=gnu++98 -DLOCAL main.cpp
```

