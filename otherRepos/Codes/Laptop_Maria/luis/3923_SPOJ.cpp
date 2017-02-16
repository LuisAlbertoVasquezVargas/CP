#include <cstdio>
#include<algorithm>
#include<cstring>

#define REP(i,n) for(int i=0;i<(n);i++)
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )

#define N 105
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , m , tc ;
int A[N][N];
int memo[N][N];

int dp( int x , int y )
{
	if( x == n )return 0;
	int &dev = memo[ x ][ y ];
	if( dev == -1 )
	{
		if( y )
			dev = max( dev , A[x][y] + dp( x + 1 , y - 1 ) );
		dev = max( dev , A[x][y] + dp( x + 1 , y ) );
		if( y + 1 < m )
			dev = max( dev , A[x][y] + dp( x + 1 , y + 1 ) );
	}
	return dev;
}
int main()
{
	sc( tc );
	while( tc -- )
	{
		sc( n ) , sc( m );
		REP( i , n )REP( j , m ) sc( A[i][j] );
		me( memo , -1 );
		int maxi = 0;
		REP( j , m ) maxi = max( maxi , dp( 0 , j ) );
		printf( "%d\n" , maxi );
	}
}


