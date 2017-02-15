#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0 ; i <n ; ++i)

const int MOD = 1000000007;
const int N = 5000;
int C[ N + 5 ][ N + 5 ];
long long pow( long long a , long long b , long long c ){
	long long ans = 1;
	while( b ){
		if( b & 1 ) ans = (ans * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ans;
}
int main(){
	for( int i = 0 ; i <= N ; ++i ) C[ i ][ 0 ] = C[ i ][ i ] = 1;
	for( int i = 2 ; i <= N ; ++i )
		for( int j = 1 ; j <= N ; ++j )
			C[ i ][ j ] = (C[ i - 1 ][ j - 1 ] + C[ i - 1 ][ j ])%MOD;
	int cases;
	scanf( "%d" , &cases );
	REP( tc , cases ){
		int n;
		scanf( "%d" , &n );
		long long ans = 0;
		for( int L = 1 ; L <= n ; ++L ){
			long long term = C[ n ][ L ];
			term = (term * term) % MOD;
			term = (26 * term) % MOD;
			term = (pow(25 , L - 1, MOD) * term) % MOD;
			ans = (ans + term) %MOD;
		}
		printf( "%lld\n" , ans );
	}
}


