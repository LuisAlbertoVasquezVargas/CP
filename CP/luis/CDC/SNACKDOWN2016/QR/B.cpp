#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define all(v) v.begin(),v.end()

typedef long long LL;
typedef vector< LL > VLL;
typedef vector< int > VI;

VLL get( VI &A ){
	int n = A.size();
	VLL DP( n );
	DP[ 0 ] = A[ 0 ];
	for( int i = 1 ; i < n ; ++i )
		DP[ i ] = max( (LL)A[ i ] , A[ i ] + DP[ i - 1 ] );
	return DP;
}
int main(){
	int cases;
	scanf( "%d" , &cases );
	REP( tc , cases ){
		int n;
		scanf( "%d" , &n );
		VI A( n );
		REP( i , n ) scanf( "%d" , &A[ i ] );
		VLL dp = get( A );
		reverse( all( A ) );
		VLL dpRev = get( A );
		reverse( all( dpRev ) );
		LL ans = LLONG_MIN;
		REP( i , n ) ans = max( ans , dp[ i ] );
		for( int i = 1 ; i + 1 < n ; ++i ){
			ans = max( ans , dp[ i - 1 ] + dpRev[ i + 1 ] );
		}
		printf( "%lld\n" , ans );
	}
}



