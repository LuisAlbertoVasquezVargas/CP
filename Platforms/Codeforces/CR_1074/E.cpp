#include <cstdio>
#include <algorithm>

#define sc1(x) scanf("%d", &(x))
#define sc2(x, y) scanf("%d%d", &(x), &(y))
#define sc3(x, y, z) scanf("%d%d%d", &(x), &(y), &(z))
#define sc4(x, y, z, w) scanf("%d%d%d%d", &(x), &(y), &(z), &(w))

#define GET_SC(_1, _2, _3, _4, NAME, ...) NAME
#define sc(...) GET_SC(__VA_ARGS__, sc4, sc3, sc2, sc1)(__VA_ARGS__)

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

const int MAX_N = (1 << 18);
const int INF = (1 << 30);
int n, m, k;
int a[MAX_N], b[MAX_N];
char instr[MAX_N];
int AC[MAX_N];

int calcUpDistance(int index) {
    int robot_coord = a[index];
    int pos = std::lower_bound(b, b + m, robot_coord) - b;
    if (pos >= m) {
        return -1;
    }
    return b[pos] - robot_coord;
}

int calcDownDistance(int index) {
    int robot_coord = a[index];
    int pos = std::upper_bound(b, b + m, robot_coord) - b;
    pos --;
    if (pos < 0) {
        return -1;
    }
    return robot_coord - b[pos];
}

// Earliest time (Top and Down)
int eatUp[MAX_N], eatDown[MAX_N];

int calcUpTime(int index) {
    int dist = calcUpDistance(index);
    if (dist < 0) {
        return INF;
    }
    if (dist > k) {
        return INF;
    }
    if (eatUp[dist] != -1) {
        return eatUp[dist];
    }
    return INF;
}

int calcDownTime(int index) {
    int dist = calcDownDistance(index);
    if (dist < 0) {
        return INF;
    }
    if (dist > k) {
        return INF;
    }
    if (eatDown[dist] != -1) {
        return eatDown[dist];
    }
    return INF;
}

int main() {
    int tc;
    sc(tc);
    REP(t, tc) {
        sc(n, m, k);
        REP(i, n) {
            sc(a[i]);
        }
        REP(i, m) {
            sc(b[i]);
        }
        scanf("%s", instr);
        
        std::sort(a, a + n);
        std::sort(b, b + m);
        
        REP(i, k + 1) {
            eatUp[i] = eatDown[i] = -1;
        }
        int cur = 0;
        eatUp[cur] = eatDown[cur] = 0;
        REP(i, k) {
            debug(cur);
            if (instr[i] == 'R') {
                cur ++;
            } else {
                cur --;
            }
            if (cur > 0) {
                if (eatUp[cur] == -1) {
                    eatUp[cur] = i;
                }
            } else {
                if (eatDown[-cur] == -1) {
                    eatDown[-cur] = i;
                }
            }
        }
        
        REP(i, k + 1) {
            AC[i] = 0;
        }
        REP(i, n) {
            int upTime = calcUpTime(i);
            int downTime = calcDownTime(i);
            int dt = std::min(upTime, downTime);

            if (dt > k) {
                continue;
            }
            AC[dt] ++;
        }
        REP(i, k) {
            AC[i + 1] += AC[i];
        }

        REP(i, k) {
            printf("%d%c", n - AC[i], (i + 1 == k ? 10 : 32));
        }
    }
}
