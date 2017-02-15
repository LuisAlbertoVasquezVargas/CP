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

#define N (1<<17)

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int T[ 4 * N + 5 ];
int A[ 4 * N + 5 ];

#define NEUTRAL 0
#define v1 ( ( node << 1 ) + 1 )
#define v2 ( v1 + 1 )
#define med ( (a + b) >> 1 )
#define LEFT v1 , a , med
#define RIGHT v2 , med + 1 , b

void build_tree( int node , int a , int b , int flag ){
	if( a == b ){
		T[ node ] = A[ a ];
		return;
	}
	build_tree( LEFT , flag ^ 1 );
	build_tree( RIGHT , flag ^ 1 );
	if( !flag ) T[ node ] = T[ v1 ] ^ T[ v2 ];
	else T[ node ] = T[ v1 ] | T[ v2 ];
}
void update( int node , int a , int b , int x , int val , int flag ){
	if( x > b || a > x ) return;
	if( a == b ){
		T[ node ] = val;
		return;
	}
	update( LEFT , x , val , flag ^ 1 );
	update( RIGHT , x , val , flag ^ 1 );
	if( !flag ) T[ node ] = T[ v1 ] ^ T[ v2 ];
	else T[ node ] = T[ v1 ] | T[ v2 ];
}
int query( int node , int a ,  int b , int lo , int hi , int flag ){
	if( lo > b || a > hi ) return NEUTRAL;
	if( a >= lo && hi >= b ) return T[ node ];
	int L = query( LEFT , lo , hi , flag ^ 1 ) , R = query( RIGHT , lo , hi , flag ^ 1 );
	if( !flag ) return L ^ R;
	return L | R;
}
int main(){
	int n , m;
	while( sc( n ) == 1 ){
		int flag = n & 1;
		n = (1 << n);
		sc( m );
		REP( i , n ) sc( A[ i ] );	
		build_tree( 0 , 0 , n - 1 , flag );
		REP( i , m ){
			int pos , val;
			sc( pos ) , sc( val );
			pos --;
			update( 0 , 0 , n - 1 , pos , val , flag );
			printf( "%d\n" , query( 0 , 0 , n - 1 , 0 , n - 1 , flag ) );
		}	
	}	
}



