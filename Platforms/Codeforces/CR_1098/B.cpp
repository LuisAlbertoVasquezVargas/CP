#include <cstdio>

#define sc1(x) scanf("%d", &(x))
#define sc2(x, y) scanf("%d%d", &(x), &(y))
#define sc3(x, y, z) scanf("%d%d%d", &(x), &(y), &(z))
#define sc4(x, y, z, w) scanf("%d%d%d%d", &(x), &(y), &(z), &(w))

#define GET_SC(_1, _2, _3, _4, NAME, ...) NAME
#define sc(...) GET_SC(__VA_ARGS__, sc4, sc3, sc2, sc1)(__VA_ARGS__)

#define REP(i, n) for(int i = 0; i < (int)(n); i++)

int abs(int x) {
    return x < 0 ? -x : x;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int solve(int n, int x1, int x2, int k) {
    if (n <= 3) {
        return 1;
    }
    int dif = abs(x1 - x2);
    return k + min(dif, n - dif);
}

int main() {
    int tc;
    sc(tc);
    REP(t, tc) {
        int n, x1, x2, k;
        sc(n, x1, x2, k);
        printf("%d\n", solve(n, x1, x2, k));
    }
}