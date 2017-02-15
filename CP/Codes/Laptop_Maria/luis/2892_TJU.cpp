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

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()

#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vector<int> >
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

#define N 105
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , m , tc , x , y;
bool solve = 1;
int vis[ N ];
vvi adj;

void dfs( int u )
{
	vis[u] = 1;
	int nv = adj[u].size();
	REP( v , nv )
	{
		int son = adj[u][v];
		if( !vis[son] )dfs( son );
	}
}
int main()
{
	sc( tc );
	while( tc-- )
	{
		solve = 1;
		sc( n ) , sc( m );
		me( vis , 0 );
		adj.clear();
		adj.resize( n );
		vi ind( n );
		REP( i , m )
		{
			sc( x ) , sc( y );
			x-- , y--;
			adj[x].pb( y );
			ind[y]++;
		}
		REP( i , n )
		{
			int nv = adj[i].size();
			REP( j , nv )
			{
				me( vis , 0 );
				dfs( adj[i][j] );
				if( vis[i] ) solve = 0;
			}
		}
		cout << solve << '\n';
	}
}


