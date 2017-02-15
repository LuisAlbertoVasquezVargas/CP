#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define N 10005
#define INF (1e100)

typedef long double ld;

int A[ N ] , B[ N ] , C[ N ];
int n;
ld eval( int a , int b , int c , ld x ){
	return a*x*x + b*x + c;
}
ld f( ld x ){
	ld maxi = -INF;
	REP( i , n ) maxi = max( maxi , eval( A[ i ] , B[ i ] , C[ i ] , x ) );
	return maxi;
}
int main()
{
	int cases;
	sc( cases );
	while( cases -- )
	{
		sc( n );
		REP( i , n ) sc( A[ i ] ) , sc( B[ i ] ) , sc( C[ i ] );
		ld lo = 0 , hi = 1000.0;
		REP( it , 75 ){
			ld med1 = ( 2*lo + hi )/3.0, med2 = ( lo + 2*hi )/3.0;
			if( f( med1 ) < f( med2 ) ) hi = med2;
			else lo = med1;
		}
		printf( "%.4f\n" , double( f( lo ) ) );
	}
}
