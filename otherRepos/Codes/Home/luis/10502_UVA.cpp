#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define N 105

char A[ N ][ N ];
int S[ N ][ N ];

int main()
{
	int n , m;
	while( scanf( "%d%d" , &n , &m ) == 2 )
	{
		if( n == 0 ) break;
		REP( i , n )
		{
			A[ i + 1 ][ 0 ] = '*';
			scanf( "%s" , A[ i + 1 ] + 1 );
		}
		for( int i = 1 ; i <= n ; ++i )
			for( int j = 1 ; j <= m ; ++j )
				S[ i ][ j ] = S[ i - 1 ][ j ] + S[ i ][ j - 1 ] - S[ i - 1 ][ j - 1 ] + A[ i ][ j ] - '0';			
		int ans = 0;
		for( int i = 1 ; i <= n ; ++i )
			for( int j = 1 ; j <= m ; ++j )
				for( int I = i ; I <= n ; ++I )
					for( int J = j ; J <= m ; ++J )
					{
						int Sum = S[ I ][ J ] - S[ i - 1 ][ J ] - S[ I ][ j - 1 ] + S[ i - 1 ][ j - 1 ];
						if( Sum == ( ( I - i + 1 )*( J - j + 1 ) ) ) ans++;	
					}
		printf( "%d\n" , ans );
	}
}
