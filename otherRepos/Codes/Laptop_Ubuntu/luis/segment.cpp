#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define N 50000
#define INF (1e9)
int n;
int A[ N + 5 ];

#define med ((a+b)>>1)
#define v1 ((node<<1)+1)
#define v2 (v1+1)
#define LEFT v1 , a , med
#define RIGHT v2 , med + 1 , b
struct Node{
	int best , L , R , S;
	Node(){
		L = R = best = -INF;
		S = 0;
	}
	Node( int val ){ best = S = L = R = val; }
	Node( int best , int L , int R , int S ) : best( best ) , L( L ) , R( R ) , S( S ) {}
}T[ 4*N ];
Node operator +( const Node &a , const Node &b ){
	Node c;
	c.S = a.S + b.S;
	c.L = max( a.L , a.S + b.L );
	c.R = max( b.R , b.S + a.R );
	c.best = max( a.best , b.best );
	c.best = max( c.best , a.R + b.L );
	return c;
}
void build_tree( int node = 0 , int a = 0 , int b = n - 1 ){
	if( a == b ){
		T[ node ] = Node( A[ a ] );
		return;
	}
	build_tree( LEFT ) , build_tree( RIGHT );
	T[ node ] = T[ v1 ] + T[ v2 ];
}
Node query( int node , int a , int b , int lo , int hi ){
	if( lo > b || a > hi ) return Node();
	if( a >= lo && hi >= b ) return T[ node ];
	return query( LEFT , lo , hi ) + query( RIGHT , lo , hi );
}
Node query( int x , int y ){ return query( 0 , 0 , n - 1 , x , y ); }

int main(){
	int Q , x , y ;
	sc( n );
	REP( i , n ) sc( A[ i ] );
	build_tree();
	sc( Q );
	REP( q , Q ){
		sc( x ) , sc( y );
		x -- , y --;
		Node u = query( x , y );
		printf( "%d\n" , u.best );
	}
}

