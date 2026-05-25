<!-- Templates/README_CPP.md -->

# C++ Competitive Programming Template

```cpp
#include <algorithm> // sort
#include <cstring>   // memset
#include <iostream>  // cin, cout, cerr, ios
#include <sstream>   // stringstream
#include <string>    // string
#include <utility>   // pair, make_pair
#include <vector>    // vector
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

#define EOL '\n'

#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define sc1(x) cin >> x
#define sc2(x, y) cin >> x >> y
#define sc3(x, y, z) cin >> x >> y >> z
#define sc4(x, y, z, w) cin >> x >> y >> z >> w
#define GET_SC(_1, _2, _3, _4, NAME, ...) NAME
#define sc(...) GET_SC(__VA_ARGS__, sc4, sc3, sc2, sc1)(__VA_ARGS__)

#ifdef LOCAL
    template <class T> void dbgVal(const T &x) { cerr << x; }
    template <class A, class B> void dbgVal(const pair<A, B> &p) { cerr << "("; dbgVal(p.fi); cerr << ", "; dbgVal(p.se); cerr << ")"; }
    template <class T> void dbgVal(const vector<T> &v) { cerr << "["; for(int i = 0; i < (int)v.size(); i++) { if(i) cerr << " "; dbgVal(v[i]); } cerr << "]"; }
    #define db1(x) cerr << "[D] " << #x << "="; dbgVal(x); cerr << '\n'
    #define db2(x, y) cerr << "[D] " << #x << "="; dbgVal(x); cerr << " | " << #y << "="; dbgVal(y); cerr << '\n'
    #define db3(x, y, z) cerr << "[D] " << #x << "="; dbgVal(x); cerr << " | " << #y << "="; dbgVal(y); cerr << " | " << #z << "="; dbgVal(z); cerr << '\n'
    #define db4(x, y, z, w) cerr << "[D] " << #x << "="; dbgVal(x); cerr << " | " << #y << "="; dbgVal(y); cerr << " | " << #z << "="; dbgVal(z); cerr << " | " << #w << "="; dbgVal(w); cerr << '\n'
    #define GET_DB(_1, _2, _3, _4, NAME, ...) NAME
    #define debug(...) GET_DB(__VA_ARGS__, db4, db3, db2, db1)(__VA_ARGS__)
#else
    #define debug(...)
#endif

#define SZ(x) ((int)(x).size())
#define CLR(a, v) memset(a, v, sizeof(a))
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define EACH(it, v) for(__typeof__((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define ALL(x) (x).begin(), (x).end()

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

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

