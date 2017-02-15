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

vector< vi > adj,ADJ,memo;

void dfs( int node , int parent = -1 )
{
	FOR( u , adj[node] )
		if( *u != parent )
			dfs( *u , node ) , ADJ[node].pb( *u );
}
// in dp parent means parent is taked ?
int dp( int node , bool parent )
{
	int &dev = memo[node][parent];
	if( dev == -1 )
	{
		if( parent )
		{
			int sum = 1 , sum2 = 0;
			FOR( u , ADJ[node] )
				sum += dp( *u , 1 ) , sum2 += dp( *u , 0 );
			dev = min( sum , sum2 );
		}
		else
		{
			int sum = 1 ;
			FOR( u , ADJ[node] )
				sum += dp( *u , 1 );
			dev = sum;
		}
	}
	return dev;
}
int main()
{
	sync
	int n;
	while( cin >> n )
	{
		if( n == 0 )break;
		adj.clear();
		adj.resize( n );
		ADJ.clear();
		ADJ.resize( n );
		for( int i = 0 ; i < n ; ++i )
		{
			int m;
			cin >> m;
			for( int j = 0 ; j < m ; ++j )
			{
				int x;
				cin >> x;
				x--;
				adj[i].pb(x);	
			}
		}
		dfs( 0 );
		memo.clear();
		memo = vector< vi >( n , vi( 2 , -1 ) );
		cout << max( 1 , dp( 0 , 1 ) ) << endl;	
	}
}
