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

#define N 100000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		vi len( 2 );
		REP( k , 2 ) sc( len[ k ] );
		vector< map< int , int > > mapa( 2 );
		REP( k , 2 ){
			REP( i , len[ k ] ){
				int x;
				sc( x );
				mapa[ k ][ x ] ++;
			}
		}
		vector< vpii > T( 2 );
		REP( k , 2 ) T[ k ] = vpii( all( mapa[ k ] ) );
		bool ok = 1;
		for( int i = 0 , j = 0 ; i < SZ( mapa[ 0 ] ) ; ++i ){
			if( !ok ) break;
			while( 1 ){
				if( j >= SZ( mapa[ 1 ] ) ){
					ok = 0;
					break;
				}
				if( T[ 0 ][ i ].se <= T[ 1 ][ j ].se ){
					j ++;
					break;
				}
				j ++;
			}
		}
		puts( ok ? "YES" : "NO" );
	}
}



