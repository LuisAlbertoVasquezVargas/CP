#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ; i < n ; ++i)

typedef long long ll;

const int N = 500;
ll A[N + 5][N + 5];
bool f(ll sol, int n , int x , int y, ll S){
	if(sol <= 0) return 0;
	A[x][y] = sol;
	
	REP(i , n){
		ll cur = 0;
		REP(j , n) cur += A[i][j];
		if(cur != S) return 0;
	}
	REP(j , n){
		ll cur = 0;
		REP(i , n) cur += A[i][j];
		if(cur != S) return 0;
	}
	ll cur = 0 ;
	REP(i , n) cur += A[i][i];
	if(cur != S) return 0;
	cur = 0;
	REP(i , n) cur += A[i][n - 1 - i];
	if(cur != S) return 0;
	
	return 1;
}
int main(){
	int n;
	while(scanf("%d" , &n) == 1){
		REP(i , n)REP(j , n) {
			int num;
			scanf("%d" , &num);
			A[i][j] = num;
		}
		if(n == 1){
			puts("1");
			continue;
		}
		int x , y;
		REP(i , n) REP(j , n)
			if(A[i][j] == 0) x = i , y = j;
		
		int nx = (x + 1)%n ;
		ll S = 0;
		REP(j , n) S += A[nx][j];
		
		ll sol , S2 = 0;
		REP(j , n) S2 += A[x][j];
		sol = S - S2;
		
		if(f(sol , n , x , y, S)){
			cout << sol << '\n';
		}else{
			cout << -1 << '\n';
		}
	}
}


