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

#define N 100005
#define M 16

using namespace std;

int n;
vi E[ N ];
int vis[ N ] , cnt[ N ] , parent[ N ] , rmq[ N ][ M + 1 ] , L[ N ] , ind[ N ];

int lca( int x , int y )
{
	if( L[y] < L[x] )swap( x , y );
	int dif = L[y] - L[x];
	REP( k , M + 1 )if( ( dif & (1<<k) ) ) y = rmq[ y ][ k ];
	if( x == y )return x;
	for( int k = M ; k >= 0 ; --k )if( rmq[ x ][ k ] != rmq[ y ][ k ] ) x = rmq[ x ][ k ] , y = rmq[ y ][ k ];
	return parent[x];
}
void init()
{
	REP( i , n ) E[i].clear();
	parent[0] = -1;
	clr( rmq , -1 );
	clr( vis , 0 );
	clr( cnt , 0 );
	clr( ind , 0 );
}
void dfs( int u )
{
	vis[ u ] = 1;
	FOR( v , E[u] )
		if( !vis[ *v ] ) parent[*v] = u , L[*v] = L[u] + 1 , dfs( *v );
}
void RMQ()
{
	REP( i , n )rmq[i][0] = parent[i];
	for( int k = 1 ; k <= M ; ++k )REP( i , n )
		if( rmq[i][k-1] != -1 )
			rmq[i][k] = rmq[ rmq[i][k-1] ][k-1];
}
void doit()
{
	REP( i , n )
		if( !ind[i] )
		{
			dfs( i );
			break;
		}
	RMQ();
}
int main()
{
	while( sc( n ) == 1 )
	{
		init();
		REP( i , n )
		{
			int u , m , v;
			scanf( "%d:(%d)" , &u , &m );
			u-- ;
			REP( i , m )
			{
				sc( v ) , v-- ;
				E[ u ].pb( v );
				ind[ v ]++;
			}
		}
		doit();
		int Q , x , y ;
		sc( Q );
		while( Q -- )
		{
			scanf( " (%d %d) " , &x , &y );
			x-- , y--;
			cnt[lca( x , y )]++;
		}
		REP( i , n )
			if( cnt[i] )
				printf( "%d:%d\n" , i + 1 , cnt[i] );
	}
}


