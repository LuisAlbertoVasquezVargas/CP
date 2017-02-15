#include <bits/stdc++.h>
using namespace std;

#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; ++it )
#define clr( t , val ) memset( t , val , sizeof( t ) )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define pb push_back

#define N 1005

typedef vector< int > vi;

int n , timer , top;
vi E[ N ];
int dfsn[ N ] , pila[ N ] , inpila[ N ] , comp[ N ];

int dfs( int u ){
	int low = dfsn[ u ] = ++timer;
	inpila[ pila[ top ++ ] = u ] = 1;
	FOR( v , E[ u ] )
		if( dfsn[ *v ] == 0 ) low = min( low , dfs( *v ) );
		else if( inpila[ *v ] ) low = min( low , dfsn[ *v ] );
	if( low == dfsn[ u ] ){
		int fin;
		do
		{
			fin = pila[ --top ];
			inpila[ fin ] = 0;
			comp[ fin ] = u;
		}while( fin != u );
	}
	return low;
}

void SCC()
{
	clr( dfsn , 0 );
	timer = 0;
	REP( i , n ) if( !dfsn[ i ] ) dfs( i );
}
vi dag[ N ];
int sz ;
int vis[ N ] , decision[ N ] , cola[ N ];

void topsort( int u ){
	vis[ u ] = 1;
	FOR( v , dag[ u ] )
		if( !vis[ *v ] ) topsort( *v );
	cola[ sz ++ ] = u;
}
void paint( int u , int color ){
	decision[ u ] = color;
	FOR( v , dag[ u ] )
		if( decision[ *v ] == -1 ) paint( *v , color );
}
void dfs0( int u ){
	vis[ u ] = 1;
	FOR( v , E[ u ] )
		if( !vis[ *v ] ) dfs0( *v );
}
void solve(){
	REP( i , n/2 ) if( comp[ 2*i ] == comp[ 2*i + 1 ] ){
		puts( "bad luck" );
		return;
	}
	clr( vis , 0 );
	dfs0( 0 );
	if( vis[ 1 ] ) {
		puts( "bad luck" );
		return;
	}
	REP( i , n ) dag[ i ].clear();
	
	REP( u , n )FOR( v , E[ u ] )
	{
		int i = comp[ u ] , j = comp[ *v ];
		if( i != j ) dag[ i ].pb( j );
	}

	clr( vis , 0 );
	sz = 0;
	REP( i , n ) if( comp[ i ] == i && !vis[ i ] ) topsort( i );
	clr( decision , -1 );
	reverse( cola , cola + sz );

	REP( i , sz ){
		int u = cola[ i ];	
		if( decision[ u ] == -1 )
		{
			decision[ u ] = 0;
			paint( comp[ u^1 ] , 1 );
		}
	}
	n /= 2;
	//cout << "val 0 "  << decision[ comp[ 0 ] ]<< endl;  
	for( int i = 1; i < n ; ++i )
		printf( "%d%c%c" , i , ( decision[ comp[ 2*i ] ]^decision[ comp[ 0 ] ]^1 ) ? 'w' : 'h' , i + 1 == n ? 10 : 32 );
}
int toi( string s ){
	istringstream in( s );
	int x ;
	in >> x;
	return x;
}
void get( string s , int &k ){
	int ns = s.size();
	char S = s[ ns - 1 ];
	s = s.substr( 0 , ns - 1 );
	int K = toi( s );
	if( S == 'h' ) k = 2*K;
	else k = 2*K + 1;
}
int main()
{
	ios_base :: sync_with_stdio( 0 );
	int m;
	while( cin >> n >> m )
	{
		if( n == 0 && m == 0 ) break;
		n *= 2;
		REP( i , n ) E[ i ].clear();
		REP( i , m ) {
			string s , t;
			cin >> s >> t;
			int u , v;
			get( s , u );
			get( t , v );
			/*cout << u << " " << (v^1) << endl;
			cout << v << " " << (u^1) << endl;
			cout << endl;*/
			E[ u ].pb( v ^ 1 );
			E[ v ].pb( u ^ 1 );
		}
		SCC();
		solve();
	}
}

