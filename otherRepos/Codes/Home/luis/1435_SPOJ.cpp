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

#define N 100000

using namespace std;

int n , x , y ;
vector< int > adj[N],adj1[N];
bool vis[N];
int memo[N][2];

void dfs( int node )
{
	vis[ node ] = 1 ;
	int nv = adj1[ node ].size();
	for( int k = 0 ; k < nv ; ++k )
	{
		int son = adj1[ node ][k] ;
		if( vis[ son ] )continue;
		adj[node].push_back(son);
		dfs( son );
	}
}
int dp( int node , int last )
{
	int &dev = memo[node][last];
	if( dev == -1 )
	{	
		int nv = adj[ node ].size();
		int op1 = 1 , op2 = 0;
		for( int k = 0 ; k < nv ; ++k )
		{
			int son = adj[ node ][k];
			op1 += dp( son , 1 );
			op2 += dp( son , 0 );
		}
		dev = op1;
		if( last ) 
			dev = min( dev , op2 );
	}
	return dev;
}
int main()
{
	while( scanf( "%d" , &n) == 1 )
	{
		for( int i = 0 ; i < n ; ++i )
			adj1[i].clear(),adj[i].clear();		
		for( int i = 0 ; i < n - 1 ; ++i )
		{
			scanf( "%d%d",&x,&y );
			x--;y--;
			adj1[x].push_back(y);
			adj1[y].push_back(x);			
		}
		memset( vis , 0 , sizeof( vis ) );
		dfs(0);
		memset( memo , -1 , sizeof( memo ) );
		printf( "%d\n" , dp( 0, 1 ) );
	}
}
