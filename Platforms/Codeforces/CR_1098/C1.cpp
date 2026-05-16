#include <cstdio>

#define sc1(x) scanf("%d", &(x))
#define sc2(x, y) scanf("%d%d", &(x), &(y))
#define sc3(x, y, z) scanf("%d%d%d", &(x), &(y), &(z))
#define sc4(x, y, z, w) scanf("%d%d%d%d", &(x), &(y), &(z), &(w))

#define GET_SC(_1, _2, _3, _4, NAME, ...) NAME
#define sc(...) GET_SC(__VA_ARGS__, sc4, sc3, sc2, sc1)(__VA_ARGS__)

#define REP(i, n) for(int i = 0; i < (int)(n); i++)

inline long long min(long long a, long long b) {
    return a < b ? a : b;
}

inline int max(int a , int b) {
    return a < b ? b : a;
}
long long abs(long long a) {
    return a < 0 ? -a : a;
}

int get_sz(long long num) {
    if (num == 0) return 1;
    int ans = 0;
    while(num > 0) {
        ans ++;
        num /= 10LL;
    }
    return ans;
}

int main() {
    int tc;
    sc(tc);
    REP(t, tc) {
        long long target;
        scanf("%lld", &target);
        int n, d1, d2;
        sc(n, d1, d2);
        int len = get_sz(target);
        long long ans = 1LL << 62;
        for(int sz = max(0, len - 1); sz <= len + 1; sz ++) {
            REP(mask, (1 << sz)) {
                long long cur = 0;
                REP(i, sz) {
                    if((mask & (1 << i)) > 0) {
                        cur = cur * 10LL + d1;
                    } else {
                        cur = cur * 10LL + d2;
                    }
                }
                ans = min(ans, abs(target - cur));
            }
        }
        printf("%lld\n", ans);
    }
}