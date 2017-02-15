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
#define MOD 1000000007LL

typedef long long ll;
typedef pair< int , int > pii;
typedef pair< ll , ll > pll;
typedef vector< int > vi;


#define v1 ((node<<1)+1)
#define v2 (v1+1)
#define med ((a+b)>>1)
#define LEFT v1 , a , med
#define RIGHT v2 , med + 1 , b

ll T[ 4 * N + 5 ] ;
int A[ N + 5 ];
pll flag[ 4 * N + 5 ];
//1(+),2(*),3(=)

pll get( pll a , pll b ){
	return mp( (a.fi * b.fi)%MOD , (a.se * b.fi + b.se)%MOD );
}
void push( int node , int a , int b ){
	if( flag[ node ] == mp( 1LL , 0LL ) ) return;
	T[ node ] = (flag[ node ].fi * T[ node ] + flag[ node ].se * (ll)(b - a + 1) )%MOD;
	if( a != b ){
		flag[ v1 ] = get( flag[ v1 ] , flag[ node ] );
		flag[ v2 ] = get( flag[ v2 ] , flag[ node ] );
	}
	flag[ node ] = mp( 1LL , 0LL );
}
void build_tree( int node , int a , int b ){
	flag[ node ] = mp( 1LL , 0LL );
	if( a == b ){
		T[ node ] = A[ a ];
		return;
	}
	build_tree( LEFT );
	build_tree( RIGHT );
	T[ node ] = (T[ v1 ] + T[ v2 ])%MOD;
}
ll query( int node , int a , int b , int lo , int hi ){
	push( node , a , b );
	if( lo > b || a > hi ) return 0;
	if( a >= lo && hi >= b ) return T[ node ];
	ll L = query( LEFT , lo , hi ) , R = query( RIGHT , lo , hi );
	return (L + R)%MOD;
}
void update( int node , int a , int b , int lo , int hi , int type , int val ){
	push( node , a , b );
	if( lo > b || a > hi ) return;
	if( a >= lo && hi >= b ){
		if( type == 1 ){
			flag[ node ] = mp( 1 , val );
		}else if( type == 2 ){
			flag[ node ] = mp( val , 0 );
		}else{
			flag[ node ] = mp( 0 , val );
			push( node , a , b );
		}
		push( node , a , b );
		return;
	}
	update( LEFT , lo , hi , type , val );
	update( RIGHT , lo , hi , type , val );
	T[ node ] = (T[ v1 ] + T[ v2 ])%MOD;
}
int main(){
	int n , Q;
	sc( n ) , sc( Q );
	REP( i , n ) sc( A[ i ] );
	
	build_tree( 0 , 0 , n - 1 );
	REP( i , 4 * N ) flag[ i ] = mp( 1LL , 0LL );
	REP( q , Q ){
		int t;
		sc( t );
		if( t == 4 ){
			int lo , hi;
			sc( lo ) , sc( hi );
			lo -- , hi --;
			assert( 0 <= lo && lo < n );
			assert( 0 <= hi && hi < n );
			printf( "%d\n" , (int)query( 0 , 0 , n - 1 , lo , hi ) );
		}else{
			int lo , hi , x;
			sc( lo ) , sc( hi ) , sc( x );
			lo -- , hi --;
			assert( 0 <= lo && lo < n );
			assert( 0 <= hi && hi < n );
			update( 0 , 0 , n - 1 , lo , hi , t , x );
		}
	}
}




