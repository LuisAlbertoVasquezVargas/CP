#include<cstdio>

int main() {
    int tc;
    scanf("%d", &tc);
    for (int t = 0; t < tc; t++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i ++) {
            printf("%d", i + 1);
            if (i != n - 1) {
                putchar(' ');
            } else {
                putchar('\n');
            }
        }
    }
}