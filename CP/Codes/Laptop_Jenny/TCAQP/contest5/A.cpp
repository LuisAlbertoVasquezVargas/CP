#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define N 1000

int DP[ 30 ][ N + 5 ][ N + 5 ];
int n , m;
char S[ N + 5 ] , T[ N + 5 ];

int main()
{
	while( scanf( "%s%s" , S , T ) == 2 ){
		if( S[ 0 ] == '*' ) break;
		n = strlen( S ) , m = strlen( T );
		REP( i , n ) S[ i ] -= 'a';
		REP( i , m ) T[ i ] -= 'a';
		
	}
}
