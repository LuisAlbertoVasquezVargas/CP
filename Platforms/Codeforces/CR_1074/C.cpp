#include<cstdio>
#include<algorithm>

#define REP(i, n) for(int i = 0; i < n; i++)

int max(int a, int b) {
    return (a < b ? b : a);
}

const int MAX_N = 4096;
int A[MAX_N];
int n;

int main() {
    int tc;
    scanf("%d", &tc);
    REP(it, tc) {
        scanf("%d", &n);
        REP(i, n) {
            scanf("%d", &A[i]);
        }
        std::sort(A, A + n);
        n = std::unique(A, A + n) - A;
        int maxi = 0;
        REP(i, n) {
            int len = 0;
            for (int j = i; j < n; ++j) {
                if (A[i] + (j - i) == A[j]) {
                    len ++;
                } else {
                    break;
                }
            }
            maxi = max(maxi, len);
        }
        printf("%d\n", maxi);
    }
}