#include <bits/stdc++.h>

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

int n , m , tc , x , y , cnt;
vvi E , ET;
int vis[ N ];

void dfs( vvi &adj , int u )
{
	cnt++;
	vis[ u ] = 1;
	for( int j = 0 ; j < adj[u].size() ; ++j )
	{
		int v = adj[u][j];
		if( !vis[v] ) dfs( adj , v );
	}
}
int main()
{
	sc( tc );
	while( tc -- )
	{
		sc( n ) , sc( m );
		E.clear() , ET.clear();
		E.resize( n ) , ET.resize( n );
		REP( i , m )
		{
			sc( x ) , sc( y );
			x -- , y-- ;
			E[x].pb(y);
			ET[y].pb(x);
		}
		int ans = 0;
		REP( i , n )
		{
			me( vis , 0 );cnt = 0;
			dfs( E , i );
			int top = cnt;
			me( vis , 0 );cnt = 0;
			dfs( ET , i );
			int tail = cnt;
			if( top > (n+1)/2  || tail > (n+1)/2 )ans++;
		}
		printf( "%d\n" , ans );
	}
}


