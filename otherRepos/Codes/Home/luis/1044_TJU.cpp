#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 1500
#define NA 1500
#define NB 1500

typedef vector< int > vi;
vi E[ N + 5 ] ;

int color[ N + 5 ];
void bfs( int s ){
	queue< int > Q;
	color[ s ] = 0;
	Q.push( s );
	while( !Q.empty() ){
		int u = Q.front() ; Q.pop();
		REP( i , E[ u ].size() ){
			int v = E[ u ][ i ];
			if( color[ v ] == -1 ){
				color[ v ] = color[ u ] ^ 1;
				Q.push( v );
			}
		}
	}
}
vi G[ NA + 5 ];
int vis[ NA + 5 ] , match[ NB + 5 ];
int dfs( int u ){
	if( vis[ u ] ) return 0;
	vis[ u ] = 1;
	REP( i , G[ u ].size() ){
		int v = G[ u ][ i ];
		if( match[ v ] == -1 || dfs( match[ v ] ) ){
			match[ v ] = u;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int nodes , u , v , sz;
	while( scanf( "%d" , &nodes ) == 1 )
	{
		REP( i , nodes ) E[ i ].clear();
		REP( i , nodes ){
			scanf( "%d:(%d)" , &u , &sz );
			REP( j , sz ){
				scanf( "%d" , &v );
				E[ u ].pb( v );
				E[ v ].pb( u );
			}
		}
		REP( i , nodes ) G[ i ].clear();
		REP( i , nodes ) color[ i ] = -1;
		bfs( 0 );
		REP( u , nodes ){
			REP( i , E[ u ].size() ){
				int v = E[ u ][ i ];
				if( color[ u ] ) G[ u ].pb( v );
				else G[ v ].pb( u );
			}
		}
		//REP( i , nodes ) cout << color[ i ] << endl;
		REP( i , nodes ) match[ i ] = -1;
		int ans = 0;
		REP( i , nodes ){
			REP( k , nodes ) vis[ k ] = 0;
			ans += dfs( i );
		}
		printf( "%d\n" , ans );
	}
}


