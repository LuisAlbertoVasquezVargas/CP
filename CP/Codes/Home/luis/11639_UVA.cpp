#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )

#define mp make_pair
#define fi first
#define se second

typedef pair< int , int > pii;

pii f( pii a , pii b ){
	if( a.fi > b.fi ) swap( a , b );
	if( b.fi >= a.se ) return mp( 0 , 0 );
	return mp( b.fi , min( a.se , b.se ) );
}
int main()
{
	int cases , tc = 0;
	sc( cases );
	while( cases -- )
	{
		int xlo1 , ylo1 , xhi1 , yhi1;
		int xlo2 , ylo2 , xhi2 , yhi2;
		sc( xlo1 ) , sc( ylo1 ) , sc( xhi1 ) , sc( yhi1 );
		sc( xlo2 ) , sc( ylo2 ) , sc( xhi2 ) , sc( yhi2 );
		pii x = f( mp( xlo1 , xhi1 ) , mp( xlo2 , xhi2 ) );
		pii y = f( mp( ylo1 , yhi1 ) , mp( ylo2 , yhi2 ) );
		int S1 = ( yhi1 - ylo1 )*( xhi1 - xlo1 );
		int S2 = ( yhi2 - ylo2 )*( xhi2 - xlo2 );
		int Sinter = ( x.se - x.fi )*( y.se - y.fi );
		int S = S1 + S2 - Sinter;
		printf( "Night %d: %d %d %d\n" , ++tc , Sinter ,  S - Sinter , 10000 - S );
	}
}
