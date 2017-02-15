#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define sc( x ) scanf( "%d" , &x )

#define N 50005 
#define INF (1<<29)

#define v1 ( ( node << 1) + 1 )
#define v2 ( v1 + 1 )
#define med ( ( a + b ) >> 1 )
#define LEFT v1 , a , med
#define RIGHT v2 , med + 1 , b

struct Node{
	int best , der , izq , sum;
	Node(){
		sum = 0;
		izq = der = best = -INF;
	}
	Node( int val ): best( val ) , der( val ) , izq( val ) , sum( val ) {};
} T[ 4*N ] , A[ N ] , NEUTRAL;
Node operator +( const Node &a , const Node &b ){
	Node ans;
	ans.sum = a.sum + b.sum;
	ans.der = max( b.der , b.sum + a.der );
	ans.izq = max( a.izq , a.sum + b.izq );
	ans.best = max( a.best , b.best );
	ans.best = max( ans.best , a.der + b.izq );
	return ans;
}
void build_tree( int node , int a , int b ){
	if( a == b ){
		T[ node ] = Node( A[ a ] );
		return;
	}
	build_tree( LEFT );build_tree( RIGHT );
	T[ node ] = T[ v1 ] + T[ v2 ];
}
void update( int node , int a , int b , int x , int val ){
	if( x > b || a > x ) return;
	if( a == b ){
		T[ node ] = Node( val );
		return;
	}
	update( LEFT , x , val );update( RIGHT , x , val );
	T[ node ] = T[ v1 ] + T[ v2 ];
}
Node query( int node , int a , int b , int lo , int hi ){
	if( lo > b || a > hi ) return NEUTRAL;
	if( a >= lo && hi >= b ) return T[ node ];
	return query( LEFT , lo , hi ) + query( RIGHT , lo , hi );
}

int n;
int main()
{
	sc( n );
	int x;
	REP( i , n ) sc( x ) , A[ i ] = Node( x );
	build_tree( 0 , 0 , n - 1 );		
	int Q;
	sc( Q );
	while( Q-- )
	{
		int x , y;
		sc( x ) , sc( y );
		x-- , y--;
		Node p = query( 0 , 0 , n - 1 , x , y );
		printf( "%d\n" , p.best );
	}
}
