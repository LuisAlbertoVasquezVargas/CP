
#include<cstdio>
#include<queue>
#include<utility>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define sc( x ) scanf( "%d" , &x )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define mp make_pair

#define N 5005
#define M 1000005
#define INF (1<<30)
#define EPS (1e-8)

//#define SQ( x ) ((x)*(x))

typedef pair< int , int > pii;
typedef long long ll;

int n;
int X[ N ] , Y[ N ];
int DP[ M ] ;

inline ll SQ( const int &x ){ return (ll)x*x;}
int f()
{
	DP[ X[ n - 1 ] ] = 0;
	for( int i = X[ n - 1 ] - 1 ; i >= X[ 0 ] ; --i )
	{
		int &dev = DP[ i ] = INF;
		int ind = upper_bound( X , X + n , i ) - X;
		for( int k = ind ; k < n ; ++k )
			if( SQ( Y[ k ] ) - SQ( Y[ k ] - Y[ 0 ] ) >= SQ(X[ k ] - i) )
			{	
				if( k == n - 1 ) 
				{
					dev = 1;
					break;
				}
				int v = (X[ k ]<<1) - i;
				if( v >= X[ n - 1 ] ) break;
				dev = min( dev , DP[ v ] );
			}
	}
	return DP[ X[ 0 ] ] == INF ?-1:DP[ X[ 0 ] ];
}
int main()
{
	int cases;
	sc( cases );
	while( cases-- )
	{
		sc( n );
		REP( i , n ) sc( X[ i ] ) , sc( Y[ i ] );
		printf( "%d\n" , f() );
	}
}
