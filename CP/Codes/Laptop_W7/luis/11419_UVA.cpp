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
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 1003
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , m , t , sz;
int vis[ N ] , match[ N ] , V[ N ];
vi M[ N ];

bool dfs( int u )
{
	if( vis[u] )return 0;
	vis[u] = 1;
	FOR( v , M[u] )
		if( match[*v] == -1 || dfs( match[*v] ) )
		{
			match[*v] = u;
			return 1;
		}
	return 0;
}
int bpm()
{
	clr( match , -1 );
	int ans = 0;
	REP( i , n )
		clr( vis , 0 ) , ans += dfs( i );
	return ans;
}
int main()
{	
	while( scanf( "%d%d%d" , &n , &m , &t ) == 3 )
	{
		if( !n )break;
		REP( i , n )M[i].clear();
		REP( i , t )
		{
			int x , y;
			scanf( "%d%d" , &x , &y );
			x-- , y--;
			M[x].pb( y );
		}
		int ans = bpm();
		printf( "%d" , ans );
		sz = 0;
		for( int i = 0 ; i < m ; ++i )
			if( match[i] != -1 )
				V[sz++] = match[i];
		for( int i = 0 ; i < sz ; ++i )
			printf( " r%d" , V[i] + 1 );
		puts("");	
	}
}


