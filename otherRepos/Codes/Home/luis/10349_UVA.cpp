#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it ++ )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back

#define M 45
#define N 1605

typedef vector< int > vi;

vi E[ N ];
int vis[ N ] , match[ N ];

bool dfs( int u ){
	if( vis[ u ] ) return 0;
	vis[ u ] = 1;
	FOR( v , E[ u ] )
		if( match[ *v ] == -1 || dfs( match[ *v ] ) )
		{
			match[ *v ] = u;
			return 1;
		}
	return 0;
}
int bpm(){
	clr( match , -1 ) ; int ans = 0;
	REP( i , N ) clr( vis , 0 ) , ans += dfs( i );
	return ans;
}
string S[ M ];
int main()
{
	int cases , n , m ;
	cin >> cases;
	REP( tc , cases ){
		cin >> n >> m;
		REP( i , n ) cin >> S[ i ];
		REP( i , N ) E[ i ].clear();
		int ans = 0;
		REP( i , n ) REP( j , m ) ans += S[ i ][ j ] == '*';
		REP( i , n ) REP( j , m - 1 )
			if( S[ i ][ j ] == '*' && S[ i ][ j ] == S[ i ][ j + 1 ] ){
				int u = i*m + j , v = i*m + j + 1;
				if( ( i + j )&1 ) E[ u ].pb( v );
				else E[ v ].pb( u );
			}
		REP( i , n - 1 ) REP( j , m )
			if( S[ i ][ j ] == '*' && S[ i ][ j ] == S[ i + 1 ][ j ] ){
				int u = i*m + j , v = ( i + 1 )*m + j;
				if( ( i + j )&1 ) E[ u ].pb( v );
				else E[ v ].pb( u );
			}
		ans -= bpm();
		printf( "%d\n" , ans );	
	}
}
