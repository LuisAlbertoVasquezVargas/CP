#include<bits/stdc++.h>
using namespace std;
 
#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) ) 
 
#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())
 
#define fi first
#define se second
#define mp make_pair
 
#define N 100000
 
typedef long long ll;
typedef vector< int > vi;
 
char s[ N + 5 ] , t[ N + 5 ];
int main(){
	int n;
	while( scanf( "%d%s" , &n , s ) == 2 ){
		vi F( 4 , n );
		t[ 2 * n ] = 0;
		REP( i , 2 * n ){
			vector< char > v;
			for( char c = 'A' ; c <= 'D' ; ++c )
				if( c == s[ i ] || c == s[ i + 1 ] ) continue;
				else v.pb( c );
			t[ i ] = v[ 0 ] , t[ i + 1 ] = v[ 1 ];
			if( i && t[ i ] == t[ i - 1 ] ) swap( t[ i ] , t[ i + 1 ] );
			i ++;
		}
		printf( "%s\n" , t );
	}
}
