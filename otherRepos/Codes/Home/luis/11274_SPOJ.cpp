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

#define N 55
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n,m;
int A[ N ][ N ] ;//,M[ N ][ N ];
pair< int , pii >V[ N*N ];
int match[ N ] , vis[ N ] , used[ N ];
vi M[N];
bool dfs( int u )
{
	if( vis[u] )return 0;
	vis[u] = 1;
	FOR( v , M[u] )
		if( ( match[*v] == -1 || dfs( match[*v] ) ) )
		{
			match[*v] = u;
			used[u] = 1;
			return 1; 
		}
	return 0;
}
int bpm()
{
	//clr( match , -1 );
	int cnt = 0;
	REP( k  , n )
		if( !used[k] )
		{
			clr( vis , 0 );
			cnt += dfs( k );
		}
		else cnt++;
	return cnt;
}
int main()
{
	int tc;
	sc( tc );
	REP( t , tc )
	{
		sc( n );
		m = 0;
		REP( i ,  n )M[i].clear();
		REP( i , n )REP( j , n )sc( A[i][j] ) , V[m++] = mp( A[i][j] , pii( i , j ) );
		sort( V , V + m );
		int mini = INF;
		int lo = 0 , hi = 0;
		clr( M  , 0 );
		clr( match , -1 );
		clr( used , 0 );
		while( lo < m )
		{
			int BPM = bpm();
			while( hi < m && BPM < n )
			{
				M[ V[hi].se.fi ].pb( V[hi].se.se );
				hi++;
				BPM = bpm();
			}
			if( BPM == n )mini = min( mini , V[hi-1].fi - V[lo].fi );
			M[V[lo].se.fi].erase( M[V[lo].se.fi].begin() );//[ n + V[lo].se.se] = 0;
			used[ match[ V[lo].se.se ] ] = 0;
			match[ V[lo].se.se ] = -1;
			lo++;
		}
		printf( "%d\n" , mini );
	}
}


