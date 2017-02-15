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

vi G[ N + 5 ];
vi C[ N + 5 ];
int T[ N + 5 ];
int DP[ 2 ][ N + 5 ];
void dfs( int u ){
	DP[ 0 ][ u ] = 0;
	int mini = INT_MAX/2;
	int ch = 0;
	REP( i , SZ( G[ u ] ) ){
		int v = G[ u ][ i ] , w = C[ u ][ i ];
		dfs( v );
		if( T[ v ] ){
			ch ++;
			DP[ 0 ][ u ] += w + DP[ 0 ][ v ];
			mini = min( mini , DP[ 1 ][ v ] - (DP[ 0 ][ v ] + w) );
		}
		T[ u ] += T[ v ];
	}
	if( ch ) DP[ 1 ][ u ] = DP[ 0 ][ u ] + mini;
	else DP[ 1 ][ u ] = 0;
}
int main(){
	int n , F;
	while( sc( n ) == 1 ){
		sc( F );
		REP( i , n ) G[ i ].clear() , C[ i ].clear() , T[ i ] = 0;
		REP( i , n - 1 ){
			int u , v , w;
			sc( u ) , sc( v ) , sc( w );
			u -- , v --;
			G[ u ].pb( v );
			C[ u ].pb( w );
		}
		REP( i , F ){
			int x;
			sc( x );
			x -- ;
			T[ x ] = 1;
		}
		dfs( 0 );
		printf( "%d\n" , DP[ 1 ][ 0 ] );
	}
}


