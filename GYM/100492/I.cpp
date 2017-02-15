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
typedef vector< int > vi;
typedef vector< vi > vvi;

char cad[ 10 ];
struct event{
	int x , y , timer;
	event(){}
	event( int x , int y , int timer ) : x( x ) , y( y ) , timer( timer ) {}
};
bool operator < ( const event &e1 , const event &e2 ){
	if( e1.x != e2.x ) return e1.x < e2.x;
	if( e1.y != e2.y ) return e1.y < e2.y;
	return e1.timer < e2.timer;
}
int main(){
	freopen("intouch.in", "r", stdin);
	freopen("intouch.out", "w", stdout);
	int n , m ;
	while( sc( n ) == 1 ){
		sc( m );
		vvi spam( n );
		vector< event > E;
		REP( it , m ){
			scanf( "%s" , cad );
			if( cad[ 0 ] == '!' ){
				int x;
				sc( x );
				x -- ;
				spam[ x ].pb( it );
			}else{
				int x , y;
				sc( x ) , sc( y );
				x -- , y --;
				if( x > y ) swap( x , y );
				E.pb( event( x , y , it ) );
			}
		}
		sort( all( E ) );
		vi ans( n );
		REP( i , SZ( E ) ){
			int ind;
			vi vec;
			for( int j = i ; j < SZ( E ) ; ++j )
				if( E[ i ].x == E[ j ].x && E[ i ].y == E[ j ].y ){
					vec.pb( E[ j ].timer );
					ind = j;
				}else break;
			if( SZ( vec ) & 1 ) vec.pb( INT_MAX );
			int x = E[ i ].x , y = E[ i ].y;
			for( int k = 0 ; k + 1 < SZ( vec ) ; k += 2 ){
				int lo = vec[ k ] , hi = vec[ k + 1 ];
				int cx = upper_bound( all( spam[ x ] ) , hi ) - lower_bound( all( spam[ x ] ) , lo );
				int cy = upper_bound( all( spam[ y ] ) , hi ) - lower_bound( all( spam[ y ] ) , lo );
				ans[ x ] += cy;
				ans[ y ] += cx;
			}
			i = ind;
		}
		REP( i , n ) printf( "%d%c" , ans[ i ] , (i + 1 == n ? 10 : 32 ) );
	}
}




