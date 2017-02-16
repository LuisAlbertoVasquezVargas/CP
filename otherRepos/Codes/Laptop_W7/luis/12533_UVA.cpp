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
#define M 17

using namespace std;

int n;
vi E[ N ];
int G[ N ];
int id[ N ] , VisComp[ N ];
int vis[ N ];
int found;
int nSuperNodes;
int parentDFS[ N ];
int idSuperNodes[ N ] , SZ[ N ] , Time[ N ] ;
//
int rama[ N ];
///
int PARENT[ N ] , VIS[ N ] , L[ N ];
int rmq[ N ][ M + 5 ];

void init()
{
	REP( i , n ) E[ i ].clear();
	REP( i , n ) id[ i ] = i;
	clr( VisComp , 0 );
	clr( vis , 0 );
	nSuperNodes = 1;
	clr( parentDFS , -1 );
	clr( idSuperNodes , 0 );
	clr( SZ , 0 );
	clr( Time , 0 );
	//
	clr( PARENT , -1 );
	clr( VIS , 0 );
	clr( L , 0 );
	clr( rmq , -1 );
}

void DFS( int u , int color )
{
	VIS[ u ] = 1;
	rama[ u ] = color;
	FOR( v , E[ u ] )
		if( !VIS[ *v ] && !idSuperNodes[ *v ] )
			L[ *v ] = L[ u ] + 1 , PARENT[ *v ] = u , DFS( *v , color );
}

void RMQ()
{
	REP( i , n ) rmq[ i ][ 0 ] = PARENT[ i ];
	for( int k = 1 ; k <= M ; ++k )
		REP( i , n ) if( rmq[ i ][ k - 1 ] != -1 )
			rmq[ i ][ k ] = rmq[ rmq[ i ][ k - 1 ] ][ k - 1 ];  
}
int lca( int x , int y )
{
	if( L[ x ] > L[ y ] ) swap( x , y );
	int dif = L[ y ] - L[ x ];
	REP( k , M + 1 )
		if( ( dif & ( 1 << k ) ) ) y = rmq[ y ][ k ];
	if( y == x ) return x;
	for( int k = M ; k >= 0 ; --k )
		if( rmq[ x ][ k ] != rmq[ y ][ k ] )
			x = rmq[ x ][ k ] , y = rmq[ y ][ k ];
	return PARENT[ x ];
}
int Find( int x )
{
	if( x == id[ x ] )return x;
	return id[ x ] = Find( id[ x ] );
}
void Union( int x , int y )
{
	int p = Find( x ) , q = Find( y );
	if( p != q )
		id[ p ] = q;
}
void dfs( int u , int p = -1 )
{
	if( found )return;
	vis[ u ] = 1;
	FOR( v , E[ u ] )
		if( *v != p && !found )
		{
			if( !vis[ *v ] )
				parentDFS[ *v ] = u , dfs( *v , u );
			else
			{
				/*cout << "cycle_detected" << endl;
				cout << "v : " << *v << endl;
				while( 1 )
				{
					if( u != *v )
						cout << u << endl;
					if( parentDFS[ u ] == -1 )break;
					u = parentDFS[ u ];
				}*/
				//SuperNodeofComp[ nSuperNodes ] = *v;
				idSuperNodes[ *v ] = nSuperNodes;
				Time[ *v ] = ++SZ[ nSuperNodes ];
				while( 1 )
				{
					if( u != *v )
						idSuperNodes[ u ] = nSuperNodes , Time[ u ] = ++SZ[ nSuperNodes ];
					if( parentDFS[ u ] == -1 )break;
					u = parentDFS[ u ];
				}
				found = 1;
				return;
			}
		}
}
int main()
{
	while( sc( n ) == 1 )
	{
		init();
		REP( i , n )
		{
			sc( G[ i ] );
			G[ i ]-- ;
			E[ i ].pb( G[ i ] );
			E[ G[ i ] ].pb( i );
			Union( i , G[ i ] );
		}
		REP( i , n )
			if( !VisComp[ Find( i ) ] )
			{
				found = 0;
				dfs( i );
				VisComp[ Find( i ) ] = 1;
				nSuperNodes++;
			}
		REP( i ,  n )
			if( idSuperNodes[ i ] )
				DFS( i , i );
		RMQ();
		int Q;
		sc( Q );
		while( Q -- )
		{
			int x , y;
			scanf( "%d%d", &x , &y );
			x-- , y--;
			if( Find( x ) != Find( y ) )
				puts( "-1" );
			else if( idSuperNodes[ x ] && ( idSuperNodes[ x ] == idSuperNodes[ y ] ) )
			{
				int t = abs( Time[ x ] - Time[ y ] );
				printf( "%d\n" , min( t , SZ[ idSuperNodes[ x ] ] - t ) );
			}
			else if( idSuperNodes[ x ] == 0 && idSuperNodes[ y ] == 0 && ( rama[ x ] == rama[ y ] ) )
			{
				int dist = L[ x ] + L[ y ] - ( L[ lca( x , y ) ] << 1 );
				printf( "%d\n", dist );
			}
			else if( idSuperNodes[ x ] == 0 && idSuperNodes[ y ] == 0 && ( rama[ x ] != rama[ y ] ) )
			{
				int t = abs( Time[ rama[ x ] ] - Time[ rama[ y ] ] );
				t = min( t , SZ[ idSuperNodes[ rama[ x ] ] ] - t );
				int dist = L[ x ] + L[ y ] + t;
				printf( "%d\n" , dist );
			}
			else if( idSuperNodes[ x ] == 0 && idSuperNodes[ y ] )
			{
				int t = abs( Time[ rama[ x ] ] - Time[ y ] );
				t = min( t , SZ[ idSuperNodes[ y ] ] - t );
				int dist = L[ x ] + t;
				printf( "%d\n", dist );
			}
			else if( idSuperNodes[ x ] && idSuperNodes[ y ] == 0 )
			{
				int t = abs( Time[ rama[ y ] ] - Time[ x ] );
				t = min( t , SZ[ idSuperNodes[ x ] ] - t );
				int dist = L[ y ] + t;
				printf( "%d\n", dist );
			}else assert( 0 );
		}
	}
}


