#include<cstdio>

#define N 105

short A[N][N] , S[N][N];

int main()
{
	short n , m;
	while( scanf( "%hd%hd" , &n , &m ) == 2 && n )
	{
		for( int i = 0 ; i < n ; ++i )
			for( int j = 0 ; j < m ; ++j )
				scanf( "%hd" , &A[i][j] );
		for( int i = 0 ; i <= n ; ++i )
			S[i][m] = 0;
		for( int j = 0 ; j <= m ; ++j )
			S[n][j] = 0;
		for( int i = n - 1 ; i >= 0 ; --i )
			for( int j = m - 1 ; j >= 0 ; --j )
				S[i][j] = S[i][j+1] + S[i+1][j] - S[i+1][j+1] + A[i][j];
		short maxi = 0;
		for( int i = 0 ; i < n ; ++i )
			for( int I = i ; I < n ; ++I )
				for( int j = 0 ; j < m ; ++j )
					for( int J = j ; J < m ; ++J )
					{
						short s = S[i][j] - S[i][J+1] - S[I+1][j] + S[I+1][J+1];
						if( s )break;
						short t = (I - i + 1 )*( J - j + 1 );
						if( s == 0 && maxi < t )
							maxi = t;
					}
		printf( "%hd\n" , maxi );
	}
}



