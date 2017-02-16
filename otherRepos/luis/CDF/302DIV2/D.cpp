#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )
 
#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())
 
#define mp make_pair
#define fi first
#define se second

#define INF (1<<20)

typedef vector< int > vi;
typedef vector< vi > vvi;

int n;
vi bfs( vi &x , vi &y , int s ){
	vi dist( n , INF );
	vvi G( n );
	REP( i , SZ( x ) ){
		int u = x[ i ] , v = y[ i ];
		G[ u ].pb( v );
		G[ v ].pb( u );
	}
	queue< int > Q;
	dist[ s ] = 0;
	Q.push( s );
	while( !Q.empty() ){
		int u = Q.front();
		Q.pop();
		REP( i , SZ( G[ u ] ) ){
			int v = G[ u ][ i ];
			if( dist[ v ] >= INF ){
				dist[ v ] = dist[ u ] + 1;
				Q.push( v );
			}
		}
	}
	return dist;
}
int solve( vi &x , vi &y , int S1 , int T1 , int L1 , int S2 , int T2 , int L2 ){
	vvi dist;
	int ans = INF;
	REP( i , n ) dist.pb( bfs( x , y , i ) );
	REP( u , n ) REP( v , n ){
		int a = dist[ S1 ][ u ] + dist[ u ][ v ] + dist[ v ][ T1 ];
		int b = dist[ S2 ][ u ] + dist[ u ][ v ] + dist[ v ][ T2 ];
		if( a <= L1 && b <= L2 ) ans = min( ans , a + b - dist[ u ][ v ] );
		
		b = dist[ S2 ][ v ] + dist[ v ][ u ] + dist[ u ][ T2 ];
		if( a <= L1 && b <= L2 ) ans = min( ans , a + b - dist[ v ][ u ] );
	}
	if( dist[ S1 ][ T1 ] <= L1 && dist[ S2 ][ T2 ] <= L2 ) ans = min( ans , dist[ S1 ][ T1 ] + dist[ S2 ][ T2 ] );
	return ans;
}
int main(){
	int m;
	while( sc( n ) == 1 ){
		sc( m );
		vi x , y;
		REP( i , m ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			x.pb( u );
			y.pb( v );
		}
		int S1 , T1 , L1 , S2 , T2 , L2;
		sc( S1 ) , sc( T1 ) , sc( L1 );
		S1 -- , T1 -- ;
		sc( S2 ) , sc( T2 ) , sc( L2 );
		S2 -- , T2 -- ;
		int ans = solve( x , y , S1 , T1 , L1 , S2 , T2 , L2 );
		if( ans >= INF ){
			puts( "-1" );
			continue;
		}
		printf( "%d\n" , m - ans );
	}
}
