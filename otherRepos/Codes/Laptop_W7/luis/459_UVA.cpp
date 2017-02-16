#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
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

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

vvi adj;
vi vis;
string dummy , s;
int n;
bool ok = 0;
void dfs( int u )
{
	vis[ u ] = 1;
	FOR( v , adj[u] )
		if( !vis[*v] )dfs(*v);
}
int main()
{
	int tc;
	cin >> tc;
	getline( cin , dummy );
	while( tc-- )
	{
		string C;
		cin >> C;
		getline( cin , dummy );
		n = C[0] - 'A' + 1;
		adj.clear();
		adj.resize( n );
		while( 1 )
		{
			getline( cin , s );
			if( s.empty() )break;
			adj[s[0]-'A'].pb(s[1]-'A');
			adj[s[1]-'A'].pb(s[0]-'A');
		}
		int cnt = 0;
		vis = vi( n , 0 );
		REP( i , n )
			if( !vis[i] )
				dfs( i ),cnt++;
		if( ok )cout << endl;
		else ok = !ok;
		cout << cnt << endl;
	}
}


