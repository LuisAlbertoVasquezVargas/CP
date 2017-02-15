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

int n , m , maxi , ind;
char s[20] , t[20];
vvi adj;
vi vis;
vi T;
void dfs( int u )
{
	vis[u] = 1;
	if( maxi < T[u] )
		maxi = T[u] , ind = u;
	FOR( v , adj[u] )
		if( !vis[*v] )
			dfs( *v );
}
int main()
{
	while( scanf( "%d%d" , &n , &m ) == 2 )
	{
		if( !n )break;
		vector< string >ID( n );
		T.resize( n );
		REP( i , n ) scanf( "%s%d", s , &T[i] ),ID[i] = string( s );
		map< string , int >Id;
		REP( i , n )Id[ ID[i] ] = i;
		adj.clear();
		adj.resize( n );
		vis.clear();
		vis.resize( n );
		while( m-- )
		{
			scanf( "%s%s" , s , t );
			int i = Id[ string(s) ] , j = Id[ string(t) ];
			adj[i].pb(j) , adj[j].pb(i);
		}
		vector< string > ans;
		REP( i , n )
			if( !vis[i] )
			{
				ind = -1;
				maxi = 0;
				dfs( i );
				ans.pb( ID[ind] );
			}
		sort( all( ans ) );
		FOR( o , ans )
			cout << *o << endl;
	}
}


