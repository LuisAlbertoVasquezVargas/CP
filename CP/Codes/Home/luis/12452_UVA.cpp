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

using namespace std;

int n;
int memo[N][2];
vector< int >adj[N],adj2[N];
int vis[ N ];

void dfs( int node )
{
	vis[ node ] = 1;
	int nv = adj2[ node ].size();
	for( int i = 0 ; i < nv ; ++i )
	{
		int son  = adj2[ node ][ i ];
		if( !vis[ son ] )
		{
			adj[ node ].push_back( son );
			dfs( son );	
		}
	}	
}
int dp( int node , int last )
{
	int &dev = memo[ node ][ last ];
	if( dev == -1 )
	{
		dev = (1<<30);
		int nv = adj[ node ].size();
		int nothing = 0, all = 0;		
		for( int k = 0 ; k < nv ; ++k )
		{
			int son = adj[ node ][ k ];
			nothing += dp( son , 0 );
			all += dp( son , 1 );			
		}
		if( last == 0 )
		{
			dev = min( dev , 100 + nothing );
			for( int k = 0 ; k < nv ; ++k )
			{
				int son = adj[ node ][ k ];
				int op1 = 175 + nothing - dp( son , 0 ) + dp( son , 1 );
				dev = min( dev , op1 );
			}
			dev = min( dev , 500 + all );
		}
		else
		{
			dev = min( dev , nothing );
			for( int k = 0 ; k < nv ;  ++k )
			{
				int son = adj[ node ][ k ];
				int op1 = 100 + nothing  - dp( son , 0 ) + dp( son , 1 );
				dev = min( dev , op1 );	
			}
			for( int k = 0 ; k < nv ; ++k )
				for( int K = k + 1 ; K < nv ; ++k )
				{
					int son1 = adj[ node ][ k ], son2 = adj[ node ][ K ];
					int op2 = 175 + nothing - dp( son1 , 0 ) + dp( son1 , 1 ) - dp( son2  , 0 ) + dp( son2 , 1 );
					dev = min( dev , op2 );
				}
			dev = min( dev , 500 + all );
 		}
	}
	return dev;	
}
int main()
{
	int tc;
	cin >> tc;
	while( tc-- )
	{
		cin >> n;
		for( int i = 0 ; i < n ; ++i )
			adj[i].clear(),adj2[i].clear();
		memset( vis , 0 , sizeof( vis ) );		
		memset( memo , -1 , sizeof( memo ) );				
		for( int i = 0 ; i < n - 1 ; ++i )
		{
			int u , v ;
			scanf( "%d%d" , &u , &v );
			adj2[ u ].push_back( v );
			adj2[ v ].push_back( u );			
		}
		dfs( 0 );
		puts( "test" );
		for( int k = 0 ; k < n ; ++k )
			dp( n - k - 1 , 0 ),dp( n - k - 1 , 1 );
		printf( "$%d\n" , dp( 0 , 1 ) );
	}
}
