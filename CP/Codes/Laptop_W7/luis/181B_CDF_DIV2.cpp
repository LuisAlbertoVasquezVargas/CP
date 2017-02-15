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

#define N 105
#define MOD 1000000007

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
#define test puts("test");

using namespace std;

int n , m;
vector< int >adj[N];
vector< int >C;
vector< vector< int > >T[4];
bool vis[N];
bool ok = 0;
void dfs( int node )
{
	vis[ node ] = 1;
	C.push_back( node + 1 );
	int nv = adj[node].size();
	for( int k = 0 ; k < nv ; ++k )
	{
		int son = adj[node][k];
		if( !vis[son] )dfs( son );
	}
}
int main()
{
	while( cin >> n >> m )
	{
		for( int i = 0 ; i < n ; ++i )
			adj[i].clear();
		for( int i = 0 ; i < 4 ; ++i )
			T[i].clear();
		ok = 1;
		me( vis , 0 );
		for( int i = 0 ; i < m ; ++i )
		{
			int x , y ;
			cin >> x >> y;
			x-- , y--;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		for( int i = 0 ; i < n ; ++i )
			if( !vis[i] )
			{
				dfs(i);
				if( C.size() > 3 )ok = 0;
				else T[C.size()].push_back(C);
				C.clear();
			}
		if( T[1].size() < T[2].size() ) ok = 0;
		if( ok == 0 )puts("-1");
		else
		{
			for( int i = 0 ; i < T[3].size() ; ++i )
				cout << T[3][i][0] << " " << T[3][i][1] << " " << T[3][i][2] << endl;
			for( int i = 0 ; i < T[2].size() ; ++i )
				cout << T[2][i][0] << " " << T[2][i][1] << " " << T[1][i][0] << endl;
			for( int i = T[2].size() ; i < T[1].size() ; i+= 3 )
				cout << T[1][i][0] << " " << T[1][i+1][0] << " " << T[1][i+2][0] << endl;
		} 
	}
}
