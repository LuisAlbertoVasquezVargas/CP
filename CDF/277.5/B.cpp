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

#define N 100

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int match[ N + 5 ];
bool vis[ N + 5 ];
vi G[ N + 5 ];
int dfs( int u ){
	if( vis[ u ] ) return 0;
	vis[ u ] = 1;
	for( auto v : G[ u ] ){
		if( match[ v ] == -1 || dfs( match[ v ] ) ){
			match[ v ] = u;
			return 1;
		}
	}
	return 0;
}
int main(){
	int n , m;
	while( sc( n ) == 1 ){
		vi A( n );
		REP( i , n ) sc( A[ i ] );
		sc( m );
		vi B( m );
		REP( i , m ) sc( B[ i ] );
		REP( i , N ) G[ i ].clear();
		REP( i , n ) REP( j , m ){
			if( abs( A[ i ] - B[ j ] ) <= 1 )
				G[ i ].pb( j );
		}
		clr( match , -1 );
		int ans = 0 ;
		REP( i , N ){
			clr( vis , 0 );
			ans += dfs( i );
		}
		printf( "%d\n" , ans );
	}
}

