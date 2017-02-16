
//#include<bits/stdc++.h>
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
int dist[ M ] ;
double T[ N ];
inline double SQ( const int &x ){ return (double)x*x;}
int bfs()
{
	REP( k , n ) T[ k ] = sqrt( abs( SQ( Y[ k ] ) - SQ( Y[ k ] - Y[ 0 ] ) ) );
	clr( dist , -1 );
	queue< int >Q;
	Q.push( X[ 0 ] );
	dist[ X[ 0 ] ] = 0;
	while( !Q.empty() ){
		int u = Q.front();
		Q.pop();
		int ind = upper_bound( X , X + n , u ) - X;
		for( int k = ind ; k < n ; ++k )
			if( EPS + T[ k ] > X[ k ] - u )
			{
				if( k == n - 1 ) return dist[ u ] + 1;
				int v = (X[ k ]<<1) - u;
				if( v >= X[ n - 1 ] ) break;
				if( dist[ v ] == -1 )
				{
					Q.push( v );
					dist[ v ] = dist[ u ] + 1;
				}
			}
		}
	return dist[ X[ n - 1 ] ];
}
int main()
{
	int cases;
	sc( cases );
	while( cases-- )
	{
		sc( n );
		REP( i , n ) sc( X[ i ] ) , sc( Y[ i ] );
		printf( "%d\n" , bfs() );
	}
}
