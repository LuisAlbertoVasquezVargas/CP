#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

typedef long long LL;
typedef std::vector<int> VI;
typedef std::string string; // temporal while not using std

#define sc1(x) scanf("%d", &(x))
#define sc2(x, y) scanf("%d%d", &(x), &(y))
#define sc3(x, y, z) scanf("%d%d%d", &(x), &(y), &(z))
#define sc4(x, y, z, w) scanf("%d%d%d%d", &(x), &(y), &(z), &(w))
#define GET_SC(_1, _2, _3, _4, NAME, ...) NAME
#define sc(...) GET_SC(__VA_ARGS__, sc4, sc3, sc2, sc1)(__VA_ARGS__)

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define PB push_back
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

string toStr(LL num) {
    if (num == 0) {
        return "0";
    }

    string ans;
    while (num > 0) {
        int d = num % 10;
        ans += '0' + d;
        num /= 10;
    }
    reverse(ALL(ans));
    return ans;
}

LL toLL(string str) {
    LL ans = 0;

    REP(i, SZ(str)) {
        ans = ans * 10LL + (str[i] - '0');
    }
    return ans;
}

const int EQUAL = 0;
const int LESS = 1;
const int GREATER = 2;
const LL INF = (1LL << 61);
const int MAX_DIGIT = 18;

int nt;
string target;
VI dd;

int used[MAX_DIGIT + 1][4];
LL memo[MAX_DIGIT + 1][4];
LL POT[MAX_DIGIT + 1];

void init() {
    POT[0] = 1LL;

    REP(i, MAX_DIGIT) {
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

    LL &ans = memo[pos][state] = INF;
    int targetDigit = target[pos] - '0';

    REP(i, SZ(dd)) {
        int currentDigit = dd[i];

        if (state == EQUAL) {
            if (targetDigit == currentDigit) {
                ans = MIN(ans, dp(pos + 1, EQUAL));
            } else if (currentDigit < targetDigit) {
                ans = MIN(ans, getDiff(currentDigit, targetDigit, pos) + dp(pos + 1, LESS));
            } else {
                ans = MIN(ans, getDiff(targetDigit, currentDigit, pos) + dp(pos + 1, GREATER));
            }
        } else if (state == LESS) {
            ans = MIN(ans, getDiff(currentDigit, targetDigit, pos) + dp(pos + 1, LESS));
        } else {
            ans = MIN(ans, getDiff(targetDigit, currentDigit, pos) + dp(pos + 1, GREATER));
        }
    }

    return ans;
}

LL solveSimple(string a, VI digits, int prevState) {
    target = a;
    nt = SZ(a);
    dd = digits;

    clear();
    return dp(0, prevState);
}

LL solveSameLength(string a, VI digits) {
    return solveSimple(a, digits, EQUAL);
}

LL solveShorterLength(string a, VI digits) {
    if (SZ(a) == 1) {
        return INF;
    }
    return ((LL)(a[0] - '0')) * POT[SZ(a) - 1] + solveSimple(a.substr(1), digits, LESS);
}

LL solveLongerLength(string a, VI digits) {
    int firstDigit = -1;

    REP(i, SZ(digits)) {
        if (digits[i] != 0) {
            firstDigit = digits[i];
            break;
        }
    }

    if (firstDigit == -1) {
        return INF;
    }

    string b;
    b += '0' + firstDigit;

    REP(i, SZ(a)) {
        b += '0' + digits[0];
    }
    return toLL(b) - toLL(a);
}

LL solve(string a, VI digits) {
    LL ans = INF;
    ans = MIN(ans, solveShorterLength(a, digits));
    ans = MIN(ans, solveSameLength(a, digits));
    ans = MIN(ans, solveLongerLength(a, digits));
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

        VI digits;
        REP(i, n) {
            int digit;
            sc(digit);
            digits.PB(digit);
        }
        printf("%lld\n", solve(toStr(a), digits));
    }
    return 0;
}
