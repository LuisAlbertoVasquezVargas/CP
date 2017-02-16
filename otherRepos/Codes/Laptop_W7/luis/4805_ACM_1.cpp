#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vpii vector< pair< int , int > >
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
#define M 17

using namespace std;

int n;
vpii E[N];
int vis[ N ] , parent[ N ] , rmq[ N ][ M + 1 ] , L[ N ];
ll D[N];

void init()
{
	REP( i , n )E[i].clear();
	clr( vis , 0 );
	parent[0] = -1;
	clr( rmq , -1 );
}
void dfs( int u )
{
	vis[ u ] = 1;
	FOR( v , E[ u ] )
		if( !vis[ v->fi ] )
		{
			L[ v->fi ] = L[u] + 1;
			D[ v->fi ] = D[u] + v->se ;
			parent[ v->fi ] = u;
			dfs( v->fi );
		}
}
void RMQ()
{
	REP( i , n )rmq[i][0] = parent[i];
	for( int k = 1 ; k <= M ; ++k )
		REP( i , n )if( rmq[ i ][ k - 1 ] != -1 )
			rmq[ i ][ k ] = rmq[ rmq[ i ][ k - 1 ] ][ k - 1 ];
}
void doit()
{
	dfs( 0 );
	RMQ();
}
int lca( int x , int y )
{
	if( L[x] > L[y] )swap( x , y );
	int dif = L[y] - L[x];
	REP( k , M + 1 )
		if( ( dif & (1<<k) ) ) y = rmq[ y ][ k ];
	if( x == y )return x;
	REP( k , M + 1 )
		if( rmq[ x ][ k ] != rmq[ y ][ k ] ) 
			x = rmq[ x ][ k ] , y = rmq[ y ][ k ];
	return parent[ x ];
}
int main()
{
	while( sc( n ) == 1 && n )
	{
		init();
		REP( i , n - 1 )
		{
			int x , w;
			sc( x ) , sc( w );
			E[ x ].pb( mp( i + 1 , w ) );
			E[ i + 1 ].pb( mp( x , w ) );
		}
		doit();
		int Q;
		sc( Q );
		REP( i , Q )
		{
			int s , t;
			sc( s ) , sc( t );
			printf( "%lld%s" , D[s] + D[t] - 2*D[ lca( s , t ) ] , ((i+1==Q)?"\n":" ") );
		}
	}
}



