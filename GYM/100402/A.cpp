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

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

int main(){
	freopen( "graph.in" , "r" , stdin );
	freopen( "graph.out" , "w" , stdout );	
	int d , r;
	while( cin >> d >> r ){
		vpii edges;
		
		//[ 0 , d ]
		//[ d - r , r ]
		int used = ((d - r <= r) ? (r - (d - r) + 1) : 0 );
		int need = 2 * r - (used);
		int n = d + 1 + need;
		REP( i , d ) edges.pb( mp( i , i + 1 ) );
		vi vec;
		
		if( used ) for( int i = 0 , id = d + 1 ; i < need ; ++i , id ++ ) vec.pb( id );
		if( SZ(vec) ) edges.pb( mp( d - r , vec.front() ) );
		if( SZ(vec) ) {
			if( !(r == d - r && vec.front() == vec.back()) )
				edges.pb( mp( r , vec.back() ) );
		}
		REP( i , SZ( vec ) - 1 ) edges.pb( mp( vec[ i ] , vec[ i + 1 ] ) );
		int m = SZ( edges );
		puts( "YES" );
		printf( "%d %d\n" , n , m );
		REP( i , m ) printf( "%d %d\n" , edges[ i ].fi + 1 , edges[ i ].se + 1 );
	}
}


