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

#define inf (1<<30)
#define eps 1e-5
#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )

#define N 10000005

using namespace std;

int n;
int T[ 4*N ] , flag[ 4*N ];
void push( int node , int a , int b )
{
	int v1 = 2*node + 1 , v2 = v1 + 1 ;	
	if( flag[ node ] )
	{
		T[ node ] = flag[ node ]*(b-a+1);
		if( a != b )
			flag[ v1 ] = flag[ v2 ] = flag[ node ];
	}	
	flag[ node ] = 0;
}

void update( int node , int a , int b , int x , int y  , int val )
{
	int v1 = 2*node + 1 , v2 = v1 + 1 , med = ( a + b )/2;	
	push( node , a , b);
	if( x > b || a > y )return;
	if( a >= x && b <= y )
	{
		flag[ node ] = val;
		push( node , a , b);
		return;	
	}
	update( v1 , a , med , x , y , val );
	update( v2 , med + 1 , b , x , y , val );
	T[ node ] = T[ v1 ] + T[ v2 ];	
}
int query( int node , int a , int b , int x , int y )
{
	int v1 = 2*node + 1 , v2 = v1 + 1 , med = ( a + b )>>1;	
	push( node , a , b );
	if( x > b || a > y )return 0;
	if( a >= x && b <= y )
		return T[ node ];
	return query( v1 , a , med , x , y ) + query( v2 , med + 1 , b , x , y );
}
int main()
{
	int tc , m = 10000000;
	sc( tc );
	while( tc-- )
	{
		sc( n );
		me( flag , 0 );
		me( T , 0 );
		for( int i = 0 ; i < n ; ++i )
		{
			int x , y;
			sc( x ) , sc( y );
			x-- , y--;
			update( 0 , 0 , m - 1 , x , y , i + 1 );
		}
		set< int >S;
		for( int i = 0 ; i < m ; ++i )
			if( query( 0 , 0 , m - 1 , i ,i ) )
				S.insert( query( 0 , 0 , m - 1 , i ,i ) );
		printf( "%d\n" , S.size() );
	}
}
