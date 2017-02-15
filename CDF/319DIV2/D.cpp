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
typedef vector< vi > vvi;

vi G[ N + 5 ];
vvi bucket[ N + 5 ];
vi vec;
int vis[ N + 5 ];
void dfs( int u , int p ){
	vis[ u ] = 1;
	vec.pb( u + 1 );
	for( auto v : G[ u ] )
		if( !vis[ v ] && v != p ) dfs( v , u );
}
int main(){
	int n;
	while( sc( n ) == 1 ){
		REP( i , n ) G[ i ].clear();
		REP( i , n + 1 ) bucket[ i ].clear();
		REP( i , n ){
			int p;
			sc( p );
			p --;
			G[ i ].pb( p );
		}
		REP( i , n ) vis[ i ] = 0;
		bool odd = 0;
		REP( i , n )
			if( !vis[ i ] ) {
				vec.clear();
				dfs( i , -1 );
				if( SZ( vec ) & 1 ) odd ++;
				bucket[ SZ( vec ) ].pb( vec );
			}
		if( SZ( bucket[ 1 ] ) ){
			puts( "YES" );
			vi r = bucket[ 1 ].back();
			int root = r[ 0 ];
			bucket[ 1 ].pop_back();
			for( int L = 1 ; L <= n ; ++L )
				for( auto arr : bucket[ L ] )
					for( auto v : arr )
						printf( "%d %d\n" , root , v );
			continue;
		}
		if( SZ( bucket[ 2 ] ) && !odd ){
			puts( "YES" );
			printf( "%d %d\n" , bucket[ 2 ][ 0 ][ 0 ] , bucket[ 2 ][ 0 ][ 1 ] );
			REP( i , SZ( bucket[ 2 ] ) - 1 ){
				printf( "%d %d\n" , bucket[ 2 ][ i ][ 0 ] , bucket[ 2 ][ i + 1 ][ 0 ] );
				printf( "%d %d\n" , bucket[ 2 ][ i ][ 1 ] , bucket[ 2 ][ i + 1 ][ 1 ] );
			}
			vi r = bucket[ 2 ].back();
			for( int L = 4 ; L <= n ; ++L )
				for( auto arr : bucket[ L ] )
					REP( i , SZ( arr ) )
						printf( "%d %d\n" , r[ i & 1 ] , arr[ i ] );
			continue;
		}
		puts( "NO" );
	}
}


