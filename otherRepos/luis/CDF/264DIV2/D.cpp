#include<bits/stdc++.h>
using namespace std;

#define sc(x) scanf("%d" , &x)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)

#define SZ(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

bool isLess(vi &x , vi &y){
	REP(i,SZ(x)){
		if(x[ i ] < y[ i ])continue;
		return 0;
	}
	return 1;
}
int main(){
	int n , K;
	while(cin >> n >> K){
		vvi T(K , vi(n));
		REP(i,K)REP(j,n){
			cin >> T[i][j];
			T[i][j] --;
		}
		vi mapa(n);
		REP(i,n) mapa[T[0][i]] = i;
		REP(i,K)REP(j,n)
			T[i][j] = mapa[T[i][j]];
		
		vvi P(n,vi(K));
		REP(i,K){
			REP(j,n){
				P[ T[i][j] ][ i ] = j;
			}
		}
		/*
		REP(i,n){
			REP(j,K)cout << P[ i ][ j ] << " ";
			cout <<  endl;
		}
		*/
		int ans = 1;
		vi DP(n);
		DP[0] = 1;
		for(int i = 1 ; i < n ; ++i){
			DP[ i ] = 1;
			for(int j = 0 ; j < i ; ++j)
				if(isLess(P[j],P[i])) DP[ i ] = max(DP[i] , 1 + DP[j]);
			ans = max( ans , DP[ i ]);
		}
		printf("%d\n" , ans);
	}
}




