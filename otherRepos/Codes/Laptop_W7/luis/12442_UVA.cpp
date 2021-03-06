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
#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , t = 0 , tc;
vi in , out , vis , lvl ;
vector< vi >adj;
void dfs( int node )
{
	vis[ node ] = 1;
	lvl[ node ] = 0;
	FOR( o , adj[node] )
		if( vis[*o] )
			lvl[ node ] = max( lvl[ node ] , 1 + lvl[*o] );
		else dfs( *o );
}
void doit()
{
	for( int i = 0 ; i < n ; ++i )
		if( !vis[i] )
			dfs( i ),cout << i << endl;
	int ans = max_element( all( lvl ) ) - lvl.begin();
	cout << "Case " << ++t << ": " << ++ans << endl;
}
int main()
{
	cin >> tc;
	while( tc-- )
	{	
		cin >> n;
		in = out = vis = vi( n , 0 );
		lvl = vi( n , -1 );
		adj.clear();
		adj.resize( n );
		for( int i = 0 ; i < n ; ++i )
		{
			int x , y;
			cin >> x >> y;
			x-- , y--;	
			adj[x].pb( y );
			in[y]++;
			out[x]++;
		} 
		doit();
	}
}
