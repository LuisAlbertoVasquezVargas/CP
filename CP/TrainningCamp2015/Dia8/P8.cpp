#include <bits/stdc++.h>
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

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 50000

typedef long long ll;
typedef long double ld;
typedef pair< int , int > pii;
typedef pair< pii , pii > ppii;
typedef vector< pii > vpii;
typedef vector< int > vi;

vi G[ N + 5 ] , C[ N + 5 ];
ll F[ N + 5 ];
ll dpF[ N + 5 ] , dpS[ N + 5 ];

void add( int u , int v , int w ){
	G[ u ].pb( v );
	C[ u ].pb( w );
}
int vis[ N + 5 ];
void dfs( int u , int p = -1 ){
	vis[ u ] = 1;
	dpS[ u ] = 0;
	dpF[ u ] = F[ u ];
	for( int i = 0 ; i < SZ(G[ u ]) ; ++i ){
		int v = G[ u ][ i ] , w = C[ u ][ i ];
		if( v == p ) continue;
		if( !vis[ v ] ) {
			dfs( v , u );
			dpS[ u ] += dpS[ v ] + (ll)w * dpF[ v ];
			dpF[ u ] += dpF[ v ];
		}
	}
}
ll ans , totF , S[ N + 5 ];

void DFS( int u , int p , ll cur ){
	vis[ u ] = 1;
	ans = min( ans , cur );
	S[ u ] = cur;
	for( int i = 0 ; i < SZ(G[ u ]) ; ++i ){
		int v = G[ u ][ i ] , w = C[ u ][ i ];
		if( v == p ) continue;
		if( !vis[ v ] )
			DFS( v , u , cur - dpF[ v ] * (ll)w + (totF - dpF[v]) * (ll)w );
	}
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		REP( i , n ) G[ i ].clear() , C[ i ].clear();
		REP( i , n - 1 ){
			int u , v , w;
			sc( u ) , sc( v ) , sc( w );
			u -- , v --;
			add( u , v , w );
			add( v , u , w );
		}
		clr( F , 0 );
		int m;
		sc( m );
		REP( i , m ){
			int u , fr;
			sc( u ) , sc( fr );
			u --;
			F[ u ] = fr;
		}
		clr( vis , 0 );
		dfs( 0 );
		totF = dpF[ 0 ];
		ans = LLONG_MAX;
		clr( vis , 0 );
		DFS( 0 , -1 , dpS[ 0 ] );
		vi vec;
		REP( i , n )
			if( S[ i ] == ans ) vec.pb( i );
		ans <<= 1;
		printf( "%lld\n" , ans );
		REP( i , SZ(vec) ) printf( "%d%c" , vec[ i ] + 1 , (i + 1== SZ(vec)) ? 10 : 32 );
	}
}





