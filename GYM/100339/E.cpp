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

#define test() cout << "hola q hace" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef vector< int > vi;

#define N 200005
#define v1 ( ( node << 1 ) + 1 )
#define v2 ( v1 + 1 )
#define med ( (a + b) >> 1 )
#define LEFT v1 , a , med
#define RIGHT v2 , med + 1 , b

int A[ N + 5 ];
int T[ 4 * N + 5 ];

void build_tree( int node , int a , int b ){
	if( a == b ){
		T[ node ] = A[ a ];
		return;
	}
	build_tree( LEFT );build_tree( RIGHT );
	T[ node ] = min( T[ v1 ] , T[ v2 ] );
}
void update( int node , int a , int b , int x , int val ){
	if( x > b || a > x ) return;
	if( a == b ){
		T[ node ] = val;
		return;
	}
	update( LEFT , x , val );update( RIGHT , x , val );
	T[ node ] = min( T[ v1 ] , T[ v2 ] );
}
int query( int node , int a ,  int b , int lo , int hi ){
	if( lo > b || a > hi ) return INT_MAX;
	if( a >= lo && hi >= b ) return T[ node ];
	return min( query( LEFT , lo , hi ) , query( RIGHT , lo , hi ) );
}

int main(){
	freopen( "nice.in" , "r" , stdin );
	freopen( "nice.out" , "w" , stdout );
	int n , K;
	while( sc( n ) == 1 ){
		sc( K );
		int cnt = 0;
		bool possible = 1;
		clr( A , 0 );
		build_tree( 0 , 0 , n );
		REP( i , n ){
			int x;
			sc( x );
			A[ x ]++;
			update( 0 , 0 , n , x , A[ x ] );
			if( query( 0 , 0 , n , 0 , x - 1 ) < A[ x ] - K ) possible = 0;
			if( !possible ) continue;
			cnt ++;
		}
		printf( "%d\n" , cnt );
	}
}



