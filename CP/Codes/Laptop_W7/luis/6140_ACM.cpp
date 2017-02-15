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
int A[ N ];
vi E[ N ];

int id[ N ];
int Find( int x )
{
	if( x == id[ x ] )return x;
	return id[ x ] = Find( id[ x ] );
}
void Union( int x , int y )
{
	int p = Find( x ) , q = Find( y );
	if( p != q ) id[ p ] = q;
}

int visComp[ N ];
bool found;
int nCycle , t;
int vis[ N ] , parent[ N ] , whatCycle[ N ] , szCycle[ N ] , Time[ N ];
void dfs( int u , int p = -1 )
{
	if( found )return;
	vis[ u ] = 1;
	FOR( v , E[ u ] )
		if( *v != p && !found )
		{
			if( !vis[ *v ] )
				parent[ *v ] = u , dfs( *v , u );
			else
			{
				//cout << "Found:" << endl;//
				found = 1;
				
				whatCycle[ *v ] = nCycle;
				Time[ *v ] = t++;
				szCycle[ nCycle ]++;
				if( parent[ *v ] == u )// cuando hay ciclo de tamaño dos
				{
					whatCycle[ u ] = nCycle;
					Time[ u ] = t++;
					szCycle[ nCycle ]++;
					return;
				}
				//cout << *v + 1 << endl;///
				while( u != *v )
				{
						//cout << u + 1 << endl;//
					whatCycle[ u ] = nCycle;
					Time[ u ] = t++;
					szCycle[ nCycle ]++;
					//if( parent[ u ] == -1 ) break;
					u = parent[ u ];
				}
				return;
			}
		}
}

int VIS[ N ] , RAMA[ N ] , PARENT[ N ] , L[ N ];
void DFS( int u , int color )
{
	VIS[ u ] = 1;
	RAMA[ u ] = color;
	FOR( v , E[ u ] )
		if( !VIS[ *v ] && !whatCycle[ *v ] )
		{
			PARENT[ *v ] = u , L[ *v ] = L[ u ] + 1;
			DFS( *v , color );
		}
}
int rmq[ N ][ M + 5 ];
void RMQ()
{
	REP( i , n ) rmq[ i ][ 0 ] = PARENT[ i ];
	for( int k = 1 ; k <= M ; ++k )
		REP( i , n ) if( rmq[ i ][ k - 1 ] != -1 )
			rmq[ i ][ k ] = rmq[ rmq[ i ][ k - 1 ] ][ k - 1 ];
}
int LCA( int x , int y )
{
	if( L[ x ] > L[ y ] ) swap( x , y );
	int dif = L[ y ] - L[ x ];
	REP( k , M + 1 ) 
		if( ( dif & ( 1 << k ) ) ) y = rmq[ y ][ k ];
	if( x == y )return x;
	for( int k = M ; k >= 0 ; --k )
		if( rmq[ x ][ k ] != rmq[ y ][ k ] )
			x = rmq[ x ][ k ] , y = rmq[ y ][ k ];
	return PARENT[ x ];
}
void init()
{
	REP( i , n ) E[ i ].clear();
	
	REP( i , n ) id[ i ] = i;
	
	clr( parent , -1 );
	clr( vis , 0 );
	clr( visComp , 0 );
	clr( whatCycle , 0 );
	clr( szCycle , 0 );
	clr( Time , -1 );
	
	clr( VIS , 0 );
	clr( RAMA , -1 );
	clr( PARENT , -1 );
	clr( L , 0 );
	
	clr( rmq , -1 );
}
void doit()
{
	REP( i , n ) E[ i ].pb( A[ i ] ) , E[ A[ i ] ].pb( i );
	
	REP( i , n ) Union( i , A[ i ] );
	nCycle = 1;
	REP( i , n )
		if( !visComp[ Find( i ) ] )
		{
			found = 0;
			t = 0;
			dfs( i );
			visComp[ Find( i ) ] = 1;
			nCycle++;
		}
	//REP( i , nCycle )cout << setw(5) << szCycle[ i ] << ( i + 1 == nCycle ? "\n":" " );//
	//REP( i , n ) cout << setw( 3 ) << whatCycle[ i ] << ( i + 1 == n ? "\n":" " );//
	//REP( i , n )cout << setw(5) << Time[ i ] << ( i + 1 == n ? "\n":" " );//
	REP( i , n )
		if( whatCycle[ i ] )
			DFS( i , i ) , RAMA[ i ] = -1;
	//REP( i , n ) cout << setw(5) << RAMA[ i ] << ( i + 1 == n ? "\n":" " );//
	RMQ();
	//REP( i , n ) cout << setw(5) << PARENT[ i ] << ( i + 1 == n ? "\n":" " );//
}
int main()
{
	while( sc( n ) == 1 )
	{
		init();
		REP( i , n ) sc( A[ i ] ) , A[ i ]--;
		doit();
		int Q;
		sc( Q );
		while( Q-- )
		{
			int x , y;
			sc( x ) , sc( y );
			x-- , y--;
			if( Find( x ) != Find( y ) )
				puts( "-1" );
			else if( whatCycle[ x ] && whatCycle[ y ] && whatCycle[ x ] == whatCycle[ y ] )
			{
				int length = abs( Time[ x ] - Time[ y ] );
				length = min( length , szCycle[ whatCycle[ x ] ] - length );
				printf( "%d\n" , length );
			}
			else if( !whatCycle[ x ] && !whatCycle[ y ] && RAMA[ x ] != -1 && RAMA[ y ] != -1 && RAMA[ x ] == RAMA[ y ] )
			{
				int lca = LCA( x , y );
				printf( "%d\n" , L[ x ] + L[ y ] - 2*L[ lca ] );
			}
			else if( !whatCycle[ x ] && !whatCycle[ y ] && RAMA[ x ] != -1 && RAMA[ y ] != -1 && RAMA[ x ] != RAMA[ y ] )
			{
				int p = RAMA[ x ] , q = RAMA[ y ];
				int length = abs( Time[ p ] - Time[ q ] );
				length = min( length , szCycle[ whatCycle[ p ] ] - length );
				/*cout << x << " " << y << endl;
				cout << "lent " << length << endl;
				cout << "level x " << L[ x ] << " level y " << L[ y ] << endl;*/
				printf( "%d\n" , length + L[ x ] + L[ y ] );
			}
			else if( !whatCycle[ x ] && whatCycle[ y ] && RAMA[ x ] != -1 && RAMA[ y ] == -1 )
			{
				int p = RAMA[ x ];
				int length = abs( Time[ y ] - Time[ p ] );
				length = min( length , szCycle[ whatCycle[ y ] ] - length );
				printf( "%d\n" , length + L[ x ] );
			}
			else if( whatCycle[ x ] && !whatCycle[ y ] && RAMA[ x ] == -1 && RAMA[ y ] != -1 )
			{
				int p = RAMA[ y ];
				int length = abs( Time[ x ] - Time[ p ] );
				length = min( length , szCycle[ whatCycle[ x ] ] - length );
				printf( "%d\n" , length + L[ y ] );
			}
			else assert( 0 );
		}
	}
}


