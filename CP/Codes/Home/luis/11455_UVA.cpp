#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i, n ) for( int i = 0 ; i < n ; ++i )

#define N 15

int P[ N ];
	
int main()
{
	int cases ;
	sc( cases );
	while( cases -- )
	{
		REP( i , 4 ) sc( P[ i ] );
		sort( P , P + 4 );
		if( P[ 3 ] >= 1LL*P[ 0 ] + 1LL*P[ 1 ] + 1LL*P[ 2 ] ) puts( "banana" );
		else
		{
			if( P[ 0 ] == P[ 1 ] && P[ 1 ] == P[ 2 ] && P[ 2 ] == P[ 3 ] ) puts( "square" );
			else if( P[ 0 ] == P[ 1 ] && P[ 2 ] == P[ 3 ] ) puts( "rectangle" );
			else puts( "quadrangle" );
		}
	}
}
