#include<cstdio>
#include<cstring>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define N 1000000

char s[ N + 5 ];
int T[ N + 5 ];
int main(){
	int n;
	while( scanf( "%s" , s ) == 1 ){
		if( s[ 0 ] == '.' ) break;
		n = strlen( s );
		int j = T[ 0 ] = -1;
		REP( i , n ){
			while( j != -1 && s[ i ] != s[ j ] ) j = T[ j ];
			T[ i + 1 ] = ++j;
		}
		if( n%(n - T[ n ]) == 0 && T[ n ] >= n/2 ) printf( "%d\n" , n / (n - T[n]) );
		else puts( "1" );
	}
}

