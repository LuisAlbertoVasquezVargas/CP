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

#define N 20005
#define M 15

using namespace std;

int n , a , b;
vi E[ N ];
int vis[ N ] , P[ N ] , L[ N ] , rmq[ N ][ M + 5 ];

void init()
{
	P[0] = -1;
	clr( rmq , -1 );
	clr( vis , 0 );
}
void dfs( int u )
{
	vis[ u ] = 1;
	FOR( v , E[ u ] )
		if( !vis[ *v ] )
			P[ *v ] = u , L[ *v ] = L[ u ] + 1 , dfs( *v );
}
void RMQ()
{
	REP( i , n ) rmq[ i ][ 0 ] = P[ i ];
	for( int k = 1 ; k <= M ; ++k )
		REP( i , n )if( rmq[ i ][ k - 1 ] != -1 )
			rmq[ i ][ k ] = rmq[ rmq[ i ][ k - 1 ] ][ k - 1 ];
}
int bfs( int s )
{
	clr( vis , 0 );
	queue< int >Q;
	Q.push( s );
	vis[ s ] = 1;
	int u;
	while( !Q.empty() )
	{
		u = Q.front();
		Q.pop();
		FOR( v , E[ u ] )
			if( !vis[ *v ] )
			{
				Q.push( *v );
				vis[ *v ] = 1;
			} 
	}
	return u;
}
void doit()
{
	dfs( 0 );
	RMQ();
	a = bfs( 0 );
	b = bfs( a );
}
int lca( int x , int y )
{
	if( L[ x ] > L[ y ] ) swap( x , y );
	int dif = L[ y ] - L[ x ];
	REP( k , M + 1 )
		if( ( dif & ( 1 << k ) ) ) y = rmq[ y ][ k ];
	if( y == x )return x;
	for( int k = M ; k >= 0 ; --k )
		if( rmq[ x ][ k ] != rmq[ y ][ k ] )
			x = rmq[ x ][ k ] , y = rmq[ y ][ k ];
	return P[ x ];
}

int dist( int x , int y , int lca )
{
	return L[ x ] + L[ y ] - ( 2*L[ lca ] );
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
	int Q;
	scanf( "%d%d" , &n , &Q );
	init();
	REP( i , n - 1 )
	{
		int x , y;
		scanf( "%d%d" , &x , &y );
		x-- , y--;
		E[ x ].pb( y );
		E[ y ].pb( x );
	}
	doit();
	while( Q-- )
	{
		int u , D;
		scanf( "%d%d" , &u , &D );
		u--;
		int lcaA = lca( a , u );
		int distA = dist( a , u , lcaA );
		int lcaB = lca( b , u );
		int distB = dist( b , u , lcaB );
		/*cout << "u:" << u + 1 << endl;
		cout << "a:" << a + 1 << endl;
		cout << "lcaA:" << lcaA << endl;
		cout << "b:" << b + 1 << endl;
		cout << "lcaB:" << lcaB << endl;
		*/
		if( distA > distB )swap( a , b ) , swap( lcaA , lcaB ) , swap( distA , distB );
		if( distB < D ) puts( "0" );
		else
		{
			//cout << "A:" << b  + 1 << endl;
			//cout << u + 1 << " " << D << " "; 
			printf("%d\n" , kth( u , b , D , lcaB , distB ) + 1 );
		}
	}
}


