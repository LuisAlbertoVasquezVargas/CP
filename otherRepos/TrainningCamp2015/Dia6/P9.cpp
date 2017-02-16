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

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 100000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

vi G[ N + 1 ];
int DP[ N + 5 ] , MAXI[ N + 5 ];
vi order;
void dfs( int u , int p = -1 ){
	order.pb( u );
	DP[ u ] = 1 , MAXI[ u ] = 0;
	for( int i = 0 ; i < SZ( G[ u ] ) ; ++i ){
		int v = G[ u ][ i ];
		if( v == p ) continue;
		dfs( v , u );
		DP[ u ] += DP[ v ];
		MAXI[ u ] = max( MAXI[ u ] , DP[ v ] );
	}
}
char S[ N + 5 ];
void solve( int root , int d ){
	order.clear();
	dfs( root );
	root = -1;
	int n = SZ( order );
	for( int i = 0 ; i < n ; ++i ){
		int u = order[ i ];
		MAXI[ u ] = max( MAXI[ u ] , n - DP[ u ] );
		if( 2 * MAXI[ u ] <= n ){
			root = u;
			break;
		}
	}
	assert( root != -1 );
	S[ root ] = 'A' + d;
	for( int i = 0 ; i < SZ( G[ root ] ) ; ++i ){
		int v = G[ root ][ i ];
		int pos = find( all( G[ v ] ) , root ) - G[ v ].begin();
		G[ v ].erase( G[ v ].begin() + pos );
		solve( v , d + 1 );
	}
}

int main(){
	int n;
	while( sc( n ) == 1 ){
		REP( i , n ) G[ i ].clear();
		REP( i , n - 1 ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			G[ u ].pb( v );
			G[ v ].pb( u );
		}
		solve( 0 , 0 );
		REP( i , n ) printf( "%c%c" , S[ i ] , (i + 1 == n ? 10 : 32) );
	}
}


