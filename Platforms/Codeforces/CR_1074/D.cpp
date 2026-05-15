#include<cstdio>
#include<vector>

#define sc(x) scanf("%d", &x)
#define REP(i, n) for(int i = 0; i < n; i++)

#define sc2(x,y) scanf("%d%d", &x, &y)
#define sc3(x,y,z) scanf("%d%d%d", &x, &y, &z)

const int MAX_N = 256 * 1024;
int n, m, h;
int A[MAX_N];
std::vector<int> indexes, values;
void reset() {
    while (!indexes.empty()) {
        int pos = indexes.back();
        indexes.pop_back();
        int val = values.back();
        values.pop_back();
        A[pos] -= val;
    }
}

void process(int pos, int val) {
    if (A[pos] + val <= h) {
        indexes.push_back(pos);
        values.push_back(val);
        A[pos] += val;
    } else {
        reset();
    }
}

int main() {
    int tc;
    sc(tc);
    REP(it, tc) {
        indexes.clear();
        values.clear();
        sc3(n, m, h);
        REP(i, n) {
            sc(A[i]);
        }
        REP(i, m) {
            int b, c;
            sc2(b, c);
            b --;
            process(b, c);
        }
        REP(i, n) {
            printf("%d%c", A[i], (i + 1 == n ? 10: 32));
        }
    }
}