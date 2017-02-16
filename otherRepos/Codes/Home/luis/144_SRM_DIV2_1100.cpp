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
#define N 50

using namespace std;

int memo[ N ] ,vis[ N ] ,dist[ N ][ N ];
vector< int >adj[ N ] , adj2[ N ];
int dp( int node )
{
	int &dev = memo[ node ];
	if( dev == -1 )
	{
		int nv = adj[node].size();
		dev = 0;
		for( int k = 0 ; k < nv ; ++k )
		{
			int son = adj[ node ][ k ];
			dev = max( dev , dist[node][son] + dp( son ) );
		}
	}
	return dev;
}
void dfs( int node )
{
	vis[ node ] = 1;
	int nv = adj2[ node ].size();
	for( int k = 0 ; k < nv ; ++k )
	{
		int son = adj2[ node ][ k ];
		if( !vis[ son ] )
		{
			adj[ node ].push_back( son );
			dfs( son );
		}
	}
}
class PowerOutage {
public:
	int estimateTimeOut(vector <int> U, vector <int> V, vector <int> W ) {
		memset( memo , -1 , sizeof( memo ) );
		memset( vis , 0 , sizeof( vis ) );
		int nv = U.size();
		for( int k = 0 ; k < nv ; ++k )
		{
			adj2[ U[k] ].push_back( V[k] ), adj2[ V[k] ].push_back( U[ k ] );
			dist[U[k]][V[k]] = dist[V[k]][U[k]] = W[k];
		}
		dfs( 0 );
		return 2*accumulate( W.begin() , W.end() , 0 ) - dp( 0 );
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
