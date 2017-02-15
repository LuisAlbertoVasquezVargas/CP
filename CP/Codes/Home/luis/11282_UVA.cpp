#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define N 21

typedef unsigned long long ull;

ull DP[ N ];
ull C[ N ][ N ];

int main()
{
	DP[ 0 ] = 1;
	DP[ 1 ] = 0;
	for( int i = 2 ; i < N ; ++i )
		DP[ i ] = ( i - 1 )*( DP[ i - 1 ] + DP[ i - 2 ] );
	REP( i , N ) C[ i ][ i ] = C[ i ][ 0 ] = 1;
	for( int i = 2 ; i < N ; ++i )
		for( int j = 1 ; j < i ; ++j ) C[ i ][ j ] = C[ i - 1 ][ j ] + C[ i - 1 ][ j - 1 ];
	/*
	REP( i , N ) cout << DP[ i ] << '\n';
	REP( i , N ) REP( j , N ) cout << C[ i ][ j ] << ( j + 1 == N ? "\n":" " );
	*/
	int n , m;
	while( cin >> n >> m ){
		ull ans = 0;
		for( int i = n - m ; i <= n ; ++i )
			ans += C[ n ][ i ] * DP[ i ];
		cout << ans << '\n';
	}
}
