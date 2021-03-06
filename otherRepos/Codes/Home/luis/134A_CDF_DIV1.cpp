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

#define N 1005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n;
int X[N] , Y[N];
int vis[N];
vector< vector< int > >adj;

void dfs( int node )
{
	vis[ node ] = 1;
	FOR( son , adj[ node ] )
		if( !vis[*son] )dfs( *son );
}
int main()
{
	while( cin >> n )
	{
		adj.clear();
		adj.resize( n );
		for( int i = 0 ; i < n ; ++i )
			cin >> X[i] >> Y[i];
		for( int i = 0 ; i < n ; ++i )
			for( int j = 0 ; j < n ; ++j )
				if( X[i] == X[j] || Y[i] == Y[j] )
					adj[i].pb( j );
		me( vis , 0 );
		int cnt = 0;
		for( int i = 0 ; i < n ; ++i )
			if( !vis[i] ) cnt++ , dfs( i );
		cout << --cnt << endl;
	}
}
