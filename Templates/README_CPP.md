<!-- Templates/README_CPP.md -->

# C++ Competitive Programming Template

```cpp
#include <iostream>

using namespace std;

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
    sc(n);

    int a, b;
    sc(a, b);

    return 0;
}
```

---

## Notes

This template starts from a minimal C++98/C++03-compatible style.

The target local compiler mode is:

```bash
g++ -std=gnu++98 -DLOCAL main.cpp
```

The template uses C++ input/output:

```cpp
cin >> x;
cout << x << '\n';
```

The `sc(...)` macro supports up to 4 input variables:

```cpp
sc(n);
sc(a, b);
sc(x, y, z);
sc(a, b, c, d);
```

It expands to:

```cpp
cin >> n;
cin >> a >> b;
cin >> x >> y >> z;
cin >> a >> b >> c >> d;
```

Once `ios::sync_with_stdio(false)` is used, avoid mixing C++ I/O with C I/O.

Use:

```cpp
cin
cout
```

Avoid mixing with:

```cpp
scanf
printf
```

The name `sc` is kept to match the C template style.

The line:

```cpp
using namespace std;
```

is used because most standard C++ tools live inside the `std` namespace, such as:

```cpp
cin
cout
vector
string
sort
```

In competitive programming, this keeps single-file solutions shorter.

The variadic macro trick used by `sc(...)` is supported by `g++ -std=gnu++98`, even though variadic macros are not part of strict C++98.

