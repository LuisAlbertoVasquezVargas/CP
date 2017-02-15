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
#define LOGN 17
#define INF (1LL<<60)

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

struct segment{
	int lo , hi , x;
	segment(){}
	segment( int lo , int hi , int x ) : lo( lo ) , hi( hi ) , x( x ) {}
};
bool operator < ( const segment &a , const segment &b ){ return a.x < b.x; }
#define v1 ((node<<1)+1)
#define v2 (v1+1)
#define med ((a+b)>>1)
#define LEFT v1 , a , med
#define RIGHT v2 , med + 1 , b

ll T[ 4 * N + 5 ] , flag[ 4 * N + 5 ];
void build_tree( int node , int a , int b ){
	T[ node ] = -INF;
	flag[ node ] = -INF;
	if( a == b )
		return;
	build_tree( LEFT );
	build_tree( RIGHT );
}
void push( int node , int a , int b ){
	if( flag[ node ] == -INF ) return;
	T[ node ] = max( T[ node ] , flag[ node ] );
	if( a != b ){
		flag[ v1 ] = flag[ node ];
		flag[ v2 ] = flag[ node ];
	}
	flag[ node ] = -INF;
}
ll query( int node , int a , int b , int lo , int hi ){
	push( node , a , b );
	if( lo > b || a > hi ) return -INF;
	if( a >= lo && hi >= b ) return T[ node ];
	return max( query( LEFT , lo , hi ) , query( RIGHT , lo , hi ) );
}
void update( int node , int a , int b , int lo , int hi , ll val ){
	push( node , a , b );
	if( lo > b || a > hi ) return;
	if( a >= lo && hi >= b ) {
		flag[ node ] = val;
		push( node , a , b );
		return;
	}
	update( LEFT , lo , hi , val );
	update( RIGHT , lo , hi , val );
	T[ node ] = max( T[ v1 ] , T[ v2 ] );
}
int rmq[ LOGN + 1 ][ N + 5 ];

int query( int a , int b ){ 
	int r = 31 - __builtin_clz( b - a + 1 );
	return min( rmq[ r ][ a ] , rmq[ r ][ b - (1<<r) + 1 ] );
}

int main(){
	freopen( "rmq.in" , "r" , stdin );
	freopen( "rmq.out" , "w" , stdout );	
	int n , m;
	while( sc( n ) == 1 ){
		sc( m );
		vector< segment > S;
		REP( i , m ){
			int lo , hi , x;
			sc( lo ) , sc( hi ) , sc( x );
			lo -- , hi --;
			S.pb( segment( lo , hi , x ) );
		}
		sort( all( S ) );
		build_tree( 0 , 0 , n - 1 );
		REP( i , SZ( S ) ){
			int lo = S[ i ].lo , hi = S[ i ].hi;
			ll val = S[ i ].x;
			update( 0 , 0 , n - 1 , lo , hi , val );
		}
		REP( i , n ) {
			ll x = query( 0 , 0 , n - 1 , i , i );
			if( x == -INF ) rmq[ 0 ][ i ] = 0;
			else rmq[ 0 ][ i ] = x;
		}
		for( int k = 1 ; k <= LOGN ; ++k )
			for( int i = 0 ; i + (1<<k) <= n ; ++i )
				rmq[ k ][ i ] = min( rmq[ k - 1 ][ i ] , rmq[ k - 1 ][ i + (1<<(k - 1)) ] );
		bool ok = 1;
		REP( i , SZ( S ) ){
			int lo = S[ i ].lo , hi = S[ i ].hi;
			ll val = S[ i ].x;
			if( query( lo , hi ) > val ) {
				ok = 0;
				break;
			}
		}
		
		if( !ok ){
			puts( "inconsistent" );
			continue;
		}
		puts( "consistent" );
		REP( i , n ) printf( "%d%c" , rmq[ 0 ][ i ] , (i + 1 == n) ? 10 : 32 );
	}
}


