#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define N 1000000

typedef vector< int > vi;
typedef pair< int , int > pii;

char s[ N + 5 ];
int T[ N + 5 ];
int main(){
	int k;
	while( scanf( "%d%s" , &k , s ) == 2 ){
		if( k == -1 ) break;
		int n = strlen( s );
		int j = T[ 0 ] = -1;
		REP( i , n ){
			while( j != -1 && s[ i ] != s[ j ] ) j = T[ j ];
			T[ i + 1 ] = ++j;
		}
		if( k < T[ n ] ) puts( "0" );
		else printf( "%d\n" , (k - T[ n ])/(n - T[ n ]));
	}
}


