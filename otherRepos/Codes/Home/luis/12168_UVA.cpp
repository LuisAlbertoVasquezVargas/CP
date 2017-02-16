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

#define N 10000

typedef pair< int , int > pii;
typedef vector< int > vi;

int toi( string s ){ istringstream in( s ) ; int x ; in >> x; return x; }
int n , m;
vi G[ N + 5 ];
int vis[ N + 5 ] , match[ N + 5 ];
bool dfs( int u ){
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
	sync
	string s , t;
	int cases , cats , dogs , voters;
	cin >> cases;
	REP( tc , cases ){
		cin >> cats >> dogs >> voters;
		vector< pii > catLovers , dogLovers;
		REP( i , voters ){
			cin >> s >> t;
			int a = toi( s.substr( 1 ) ) , b = toi( t.substr( 1 ) );
			a-- , b--;
			if( s[ 0 ] == 'C' )
				catLovers.pb( mp( a , b ) );
			else
				dogLovers.pb( mp( a , b ) );
		}
		n = catLovers.size();
		m = dogLovers.size();
		REP( i , n ) G[ i ].clear();
		REP( i , m ) match[ i ] = -1;
		REP( i , n ) REP( j , m )
			if( catLovers[ i ].se == dogLovers[ j ].fi || catLovers[ i ].fi == dogLovers[ j ].se )
				G[ i ].pb( j );
		int ans = n + m;
		REP( i , n ){
			REP( j , n ) vis[ j ] = 0;
			ans -= dfs( i );
		}
		cout << ans << '\n';
	}
}


