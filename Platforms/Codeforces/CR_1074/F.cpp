#include <cstdio> // scanf, printf, fprintf
#include <vector> // vector
#include <cassert> // assert

// TODO(lvasquez): now extend for vector<long long> if u see fit
//  - add coding standard mentioning REP_(...) where _ = "empty"
//  - but for simple structures if_() the _ = "space"
//  - add coding standards like camelcase or underscorecase

typedef std::vector<int> VI;

#define sc1(x) scanf("%d", &(x))
#define sc2(x, y) scanf("%d%d", &(x), &(y))
#define sc3(x, y, z) scanf("%d%d%d", &(x), &(y), &(z))
#define sc4(x, y, z, w) scanf("%d%d%d%d", &(x), &(y), &(z), &(w))
#define GET_SC(_1, _2, _3, _4, NAME, ...) NAME
#define sc(...) GET_SC(__VA_ARGS__, sc4, sc3, sc2, sc1)(__VA_ARGS__)

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define PB push_back
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

#define sc1(x) scanf("%d", &(x))
#define sc2(x, y) scanf("%d%d", &(x), &(y))
#define sc3(x, y, z) scanf("%d%d%d", &(x), &(y), &(z))
#define sc4(x, y, z, w) scanf("%d%d%d%d", &(x), &(y), &(z), &(w))

const int MAX_ND = (1 << 19);
int n, N;
int a[MAX_ND];
VI stacks[MAX_ND];
VI concat2(const VI &a, const VI &b) {
    VI ans;
    REP(i, SZ(a)) {
        ans.PB(a[i]);
    }
    REP(i, SZ(b)) {
        ans.PB(b[i]);
    }
    return ans;
}

VI concat3(const VI &a, const VI &b, const VI &c) {
    return concat2(concat2(a, b), c);
}

VI join(VI stack_left, VI stack_right) {
    int xor_left = stack_left.back();
    stack_left.pop_back();
    int xor_right = stack_right.back();
    stack_right.pop_back();
    int xor_res = xor_left ^ xor_right;
    if (xor_left >= xor_right) {
        return concat3(stack_right, stack_left, VI(1, xor_res));
    }
    return concat3(stack_left, stack_right, VI(1, xor_res));
}

void build(int node, int aa, int bb) {
    if (aa == bb) {
        stacks[node] = {aa, a[aa]};
        return;
    }
    int mid = (aa + bb) / 2;
    int lnode = node * 2 + 1;
    int rnode = node * 2 + 2;
    build(lnode, aa, mid);
    build(rnode, mid + 1, bb);
    stacks[node] = join(stacks[lnode], stacks[rnode]);
}

VI query(int node, int aa, int bb, int pos, int val) {
    if (pos < aa || bb < pos) {
        return stacks[node];
    }
    if (aa == bb) {
        return {aa, val};
    }
    int mid = (aa + bb) / 2;
    int lnode = node * 2 + 1;
    int rnode = node * 2 + 2;
    VI left = query(lnode, aa, mid, pos, val);
    VI right = query(rnode, mid + 1, bb, pos, val);
    return join(left, right);
}

int main() {
    int tc;
    sc(tc);
    REP(t, tc) {
        int q;
        sc(n, q);
        N = (1 << n);
        REP(i, N) {
            sc(a[i]);
        }
        build(0, 0, N - 1);
        REP(i, q) {
            int pos, val;
            sc(pos, val);
            pos --;
            VI ans = query(0, 0, N - 1, pos, val);
            ans.pop_back();
            int cnt = 0;
            while (!ans.empty()) {
                if (ans.back() == pos) {
                    break;
                }
                ans.pop_back();
                cnt ++;
            }
            printf("%d\n", cnt);
        }
    }
}

