#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it++ )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back

#define N 3005
typedef vector< int > vi;
typedef vector< vi > vvi;

#define inf 1000001

int S,T,cap[ N ][ N ];
vi E[ N ];
bool vis[ N ];
set< int > Set[ N ];
int dfs(int u,int hasta){
	if( u == T )return hasta;
	if( vis[ u ] )return 0;
	vis[ u ] = 1;
	FOR( v , E[ u ] ){
		if( cap[ u ][ *v ] <= 0 )continue;
		int r = dfs( *v , min( hasta , cap[ u ][ *v ] ) );
		if( r <= 0 )continue;
		Set[ u ].insert( *v );
		cap[ u ][ *v ] -= r;
		Set[ *v ].erase( u );
		cap[ *v ][ u ] += r;
		return r;
	}
	return 0;
}

int maxFlow( int s , int t ){
	S = s , T = t;
	int flow = 0;
	while( 1 ){
		clr( vis , 0 );
		int r = dfs( S , inf );
		if( r <= 0 )break;
		flow += r;
	}
	return flow;
}


void add_edge( int x , int y , int val ){
	E[ x ].pb( y );
	E[ y ].pb( x );
	cap[ x ][ y ] += val;
	cap[ y ][ x ] = 0 ;
}

void impr( vi v ){
	int nv = v.size();
	REP( i , nv ) printf( "%d%c" , v[ i ] + 1 , i + 1 == nv ? 10 : 32 );
}
int main()
{
	int n , nk , tam , x ;
	while( sc( nk ) == 1 )
	{
		sc( n );
		if( nk == 0 ) break;
		int s = n + nk , t = n + nk + 1;
		REP( i , t ) E[ i ].clear() , Set[ i ].clear();
		clr( cap , 0 );
		REP( i , n ) add_edge( s , i , 1 );
		int total = 0;
		REP( i , nk ){
			sc( tam );
			total += tam;
			add_edge( n + i , t , tam );
		}
		REP( i , n ){
			sc( tam );
			REP( j , tam )sc( x ) , x-- , add_edge( i , n + x , 1 );
		}
		int flow = maxFlow( s , t );
		//cout << "flow : " << flow << endl;
		if( flow != total ){
			puts( "0" );
			continue;
		}
		puts( "1" );
		//REP( i , n )REP( j , nk )
		//	if( Set[ i ].count( n + j ) ) cout << i << " " ;
		vvi ans( nk );
		REP( i , n ){
			FOR( v , Set[ i ] ) ans[ *v - n ].pb( i );
		}
		REP( i , nk ) impr( ans[ i ] );
	}
}

