#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define FOR( it , A ) for( vector< short > ::iterator it = A.begin() ; it != A.end() ; it ++ )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()

#define N 1000

typedef vector< short > vi;
int n;
vi E[ N + 5 ];
short DP[ N + 5 ] ;
bool vis[ N + 5 ] ;
void dfs( int u ){
	vis[ u ] = 1;
	short &dev = DP[ u ] = 0;
	short sz = E[ u ].size();	
	vector< bool > SET( sz + 1 );
	FOR( v , E[ u ] ){
		//cout << *v << endl;
		if( !vis[ *v ] ) dfs( *v );
		SET[ min( sz , DP[ *v ] ) ] = 1;
	}
	while( SET[ dev ] ) dev++;
	//cout << u << " " << dev << endl;
}
int main(){
	int sz , v , m;
	while( sc( n ) == 1 ){
		REP( i , n ) E[ i ].clear() , vis[ i ] = 0;
		REP( u , n ){
			sc( sz );
			REP( j , sz ){
				sc( v );
				E[ u ].pb( v );
				//E[ v ].pb( u );
			}
		}
		REP( i , n ) if( !vis[ i ] ) dfs( i );
		while( sc( m ) == 1 ){
			if( !m ) break;
			int ans = 0;
			REP( i , m ) sc( v ) , ans ^= DP[ v ] ;
			puts( ans ? "WIN" : "LOSE" );
		}
	}
}
