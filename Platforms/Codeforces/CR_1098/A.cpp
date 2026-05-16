#include <cstdio>

#define sc1(x) scanf("%d", &(x))
#define sc2(x, y) scanf("%d%d", &(x), &(y))
#define sc3(x, y, z) scanf("%d%d%d", &(x), &(y), &(z))

#define GET_SC(_1, _2, _3, NAME, ...) NAME
#define sc(...) GET_SC(__VA_ARGS__, sc3, sc2, sc1)(__VA_ARGS__)

#define REP(i, n) for(int i = 0; i < (int)(n); i++)

int min(int a, int b) {
    return a < b ? a : b;
}

int freq[4];
int main() {
    int tc;
    sc(tc);
    REP(i, tc) {
        int n;
        sc(n);
        REP (i, 4) {
            freq[i] = 0;
        }
        REP(i, n) {
            int val;
            sc(val);
            freq[val] ++;
        }
        int ans = 0;
        ans += freq[0];
        int cur = min(freq[1], freq[2]);
        ans += cur;
        freq[1] -= cur;
        freq[2] -= cur;
        ans += (freq[1] / 3) + (freq[2] / 3);
        printf("%d\n", ans);
    }
}