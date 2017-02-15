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

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define INF (1LL<<60)

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< ll > vll;
typedef vector< vll > vvll;

struct edg{
	int xa , ya , xb , yb , t;
	edg(){}
	edg( int xa , int ya , int xb , int yb , int t ) : xa( xa ) , ya( ya ) , xb( xb ) , yb( yb ) , t( t ) {}
};
int getUpper( vi &v , int x ){
	return upper_bound( all( v ) , x ) - v.begin();
}
int getLower( vi &v , int x ){
	int pos = lower_bound( all( v ) , x ) - v.begin();
	if( binary_search( all( v ) , x ) ) return pos;
	return pos - 1;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int len , F , m;
		sc( len ) , sc( F ) , sc( m );
		vector< edg > E;
		vvi T( len );
		REP( i , len ) T[ i ].pb( 0 ) , T[ i ].pb( F - 1 );
		REP( i , m ){
			int xa , ya , xb , yb , t;
			sc( xa ) , sc( ya ) , sc( xb ) , sc( yb ) , sc( t );
			xa -- , xb -- , ya -- , yb --;
			E.pb( edg( xa , ya , xb , yb , t ) );
			T[ xa ].pb( ya );
			T[ xb ].pb( yb );
		}
		
		int Q;
		sc( Q );
		vector< edg > queries;
		REP( q , Q ){
			int xa , ya , xb , yb;
			sc( xa ) , sc( ya ) , sc( xb ) , sc( yb );
			xa -- , xb -- , ya -- , yb --;
			queries.pb( edg( xa , ya , xb , yb , 0 ) );
			//T[ xa ].pb( ya );
			//T[ xb ].pb( yb );
			
		}
		for( auto &v : T ) {
			sort( all( v ) );
			v.resize( unique( all( v ) ) - v.begin() );
		}
		map< pii , int > mapa;
		map< int , pii > inv;
		int cnt = 0;
		REP( x , len ){
			vi v = T[ x ];
			for( auto y : v ){
				mapa[ mp( x , y ) ] = cnt;
				inv[ cnt ] = mp( x , y );
				cnt ++;
			}
		}
		
		int n = cnt;
		vvll DP( n , vll( n , INF ) );
		REP( i , n ) DP[ i ][ i ] = 0;
		
		REP( x , len ){
			REP( i , SZ(T[ x ]) - 1 ){
				int xa = x , xb = x;
				int ya = T[ x ][ i ] , yb = T[ x ][ i + 1 ];
				int u = mapa[ mp( xa , ya ) ] , v = mapa[ mp( xb , yb ) ];
				ll w = min( DP[ u ][ v ] , (ll)(yb - ya) );
				DP[ u ][ v ] = DP[ v ][ u ] = w;	
			}
		}
		REP( xa , len ){
			int xb = (xa + 1)%len;
			int ya = 0 , yb = 0;
			int u = mapa[ mp( xa , ya ) ] , v = mapa[ mp( xb , yb ) ];
			ll w = min( DP[ u ][ v ] , 1LL );
			DP[ u ][ v ] = DP[ v ][ u ] = w;
		}
		REP( i , SZ( E ) ){
			int xa , ya , xb , yb , t;
			xa = E[ i ].xa;
			ya = E[ i ].ya;
			xb = E[ i ].xb;
			yb = E[ i ].yb;
			t = E[ i ].t;
			int u = mapa[ mp( xa , ya ) ] , v = mapa[ mp( xb , yb ) ];
			ll w = min( DP[ u ][ v ] , (ll)t );
			DP[ u ][ v ] = DP[ v ][ u ] = w;
		}
		REP( k , n ) REP( i , n ) REP( j , n )
			DP[ i ][ j ] = min( DP[ i ][ j ] , DP[ i ][ k ] + DP[ k ][ j ] );
			
		for( auto e : queries ){
			int xa = e.xa , ya = e.ya , xb = e.xb , yb = e.yb;

			int loa = getUpper( T[ xa ] , ya );
			int hia = getLower( T[ xa ] , ya );
			int lob = getUpper( T[ xb ] , yb );
			int hib = getLower( T[ xb ] , yb );
			vi A = { loa , hia };

			vi B = { lob , hib };
			ll ans = INF;
			if( xa == xb ) ans = min( ans , (ll)abs( ya - yb ) );
			/*
			DEBUG2( xa , ya );
			DEBUG2( xb , yb );
			*/
			for( auto pa : A )
				for( auto pb : B ){
					
					int u = mapa[ mp( xa , T[ xa ][ pa ] ) ];
					int v = mapa[ mp( xb , T[ xb ][ pb ] ) ];
					ans = min( ans , (ll)abs( T[ xa ][ pa ] - ya ) + (ll)abs( T[ xb ][ pb ] - yb ) + DP[ u ][ v ] );
					/*
					test();
					DEBUG2( pa , T[ xa ][ pa ] );
					DEBUG2( pb , T[ xb ][ pb ] );
					DEBUG( abs( T[ xa ][ pa ] - ya ) + abs( T[ xb ][ pb ] - yb ) + DP[ u ][ v ] );
					*/
				}
			printf( "%lld\n" , ans );
		}
		
	}
}


