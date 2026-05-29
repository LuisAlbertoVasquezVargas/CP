#include <stdio.h>

enum {
    MAX_N = 200000,
    INF = 2147483646
};

// Declared sequentially exactly like your code
int A[MAX_N + 1];
int n;

int main() {
    n = 200000; // Codeforces Test #6 value

    // Print out physical memory addresses
    printf("[MEMORY] Address of A[%d] (End of array): %p\n", MAX_N, (void*)&A[MAX_N]);
    printf("[MEMORY] Address of A[%d] (Out of bounds): %p\n", MAX_N + 1, (void*)&A[MAX_N + 1]);
    printf("[MEMORY] Address of variable 'n'        : %p\n\n", (void*)&n);

    printf("[BEFORE] Value of n = %d\n", n);

    // This is your line from main()
    A[n + 1] = INF; 

    printf("[AFTER]  Value of n = %d  <-- CORRUPTED BY INF!\n", n);

    // Watch how your loop now goes completely out of bounds
    if (n == INF) {
        printf("[EXPLOSION] solve() will now loop from 1 to %d instead of 200000!\n", n);
    }

    return 0;
}
