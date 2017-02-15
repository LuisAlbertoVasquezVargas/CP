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

#define N 500

typedef vector< int > vi;

int n , m;
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
int main(){
	int cases , op;
	sc( cases );
	REP( tc , cases ){
		sc( n ) , sc( m );
		REP( i , n ) G[ i ].clear();
		REP( i , n ) REP( j , m ){
			sc( op );
			if( op ) G[ i ].pb( j );
		}
		REP( i , m ) match[ i ] = -1;
		int ans = 0;
		REP( i , n ){
			REP( j , n ) vis[ j ] = 0;
			ans += dfs( i );
		}
		printf("Case %d: ", tc + 1 );
      	printf("a maximum of %d nuts and bolts ", ans );
      	printf("can be fitted together\n");
	}
}

