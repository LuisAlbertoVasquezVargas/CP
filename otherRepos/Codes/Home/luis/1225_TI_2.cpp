#include<cstdio>

#define N 55
#define W 0
#define B 1
#define R 2

unsigned int DP[ N ][ 4 ];

int main()
{
	for( int last = 0 ; last < 4 ; last++ )DP[0][last] = 1;
	for( int n = 1 ; n < N ; ++n )
		for( int last = 0 ; last < 4 ; last++ )
		{
			unsigned int &dev = DP[n][last]; //= 0;
			for( int k = 0 ; k < 3 ; ++k )
			{
				if( last == k )continue;
				if( k == B )
				{
					if( n > 1 && ( last == W || last == R ) )
						dev += DP[ n - 2 ][ last==W?R:W ];
				}else dev += DP[ n - 1 ][ k ];
			}
		}
	int n;
	while( scanf( "%d" , &n ) == 1 )
		printf( "%u\n" , DP[n][3] );
}
