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

#define N 50
#define INF (1<<30)
#define M 2500

typedef pair< int , int > pii;
typedef vector< int > vi;

int n;
int match[ N + 5 ] , vis[ N + 5 ] , used[ N + 5 ];
vi G[ N + 5 ];
int dfs( int u ){
	if( vis[ u ] ) return 0;
	vis[ u ] = 1;
	REP( i , G[ u ].size() ){
		int v = G[ u ][ i ];
		if( match[ v ] == -1 || dfs( match[ v ] ) ){
			match[ v ] = u;
			used[ u ] = 1;
			return 1;
		}
	}
	return 0;
}
int bpm(){
	int ans = 0;
	REP( i , n ){
		if( used[ i ] ) ans ++;
		else{
			REP( j , n ) vis[ j ] = 0;
			if( dfs( i ) ) ans++;
		}
	}
	return ans;
}
void fix( int k ){
	G[ k ].erase( G[ k ].begin() );
}
pair< int , pii > P[ M + 5 ];
int main(){
	int cases , x , sz;
	sc( cases );
	while( cases -- ){
		sc( n );
		sz = 0;
		REP( i , n ) REP( j , n ) {
			sc( x );
			P[ sz ++ ] = mp( x , mp( i , j ) );
		}
		REP( i , n ) match[ i ] = -1;
		REP( i , n ) used[ i ] = 0;
		REP( i , n ) G[ i ].clear();
		sort( P , P + sz );
		int lo = 0 , hi = 0 , ans = INF;
		while( lo < sz ){
			int BPM = bpm();
			while( hi < sz && BPM < n ){
				int u = P[ hi ].se.fi , v = P[ hi ].se.se;
				G[ u ].pb( v );
				BPM = bpm();
				hi ++;
			}
			if( BPM == n ) ans = min( ans , P[ hi - 1 ].fi - P[ lo ].fi );
			int u = P[ lo ].se.fi , v = P[ lo ].se.se;
			fix( u );
			if( match[ v ] != -1 )
				used[ match[ v ] ] = 0;
			match[ v ] = -1;
			lo ++;
		}
		printf( "%d\n" , ans );
	}
}


