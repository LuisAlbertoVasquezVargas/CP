<!-- Templates/README_CPP.md -->

# C++ Competitive Programming Template

```cpp
#include <iostream>  // cin, cout, cerr, ios
#include <sstream>   // stringstream
#include <string>    // string
#include <vector>    // vector
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define sc1(x) cin >> x
#define sc2(x, y) cin >> x >> y
#define sc3(x, y, z) cin >> x >> y >> z
#define sc4(x, y, z, w) cin >> x >> y >> z >> w
#define GET_SC(_1, _2, _3, _4, NAME, ...) NAME
#define sc(...) GET_SC(__VA_ARGS__, sc4, sc3, sc2, sc1)(__VA_ARGS__)

#define SZ(x) ((int)(x).size())
#define REP(i, n) for(int i = 0; i < (int)(n); i++)

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#ifdef LOCAL
    #define db1(x) cerr << "[D] " << #x << "=" << x << '\n'
    #define db2(x, y) cerr << "[D] " << #x << "=" << x << " | " << #y << "=" << y << '\n'
    #define db3(x, y, z) cerr << "[D] " << #x << "=" << x << " | " << #y << "=" << y << " | " << #z << "=" << z << '\n'
    #define db4(x, y, z, w) cerr << "[D] " << #x << "=" << x << " | " << #y << "=" << y << " | " << #z << "=" << z << " | " << #w << "=" << w << '\n'
    #define GET_DB(_1, _2, _3, _4, NAME, ...) NAME
    #define debug(...) GET_DB(__VA_ARGS__, db4, db3, db2, db1)(__VA_ARGS__)
#else
    #define debug(...)
#endif

string toStr(int x) { stringstream ss; ss << x; return ss.str(); }
string toStrLL(LL x) { stringstream ss; ss << x; return ss.str(); }
int toInt(string s) { int x; stringstream ss(s); ss >> x; return x; }
LL toLL(string s) { LL x; stringstream ss(s); ss >> x; return x; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    sc(tc);

    REP(t, tc) {

    }

    return 0;
}
```

## Compilation

```bash
g++ -std=gnu++98 -DLOCAL main.cpp
```

