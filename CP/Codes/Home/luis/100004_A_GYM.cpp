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
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

ll n , mini , sum , temp ;
ll C[N];
int vis[N];
vector< vector< pair<int,int> > >adj , ADJ;

void dfs( int node , int parent )
{
	vis[ node ] = 1;
	FOR( son , adj[node] )
		if( (*son).first != parent && !vis[(*son).first] )
			ADJ[node].pb(*son),dfs( (*son).first , node );
}
void DFS( int node )
{
	vis[node] = 1;
	mini = min( mini , sum - temp + C[node] );	
	FOR( son , ADJ[node] )
		if( !vis[(*son).first] )
		{
			temp += (*son).second;
			DFS( (*son).first );
			temp -= (*son).second;
		}

}
int main()
{
	cin >> n;
	adj.resize( n + 1 );
	ADJ.resize( n + 1 );
	for( int i = 0 ; i <= n ; ++i )
		cin >> C[i] ;
	sum = 0;
	for( int i = 0 ; i < n ; ++i )
	{
		int x , y , w;
		cin >> x >> y >> w;
		sum += 2LL*w;
		adj[x].pb( make_pair(y,w) );
		adj[y].pb( make_pair(x,w) );
	}
	me( vis, 0 );
	dfs( 0 , -1 );
	me( vis, 0 );
	mini = 1LL<<60;
	temp = 0;
	DFS( 0 );
	cout << mini << endl;
}
