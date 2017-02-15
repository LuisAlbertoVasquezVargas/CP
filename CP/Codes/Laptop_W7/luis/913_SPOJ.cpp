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

#define N 10005
#define M 14

using namespace std;

char s[ 10 ];
int n;
vector< pii > E[ N ];
int vis[ N ] , L[ N ] , parent[ N ] , D[ N ];
int rmq[ N ][ M + 1 ];

void dfs( int u )
{
	vis[ u ] = 1;
	FOR( v , E[ u ] )
		if( !vis[ v->fi ] )
		{
		 	L[ v->fi ] = L[ u ] + 1 , parent[ v->fi ] = u;
			D[ v->fi ] = D[ u ] + v->se;
			dfs( v->fi );
		}
}
void RMQ()
{
	REP( i , n )rmq[i][0] = parent[i];
	for( int k = 1 ; k <= M ; ++k )
		REP( i , n ) if( rmq[ i ][ k - 1 ] != -1 )
			rmq[ i ][ k ] = rmq[ rmq[ i ][ k - 1 ] ][ k - 1 ];
}
void init()
{
	REP( i ,  n )E[i].clear();
	clr( vis , 0 );
	clr( rmq , -1 );
}
void doit()
{
	dfs( 0 );
	RMQ();
}

int LCA( int x , int y )
{
	if( L[x] > L[y] )swap( x , y );
	int dif = L[y] - L[x];
	REP( k , M + 1 )if( (dif&(1<<k)) )
		y = rmq[ y ][ k ];
	if( y == x )return x;
	for( int k = M ; k >= 0 ; --k )
		if( rmq[ x ][ k ] != rmq[ y ][ k ] )
			x = rmq[ x ][ k ]  ,y = rmq[ y ][ k ];
	return parent[x];
}
int dist( int x , int y ){ return D[x] + D[y] - 2*D[ LCA( x , y ) ]; }
// k 0 based
int kth( int x , int y , int K )
{
	int lca = LCA( x , y );
	int dif = L[ x ] - L[ lca ];
	if( K <= dif )
	{
		REP( k , M + 1 ) if( (K&(1<<k) ) )x = rmq[ x ][ k ];
		return x;
	}
	dif = L[x] + L[y] - 2*L[ LCA( x , y ) ] - K;
	REP( k , M + 1 ) if( (dif&(1<<k) ) )y = rmq[ y ][ k ];
	return y;
}
int main()
{
	parent[ 0 ] = -1;
	int tc;
	sc( tc );
	bool ok = 0;
	while( tc -- )
	{
		if( ok )puts( "" );
		else ok = 1;
		sc( n );
		init();
		REP( i , n - 1 )
		{
			int x , y , w;
			scanf( "%d%d%d" , &x , &y , &w );
			x-- , y--;
			E[ x ].pb( mp( y , w ) );
			E[ y ].pb( mp( x , w ) );
		}
		doit();
		while( 1 )
		{
			scanf( "%s" , s );
			int x , y , k;
			if( s[1] == 'O' )break;
			scanf( "%d%d" , &x , &y );
			x-- , y--;
			if( s[0] == 'K' )
			{
				scanf( "%d" , &k );
				printf( "%d\n" , kth( x , y , k - 1 ) + 1 );
			}
			else printf( "%d\n" , dist( x , y ) );
		}
	}
}


