#include <bits/stdc++.h>
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

#define N 26

typedef vector< int > vi;

int vis[ N + 5 ] , match[ N + 5 ];
vi G[ N + 5 ];
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
vector< string > S[ N + 5 ];

int main(){
	sync
	int cases , sz;
	cin >> cases;
	REP( tc , cases ){
		int n;
		cin >> n;
		REP( i , n ) match[ i ] = -1;
		REP( i , n ) G[ i ].clear();
		REP( i , n ){
			cin >> sz;
			S[ i ].resize( sz );
			REP( j , sz ){
				cin >> S[ i ][ j ];
				int u = toupper( S[ i ][ j ][ 0 ] );
				u -= 'A';
				if( u < n ) G[ i ].pb( u );
			}
		}
		REP( i , n ){
			REP( j , n )vis[ j ] = 0;
			dfs( i );
		}
		cout << "Case #" << tc + 1 << ":\n" ;
		REP( i , n ){
			int u = match[ i ];
			REP( j , S[ u ].size() ){
				string s = S[ u ][ j ];
				if( toupper( s[ 0 ] ) == 'A' + i ) {
					transform( all( s ) , s.begin() , :: tolower );
					s[ 0 ] = toupper( s[ 0 ] );
					cout << s << '\n';
				}
			}
		}
	}
}


