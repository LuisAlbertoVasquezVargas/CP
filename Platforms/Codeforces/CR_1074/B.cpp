#include<cstdio>

#define REP(i, n) for(int i = 0; i < n; i++)

const int MAX_N = 64;
int A[MAX_N];

// only works for different addresses
void swap(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

int max(int a, int b) {
    return (a < b ? b : a);
}

int find_local(int n) {
    int maxi = 0;
    int acum = 0;
    REP(i, n) {
        maxi = max(maxi, A[i]);
        acum += maxi;
    }
    return acum;
}

int func(int n) {
    int maxi = find_local(n);
    REP(j, n) {
        REP(i, j) {
            swap(A[i], A[j]);
            maxi = max(maxi, find_local(n));
            swap(A[i], A[j]);
        }
    }
    return maxi;
}

int main() {
    int tc;
    scanf("%d", &tc);
    REP(t, tc) {
        int n;
        scanf("%d", &n);
        REP(i, n) {
            scanf("%d", &A[i]);
        }
        printf("%d\n", func(n));
    }
}

