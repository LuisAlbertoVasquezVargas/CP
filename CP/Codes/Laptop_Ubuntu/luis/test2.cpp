#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define clr( t , val ) memset( t , val , sizeof( t ) )

typedef long long ll;

#define N 100005

#define v1 (node<<1) + 1
#define v2 (node<<1) + 2
#define med (( a + b )>>1)

#define LEFT v1 , a , med
#define RIGHT v2 , med + 1 , b  
#define JOIN T[ node ] = T[ v1 ] + T[ v2 ]

int n;
ll T[ 4*N ] , flag[ 4*N ]; //, A[ N ] ;
/*
void build_tree( int node , int a , int b )
{
	if( a == b )
	{
		T[ node ] = A[ a ];
		return;
	}
	build_tree( LEFT );
	build_tree( RIGHT );
	JOIN;
}*/
void push( int node , int a , int b )
{
	T[ node ] += ( b - a + 1LL )*flag[ node ];
	if( a != b )
	{
		flag[ v1 ] += flag[ node ];
		flag[ v2 ] += flag[ node ];
	}
	flag[ node ] = 0;
}
void update( int node , int a , int b , int lo , int hi , int val )
{
	push( node , a , b );
	if( lo > b || a > hi ) return;
	if( a >= lo && hi >= b ) {
		flag[ node ] = val;
		push( node , a , b );
		return;
	}
	update( LEFT , lo , hi , val ) , update( RIGHT , lo , hi , val );
	JOIN;
}

ll query( int node , int a , int b , int lo , int hi )
{
	push( node , a , b );
	if( a > hi || lo > b ) return 0;
	if( a >= lo && hi >= b ) return T[ node ];
	return query( LEFT , lo , hi ) + query( RIGHT , lo , hi );
}

int main()
{
	int cases , Q , op , x  , y , val ;
	sc( cases );
	while( cases -- )
	{
		clr( T , 0 ) , clr( flag , 0 );
		sc( n ) , sc( Q );
		while( Q-- )
		{
			sc( op );
			if( !op )
			{
				sc( x ) , sc( y ) , sc( val );
				x -- , y--;
				update( 0 , 0 , n - 1 , x , y , val );	
			}
			else
			{
				sc( x ) , sc( y );
				x-- , y-- ;
				cout << query( 0 , 0 , n - 1 , x , y ) << '\n';			
			} 
		}				
	}
// 0 update 1 query
}
