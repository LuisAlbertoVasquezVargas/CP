#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < (n); ++i)

#define all(v) v.begin(),v.end()

const int N = 1e5;
int A[N + 5];
int main(){
	int n;
	while(scanf("%d" , &n) == 1){
		REP(i , n) scanf("%d" , &A[i]);

		REP(i , n - 1) A[i] += A[i + 1];
		
		REP(i , n) printf("%d%c" , A[i] , i + 1 == n ? 10 : 32);
	}
}


