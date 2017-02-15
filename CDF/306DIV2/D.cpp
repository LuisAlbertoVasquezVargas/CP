#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define SZ( v ) ((int)(v).size())
#define all( v ) v.begin() , v.end()

#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef vector< int > vi;

void add( vi &x , vi &y , int u , int v ){
	x.pb( u ) , y.pb( v );
}
int n;
void Fill( vi &x , vi &y , int cur ){
	for( int i = 1 ; i <= 2 * n ; ++i )
		add( x , y , cur , cur + i );
	for( int i = 1 ; i <= 2 * n ; ++i )
		for( int j = 1 ; j <= 2 * n ; ++j )
			add( x , y , cur + i , cur + 2 * n + 2 * n * (i - 1) + j);
	for( int i = 1 ; i <= n ; ++i )
		for( int j = 1 ; j <= 2 * n ; ++j )
			for( int k = 1 ; k <= 2 * n ; ++k )
				add( x , y , cur + 2 * n + 2 * n * (i - 1) + j , 
					cur + 2 * n + 2 * n * (i - 1) + k + 2 * n * n );
}
int main(){
	int k;
	while( sc( k ) == 1 ){
		if( !(k & 1) ){
			puts( "NO" );
			continue;
		}
		puts( "YES" );
		n = (k - 1)/2;
		int len = 1 + 2 * n + 4 * n * n;
		vi x , y;
		Fill( x , y , 0 );
		Fill( x , y , len );
		x.pb( 0 );
		y.pb( len );
		printf( "%d %d\n" , 2 * len , SZ( x ) );
		REP( i , SZ( x ) ) printf( "%d %d\n" , x[ i ] + 1 , y[ i ] + 1 );
	}	
}


