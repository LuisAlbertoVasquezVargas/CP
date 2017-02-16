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

#define N 5005
#define M 13

using namespace std;

int n;
vi E[ N ];
int vis[ N ] , L[ N ] , pa[ N ], rmq[ N ][ M + 1 ];

void init()
{
	REP( i , n )E[i].clear();
	clr( vis , 0 );
	clr( rmq , -1 );
	pa[ 0 ] = -1;
}
void dfs( int u )
{
	vis[ u ] = 1;
	FOR( v , E[u] )
		if( !vis[ *v ] )
			L[ *v ] = L[ u ] + 1 , pa[ *v ] = u , dfs( *v ); 
}
void RMQ()
{
	REP( i , n )rmq[ i ][ 0 ] = pa[ i ];
	for( int k = 1 ; k <= M ; ++k )
		REP( i , n ) if( rmq[ i ][ k - 1 ] != -1 )
			rmq[ i ][ k ] = rmq[ rmq[ i ][ k - 1 ] ][ k - 1 ];
}
void doit()
{
	dfs( 0 );
	RMQ();
}
int LCA( int x , int y )
{
	if( L[x] > L[y] )swap( x , y );
	int dif = L[ y ] - L[ x ];
	REP( k , M + 1 ) 
		if( ( dif & ( 1<<k ) ) ) y = rmq[ y ][ k ];
	if( x == y )return x;
	for( int k = M ; k >= 0 ; --k )
		if( rmq[ x ][ k ] != rmq[ y ][ k ] )
			x = rmq[ x ][ k ] , y = rmq[ y ][ k ];
	return pa[ x ];
}
int kth( int x , int y , int K , int lca , int dist )
{
	int dif = L[ x ] - L[ lca ];
	if( K <= dif )
	{
		REP( k , M + 1 )
			if( ( K & ( 1 << k ) ) ) x = rmq[ x ][ k ];
		return x;
	}
	dif = dist - K;
	REP( k , M + 1 )
		if( ( dif & ( 1 << k ) ) ) y = rmq[ y ][ k ];
	return y;
}
int main()
{
	while( sc( n ) == 1 && n )
	{
		init();
		REP( i , n - 1 )
		{
			int x , y;
			sc( x ) , sc( y );
			x-- , y--;
			E[ x ].pb( y );
			E[ y ].pb( x );
		}
		doit();
		int Q;
		sc( Q );
		while( Q -- )
		{
			int x , y;
			sc( x ) , sc( y );
			x -- , y--;
			if( L[x] > L[y] )swap( x , y );
			int lca = LCA( x , y );
			int dist = L[ x ] + L[ y ] - (L[ lca ]<<1);
			int distDiv2 = dist>>1;
			int med = kth( x , y , distDiv2 , lca , dist );
			if( dist&1 )
			{
				int med2 = kth( x , y , distDiv2 + 1 , lca , dist );
				if( med > med2 )swap( med , med2 );
				printf( "The fleas jump forever between %d and %d.\n" , med + 1 , med2 + 1 );
			}
			else printf( "The fleas meet at %d.\n", med + 1 );
		}
	}
}


