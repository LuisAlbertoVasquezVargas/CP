#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0 ; i <n ; ++i)

const int N = 500;
int A[ N + 5 ];

int main(){
	int cases;
	scanf( "%d" , &cases );
	REP( tc , cases ){
		int n , H , W;
		scanf( "%d%d%d" , &n , &H , &W );
		REP( i , n )
			scanf( "%d" , &A[ i + 1 ] );
		A[ n + 1 ] = W;
		int ans = INT_MAX;
		sort( A , A + n + 1 );
		for( int i = 0 ; i <= n ; ++i )
			ans = min( ans , A[ i + 1 ] - A[ i ] );
		ans *= H;
		printf( "%d\n" , ans );
	}
}


