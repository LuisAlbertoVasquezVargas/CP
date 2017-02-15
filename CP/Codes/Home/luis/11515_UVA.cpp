#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define N 20
#define EPS (1e-8)

typedef long double ld;

int X[ N ] , Y[ N ] , R[ N ];

int main()
{
	int cases;
	sc( cases );
	while( cases -- )
	{
		int n;
		sc( n );
		REP( i , n ) sc( X[ i ] ) , sc( Y[ i ] ) , sc( R[ i ] );
		int S = 0;
		REP( mask , 1 << n )
		{
			bool ok = 1;
			for( int i = 0 ; ok && i < n ; ++i )
				for( int j = i + 1 ; ok && j < n ; ++j )
					if( ( mask & ( 1 << i ) ) && ( mask & ( 1 << j ) ) )
					{
						int dx = X[ i ] - X[ j ];
						int dy = Y[ i ] - Y[ j ];
						ld c = sqrt( dx*dx + dy*dy );
						ld a = R[ i ] , b = R[ j ];
						ld A[ 3 ] = { a , b , c };
						sort( A , A + 3 );
						if( a + b >= c - EPS )
							ok = 0;
					}
			if( ok )
			{
				int sum = 0;
				REP( i , n ) 
					if( mask&( 1 << i ) ) sum += R[ i ]*R[ i ];
				S = max( S , sum );
			}
		}	
		printf( "%d\n" , S );	
	}
}
