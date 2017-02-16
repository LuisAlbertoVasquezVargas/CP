#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define N 100000

int* getBoard( char *s , int n ){
    int* T = new int[ n + 1 ];
    T[ 1 ] = 0;
    for( int v = 2 , p = 0 ; v <= n ; ++v )
    {
        while( p && ( s[ v - 1 ] != s[ p ] ) )
            p = T[ p ];
        if( s[ v - 1 ] == s[ p ] ) p++;
        T[ v ] = p;
    }
    return T;
} 
char S[ N + 5 ];

int main()
{
	while( scanf( "%s" , S ) == 1 ){
		if( S[ 0 ] == '*' ) break;
		int nS = strlen( S );
		int* B = getBoard( S , nS );
		int t = ( nS - B[ nS ] );
		if( nS % t == 0 )
			printf( "%d\n" , nS /( nS - B[ nS ] ) );
		else puts( "1" );
	}
}
