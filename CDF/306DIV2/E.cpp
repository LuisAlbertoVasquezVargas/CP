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

int main(){
	int n;
	while( sc( n ) == 1 ){
		vi x( n );
		REP( i , n ) sc( x[ i ] );
		
		if( x[ n - 1 ] == 1 ){
			puts( "NO" );
			continue;
		}
		puts( "YES" );
		
		
	}
}



