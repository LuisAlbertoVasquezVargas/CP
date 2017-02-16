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
using namespace std;
 
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

int c;
int n,Q,x,y,op;

int main()
{
      scanf( "%d" , &n );
      for( int i = 0 ; i < n ; ++i )
            scanf( "%d" , &c ) , A[ i ] = Node( c );
      build_tree( 0 , 0 , n - 1 );
      scanf( "%d" , &Q );
      while( Q-- )
      {
            scanf( "%d%d%d" , &op , &x , &y );
            x--;y--;
            if( op == 0 )
                  update( 0 , 0 , n - 1 , x , y + 1 );
            else  printf( "%d\n" , query( 0 , 0 , n - 1 , x , y ).best );
      }
}
