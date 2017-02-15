#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define N 1000000
#define INF (1<<20)

typedef long long ll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int , int > pii;


#define v1 ((node<<1)+1)
#define v2 (v1+1)
#define med ((a+b)>>1)
#define LEFT v1 , a , med
#define RIGHT v2 , med + 1 , b

struct Node{
	 ll sum , maxi , flag;
	 Node(){//neutral
	 	sum = maxi = flag = 0;
	 }
} T[ 4 * N + 5 ];

Node operator +( const Node &a , const Node &b ){
	Node c;
	c.sum = a.sum + b.sum;
	c.maxi = max( a.maxi , b.maxi );
	return c;
}

void push( int node , int a , int b ){
	if( T[ node ].flag == 0 ) return;
	T[ node ].sum += T[ node ].flag * ( b - a + 1LL );
	T[ node ].maxi += T[ node ].flag;
	if( a != b ){
		T[ v1 ].flag += T[ node ].flag;
		T[ v2 ].flag += T[ node ].flag;
	}
	T[ node ].flag = 0;
}
Node query( int node , int a , int b , int lo , int hi ){
	push( node , a , b );
	if( lo > b || a > hi ) return Node();
	if( a >= lo && hi >= b ) return T[ node ];
	return query( LEFT , lo , hi ) + query( RIGHT , lo , hi );
}
void update( int node , int a , int b , int lo , int hi , int val ){
	push( node , a , b );
	if( lo > b || a > hi ) return;
	if( a >= lo && hi >= b ) {
		T[ node ].flag = val;
		push( node , a , b );
		return;
	}
	update( LEFT , lo , hi , val );
	update( RIGHT , lo , hi , val );
	T[ node ] = T[ v1 ] + T[ v2 ];
}
int L[ N + 5 ] , R[ N + 5 ] , C[ N + 5 ];
int main(){
	int n;
	sc( n );
	REP( i , n ){
		int lo , hi , x;
		sc( lo ) , sc( hi ) , sc( x );
		lo -- , hi --;
		L[ i ] = lo , R[ i ] = hi , C[ i ] = x;
		update( 0 , 0 , N - 1 , lo , hi , x );
	}
	int Q;
	sc( Q );
	REP( i , Q ){
		int t;
		sc( t );
		if( t == 1 ){
			int lo , hi;
			sc( lo ) , sc( hi );
			lo -- , hi --;
			Node nodo = query( 0 , 0 , N - 1 , lo , hi );
			cout << nodo.sum << " " << nodo.maxi << endl;
			//printf( "%lld\n" , query( 0 , 0 , N - 1 , lo , hi ).maxi );
		}else{
			int id , lo , hi , x;
			sc( id ) , sc( lo ) , sc( hi ) , sc( x );
			id -- , lo -- , hi --;
			update( 0 , 0 , N - 1 , L[ id ] , R[ id ] , -C[ id ] );
			L[ id ] = lo , R[ id ] = hi , C[ id ] = x;
			update( 0 , 0 , N - 1 , L[ id ] , R[ id ] , +C[ id ] );
		}
	}
}


