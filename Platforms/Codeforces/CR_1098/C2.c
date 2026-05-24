#include <stdio.h>
#include <string.h>

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

#define INF (1LL << 61)

enum {
    EQUAL = 0,
    LESS = 1,
    GREATER = 2,
    MAX_DIGIT = 18,
    MAX_N = 10
};

int nt;
char target[32];
int dd[MAX_N];
int nd;

int used[MAX_DIGIT + 1][4];
LL memo[MAX_DIGIT + 1][4];
LL POT[MAX_DIGIT + 2];

void init() {
    POT[0] = 1LL;

    REP(i, MAX_DIGIT + 1) {
        POT[i + 1] = POT[i] * 10LL;
    }
}

void clear() {
    memset(used, 0, sizeof(used));
}

LL getDiff(int firstDigit, int secondDigit, int pos) {
    int delta = secondDigit - firstDigit;
    int exp = nt - 1 - pos;
    return ((LL)delta) * POT[exp];
}

LL dp(int pos, int state) {
    if (pos == nt) {
        return 0LL;
    }

    if (used[pos][state]) {
        return memo[pos][state];
    }

    used[pos][state] = 1;
    LL *ans = &memo[pos][state];
    *ans = INF;
    int targetDigit = target[pos] - '0';

    REP(i, nd) {
        int currentDigit = dd[i];
        if (state == EQUAL) {
            if (targetDigit == currentDigit) {
                *ans = MIN(*ans, dp(pos + 1, EQUAL));
            } else if (currentDigit < targetDigit) {
                *ans = MIN(*ans, getDiff(currentDigit, targetDigit, pos) + dp(pos + 1, LESS));
            } else {
                *ans = MIN(*ans, getDiff(targetDigit, currentDigit, pos) + dp(pos + 1, GREATER));
            }
        } else if (state == LESS) {
            *ans = MIN(*ans, getDiff(currentDigit, targetDigit, pos) + dp(pos + 1, LESS));
        } else {
            *ans = MIN(*ans, getDiff(targetDigit, currentDigit, pos) + dp(pos + 1, GREATER));
        }
    }

    return *ans;
}

LL solveSimple(char a[], int digits[], int n, int prevState) {
    strcpy(target, a);
    nt = strlen(a);
    nd = n;

    REP(i, n) {
        dd[i] = digits[i];
    }

    clear();

    return dp(0, prevState);
}

LL solveSameLength(char a[], int digits[], int n) {
    return solveSimple(a, digits, n, EQUAL);
}

LL solveShorterLength(char a[], int digits[], int n) {
    int len = strlen(a);

    if (len == 1) {
        return INF;
    }

    return ((LL)(a[0] - '0')) * POT[len - 1] + solveSimple(a + 1, digits, n, LESS);
}

LL solveLongerLength(char a[], int digits[], int n) {
    int len = strlen(a);
    int firstDigit = -1;

    REP(i, n) {
        if (digits[i] != 0) {
            firstDigit = digits[i];
            break;
        }
    }

    if (firstDigit == -1) {
        return INF;
    }

    char b[32];

    b[0] = '0' + firstDigit;

    REP(i, len) {
        b[i + 1] = '0' + digits[0];
    }

    b[len + 1] = '\0';

    return toLL(b) - toLL(a);
}

LL solve(char a[], int digits[], int n) {
    LL ans = INF;
    ans = MIN(ans, solveShorterLength(a, digits, n));
    ans = MIN(ans, solveSameLength(a, digits, n));
    ans = MIN(ans, solveLongerLength(a, digits, n));
    return ans;
}

int main() {
    init();

    int tc;
    sc(tc);

    REP(t, tc) {
        LL a;
        int n;

        scanf("%lld%d", &a, &n);

        int digits[MAX_N];

        REP(i, n) {
            sc(digits[i]);
        }

        char aStr[32];
        toStrLL(a, aStr);

        printf("%lld\n", solve(aStr, digits, n));
    }

    return 0;
}
