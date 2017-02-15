#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define SZ( v ) ((int)(v).size())

#define N 1000
#define M 10000

typedef float ld;
typedef vector< int > vi;

int n , m , Y;
bool used[ N + 1 ][ M + 1 ];
int memo[ N + 1 ][ M + 1 ];
int INF = INT_MAX/2;
int X[ N + 1 ];
const int d = 2;

int dp( int pos , int S ){
	if( pos == n ) return (S == 0) ? 0 : INF;
	if( used[ pos ][ S ] ) return memo[ pos ][ S ];
	used[ pos ][ S ] = 1;
	int &dev = memo[ pos ][ S ] = INF;
	int x = round( (ld)X[ pos ] * (ld)m / (ld)Y );
	for( int cur = max( 0 , x - d ) ; cur <= x + d ; ++cur ){
		if( S - cur >= 0 ){
			int temp = (X[ pos ] * m) - (cur* Y);
			dev = min( dev , abs( temp ) + dp( pos + 1 , S - cur ) );
		}
	}
	return dev;
}

vi vec;
void rec( int pos , int S ){
	if( pos == n ) return;
	int x = round( (ld)X[ pos ] * (ld)m / (ld)Y );
	for( int cur = max( 0 , x - d ) ; cur <= x + d ; ++cur ){
		if( S - cur >= 0 ){
			int temp = (X[ pos ] * m) - (cur* Y);
			if( dp( pos , S ) == (abs( temp ) + dp( pos + 1 , S - cur )) ){
				vec.push_back( cur );
				rec( pos + 1 , S - cur );
				return;
			}
		}
	}
}

int main(){
	freopen( "input.txt" , "r" , stdin );
	freopen( "output.txt" , "w" , stdout );
	while( sc( n ) == 1 ){
		sc( m ) , sc( Y );
		REP( i , n ) sc( X[ i ] );

		dp( 0 , m );
		rec( 0 , m );
		REP( i , SZ( vec ) ) printf( "%d%c" , vec[ i ] , (i + 1 == SZ(vec)) ? 10 : 32 );
	}
}


