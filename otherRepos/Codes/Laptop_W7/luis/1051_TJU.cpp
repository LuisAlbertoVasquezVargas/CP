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

#define N 100005
#define M 16

using namespace std;

int n;
vi E[ N ];
int vis[ N ] , cnt[ N ] , parent[ N ] , rmq[ N ][ M + 1 ] , L[ N ] , ind[ N ];

int lca( int x , int y )
{
	if( L[y] < L[x] )swap( x , y );
	int dif = L[y] - L[x];
	REP( k , M + 1 )if( ( dif & (1<<k) ) ) y = rmq[ y ][ k ];
	if( x == y )return x;
	for( int k = M ; k >= 0 ; --k )if( rmq[ x ][ k ] != rmq[ y ][ k ] ) x = rmq[ x ][ k ] , y = rmq[ y ][ k ];
	return parent[x];
}
void init()
{
	REP( i , n ) E[i].clear();
	parent[0] = -1;
	clr( rmq , -1 );
	clr( vis , 0 );
	clr( cnt , 0 );
	clr( ind , 0 );
}
void dfs( int u )
{
	vis[ u ] = 1;
	/*FOR( v , E[u] )
		if( !vis[ *v ] ) parent[*v] = u , L[*v] = L[u] + 1 , dfs( *v );*/
	for( int i = 0 ; i < E[u].size() ; ++i )
	{
		int v = E[u][i];
		if( !vis[ v ] ) parent[v] = u , L[v] = L[u] + 1 , dfs( v );
	}
}
void RMQ()
{
	REP( i , n )rmq[i][0] = parent[i];
	for( int k = 1 ; k <= M ; ++k )REP( i , n )
		if( rmq[i][k-1] != -1 )
			rmq[i][k] = rmq[ rmq[i][k-1] ][k-1];
}
void doit()
{
	REP( i , n )
		if( !ind[i] )
		{
			dfs( i );
			break;
		}
	RMQ();
}
int main()
{
	while( sc( n ) == 1 )
	{
		init();
		REP( i , n )
		{
			int u , m , v;
			scanf( "%d:(%d)" , &u , &m );
			u-- ;
			REP( i , m )
			{
				sc( v ) , v-- ;
				E[ u ].pb( v );
				ind[ v ]++;
			}
		}
		doit();
		int Q , x , y ;
		sc( Q );
		while( Q -- )
		{
			scanf( " (%d,%d) " , &x , &y );
			x-- , y--;
			cnt[lca( x , y )]++;
		}
		REP( i , n )
			if( cnt[i] )
				printf( "%d:%d\n" , i + 1 , cnt[i] );
	}
}


