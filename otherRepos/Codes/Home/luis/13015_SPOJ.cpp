#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <cctype>

#define N 10005
#define M 1000006

using namespace std;

int n , Q , tc , num , op , u , v ;
int T[ 4*N ], flag[ 4*N ];
int A[ N ] ;
bool prime[ M + 5 ];

void sieve()
{
	for( int i = 0 ; i <= M ; ++i )
		prime[i] = 1;
	prime[ 0 ] = prime[ 1 ] = 0 ;
	for( int i = 2 ; i*i <= M ; ++i )
		if( prime[i] )
			for( int j = i*i ; j <= M ; j += i )
				prime[ j ] = 0;
}
void push( int node , int a , int b )
{
	int v1 = 2*node + 1 , v2 = 2*node + 2 , med = ( a + b )/2;	
	if( flag[ node ] )
	{
		T[ node ] = ( flag[ node ]==1?0:(b-a+1) );
		if( a != b )
		{
			flag[ v1 ] = flag[ v2 ] = flag[ node ];
		}
	}
	flag[ node ] = 0;
}
void build_tree( int node , int a , int b )
{
	flag[ node ] = 0;
	int v1 = 2*node + 1 , v2 = 2*node + 2 , med = ( a + b )/2;	
	if( a == b )
	{
		T[ node ] = A[a];
		return;	
	}
	build_tree( v1 , a , med );
	build_tree( v2 , med + 1 , b );
	T[ node ] = T[ v1 ] + T[ v2 ];
}
void update( int node , int a , int b , int x , int y , int isP )
{
	int v1 = 2*node + 1 , v2 = 2*node + 2 , med = ( a + b )/2;	
	push( node , a , b );
	if( x > b || a > y )return;
	if( a >= x && y >= b )
	{
		flag[ node ] = (isP == 1? 2:1);
		push( node , a , b );
		return;
	}
	update( v1 , a  , med , x , y , isP );
	update( v2 , med + 1 , b , x , y , isP );
	T[ node ] = T[ v1 ] + T[ v2 ];
}
int query( int node , int a , int b , int x , int y )
{
	int v1 = 2*node + 1 , v2 = 2*node + 2 , med = ( a + b )/2;	
	push( node , a , b );
	if( x > b || a > y )return 0;
	if( a >= x && y >= b )
		return T[ node ];
	return query( v1 , a , med , x , y ) + query( v2 , med + 1 , b , x , y );
}
int main()
{
	sieve();
	scanf( "%d" , &tc );
	for( int k = 0 ; k < tc ; ++k )
	{
		printf( "Case %d:\n" , k + 1 );
		scanf( "%d%d" , &n , &Q );
		for( int i = 0 ; i < n ; ++i )
		{
			scanf( "%d" , &num );
			A[ i ] = prime[ num ];	
		}
		build_tree( 0 , 0 , n - 1 );
		while( Q-- )
		{
			scanf( "%d" , &op );
			if( op == 0 )
			{
				scanf( "%d%d%d" , &u , &v , &num );
				u--,v--;				
				update( 0 , 0 , n - 1 , u , v , prime[ num ] );
			}
			else
			{
				scanf( "%d%d" , &u , &v );
				u--,v--;
				printf( "%d\n" , query( 0 , 0, n - 1 , u , v ) );						
			}
		}
	}
}
