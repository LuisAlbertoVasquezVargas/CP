#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it ++ )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back

#define N 50000
#define LOGN 19

typedef vector< int > vi;

vi E[ N + 5 ] , W[ N + 5 ];
int n;
int vis[ N + 5 ] , pa[ N + 5 ] , depth[ N + 5 ] , distRoot[ N + 5 ];

void dfs( int u ){
	vis[ u ] = 1;
	REP( i , E[ u ].size() ){
		int v = E[ u ][ i ] , w = W[ u ][ i ];
		if( !vis[ v ] ){
			pa[ v ] = u;
			depth[ v ] = depth[ u ] + 1;
			distRoot[ v ] = distRoot[ u ] + w;
			dfs( v );
		}
	}
}
int rmq[ LOGN + 1 ][ N + 5 ];
void RMQ(){
	clr( rmq , -1 );
	REP( i , n ) rmq[ 0 ][ i ] = pa[ i ];
	for( int k = 1 ; k <= LOGN ; ++k )
		REP( i , n ) if( rmq[ k - 1 ][ i ] != - 1 )
			rmq[ k ][ i ] = rmq[ k - 1 ][ rmq[ k - 1 ][ i ] ];
}

int lca( int u , int v ){
	if( depth[ u ] > depth[ v ] ) swap( u , v );
	int dist = depth[ v ] - depth[ u ];

	for( int k = 0 ; k <= LOGN ; ++k ) if( dist & ( 1 << k ) ) v = rmq[ k ][ v ];
	if( u == v ) return u;
	for( int k = LOGN ; k >= 0 ; --k )
		if( rmq[ k ][ u ] != rmq[ k ][ v ] ) u = rmq[ k ][ u ] , v = rmq[ k ][ v ];
	return pa[ u ];
}
int main(){
	int u , v , w , Q;
	while( sc( n ) == 1 ){
		REP( i , n ) E[ i ].clear() , W[ i ].clear();
		REP( i , n - 1 ){
			sc( u ) , sc( v ) , sc( w );
			E[ u ].pb( v );
			W[ u ].pb( w );
			
			E[ v ].pb( u );
			W[ v ].pb( w );
		}
		clr( vis , 0 );
		depth[ 0 ] = 0;
		pa[ 0 ] = -1;
		dfs( 0 );
		RMQ();
		sc( Q );
		while( Q -- ){
			sc( u ) , sc( v );
			printf( "%d\n" , distRoot[ u ] + distRoot[ v ] - 2*distRoot[ lca( u , v ) ] );
		}
	}
}
