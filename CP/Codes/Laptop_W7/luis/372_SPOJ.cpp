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

#define N 50005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n;
vector< vector< pair< int , int > > >G;


int Djstra( int ini , bool ok )
{
	vi D(n, INF); 
	priority_queue<pii,vector<pii>, greater<pii> > Q; 
	D[ ini ] = 0;
	Q.push( mp(0,ini) );
	
	while(!Q.empty()) 
	{
		pii top = Q.top();
		Q.pop();
		int v = top.se, d = top.fi;
		if(d <= D[v]) 
		{
			FOR(it,G[v]) 
			{
				int v2 = it->fi, cost = it->se;
				if(D[v2] > D[v] + cost) 
				{
					D[v2] = D[v] + cost;
					Q.push( mp(D[v2], v2) );
				}
			}
		}
	}
	int ind = max_element( all(D) ) - D.begin();
	if( !ok )
		return ind;
	return D[ind];
}
int main()
{
	int tc;
	cin >> tc;
	while( tc -- )
	{
		G.clear();
		cin >> n;
		G.resize(n);
		for( int i = 0 ; i + 1 < n ; ++i )
		{
			int u , v , w;
			cin >> u >> v >> w;	
			u--,v--;
			G[u].pb( mp( v , w ) );
			G[v].pb( mp( u , w ) );
		}
		int Ind = Djstra( 0 , 0 );
		cout << Djstra( Ind , 1 ) << endl;
	}
}
