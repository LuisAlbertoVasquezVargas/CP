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

#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define sc(x) scanf("%d",&x)
#define clr(t,val) memset( t , val , sizeof(t) )

#define N 10005

using namespace std;

int n;
vi E[ N ];
int vis[ N ] , L[ N ] , parent[ N ];
int rmq[ N ][ 21 ];

void dfs( int u )
{
	vis[ u ] = 1;
	for( int i = 0  ; i < E[ u ].size() ; ++i )
	{
		int v = E[ u ][ i ];
		if( !vis[ v ] ) parent[ v ] = u , L[ v ] = L[ u ] +  1 , dfs( v );
	}
}
void RMQ()
{
	REP( i , n ) rmq[i][0] = parent[i];
	for( int k = 1 ; k <= 20 ; ++k )
		REP( i , n ) if( rmq[i][k-1] != -1 )
			rmq[i][k] = rmq[ rmq[i][k-1] ][k-1];
}
void init()
{
	REP( i , n )E[i].clear();
	clr( vis ,  0 );
	clr( parent , -1 );
	clr( rmq , -1 );
}
void doit()
{
	dfs( 0 );
	RMQ();
}
int LCA( int x , int y )
{
	if( L[y] < L[x] )swap( x , y );
	int dif = L[y] - L[x];
	REP( k , 20 ) if( (dif&(1<<k)) ) y = rmq[y][k];
	if( y == x )return x;
	for( int k = 20 ; k >= 0 ; --k )
		if( rmq[x][k] != rmq[y][k] ) x = rmq[x][k] , y = rmq[y][k];
	return parent[x];
}
int main()
{
	int tc;
	sc( tc );
	while( tc -- )
	{
		sc( n );
		init();
		REP( i , n - 1 )
		{
			int x , y;
			scanf( "%d%d" , &x , &y );
			E[ x ].pb( y );
			E[ y ].pb( x );
		}
		doit();
		int Q;
		sc( Q );
		while( Q-- )
		{
			int x , y;
			scanf( "%d%d" , &x , &y );
			int lca = LCA( x , y );
			if( x == y )puts( "No" );
			else puts( x==lca?"Yes":"No" );
		}
		puts( "" );
	}
}


