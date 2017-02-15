#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() cout << "hola que hace ?" << endl;
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 100000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;

int P[ N + 1 ];
vi G[ N + 5 ] , C[ N + 5 ];
void add( int u , int v , int w ){
	G[ u ].pb( v );
	C[ u ].pb( w );
}
int vis[ N + 5 ];
ll SP[ N + 5 ] , DP[ N + 5 ];
void dfs( int u , int p = -1 ){
	vis[ u ] = 1;
	SP[ u ] = P[ u ];
	DP[ u ] = 0;
	REP( i , SZ( G[ u ] ) ){
		int v = G[ u ][ i ];
		int w = C[ u ][ i ];
		if( v == p ) continue;
		if( vis[ v ] ) continue;
		dfs( v , u );
		SP[ u ] += SP[ v ];
		DP[ u ] += DP[ v ] + (ll) w * SP[ v ];
	}
}
int best;
ll ans;
void DFS( int u , int p , ll cur ){
	vis[ u ] = 1;
	if( cur < ans ){
		ans = cur;
		best = u;
	}
	REP( i , SZ( G[ u ] ) ){
		int v = G[ u ][ i ];
		int w = C[ u ][ i ];
		if( v == p ) continue;
		if( vis[ v ] ) continue;
		DFS( v , u , cur + ( -2LL * SP[ v ] + SP[ 0 ] ) * (ll) w );
	}
}
int main(){
	freopen("house.in", "r", stdin);
	freopen("house.out", "w", stdout);
	int n;
	while( sc( n ) == 1 ){
		REP( i , n ) G[ i ].clear() , C[ i ].clear();
		REP( i , n ) sc( P[ i ] );
		REP( i , n - 1 ){
			int u , v , w;
			sc( u ) , sc( v ) , sc( w );
			u -- , v --;
			add( u , v , w );
			add( v , u , w );
		}
		REP( i , n ) vis[ i ] = 0;
		dfs( 0 );
		ans = LLONG_MAX;
		REP( i , n ) vis[ i ] = 0;
		DFS( 0 , -1 , DP[ 0 ] );
		cout << ++best << " " << ans << '\n';
	}
}




