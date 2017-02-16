#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define N 15

typedef vector< int > vi;

int n;
vi G[ N + 5 ];
int vis[ N + 5 ];
vi path;
void impr( vi &v ){
	REP( i , SZ( v ) ) cout << v[ i ] << char( i + 1 == SZ( v ) ? 10 : 32 );
}
void f( int u ){
	impr( path );
	REP( i , SZ( G[ u ] ) ){
		int v = G[ u ][ i ];
		if( !vis[ v ] ){
			vis[ v ] = 1;
			path.pb( v );
			f( v );
			vis[ v ] = 0;
			path.pop_back();
		}
	}
}
int main(){
	cin >> n;
	int m;
	cin >> m;
	REP( i , m ){
		int u , v;
		cin >> u >> v;
		u -- , v --;
		G[ u ].pb( v );
		G[ v ].pb( u );
	}
	clr( vis , 0 );
	vis[ 0 ] = 1;
	path.pb( 0 );
	f( 0 );	
}


