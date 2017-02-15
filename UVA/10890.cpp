#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define N 35

int dim , n , S;
int ans;

int x[ N + 5 ] , y[ N + 5 ];
int dist[ N + 5 ][ N + 5 ];

void f( int u , int mask , int cur ){
	
	if( cur + dist[ u ][ n - 1 ] >= ans ) return;
	
	if( __builtin_popcount( mask ) == S ){
		ans = min( ans , cur + dist[ u ][ n - 1 ] );
		return;
	}
	
	for( int v = 1 ; v <= n - 2 ; ++v )
		if( !(mask & (1 << v)) )f( v , mask | (1 << v) , cur + dist[ u ][ v ] );
}

int main(){
	int tc = 0;
	while( scanf( "%d%d%d" , &dim , &n , &S ) == 3 ){
		if( !dim && !n && !S ) break;
		
		for( int i = 1 ; i <= n ; ++i ){
			scanf( "%d%d" , &x[ i ] , &y[ i ] );
			
			int j = rand() % i + 1;
			swap( x[ i ] , x[ j ] );
			swap( x[ i ] , x[ j ] );
			
		}
		x[ 0 ] = y[ 0 ] = 0;
		x[ n + 1 ] = y[ n + 1 ] = dim - 1;
		n += 2;
		REP( i , n ) REP( j , n )
			dist[ i ][ j ] = abs( x[ j ] - x[ i ] ) + abs( y[ j ] - y[ i ] );
			
		ans = INT_MAX;
		f( 0 , 0 , 0 );
		printf( "Case %d: %d\n" , ++tc , ans );
		
	}
}
