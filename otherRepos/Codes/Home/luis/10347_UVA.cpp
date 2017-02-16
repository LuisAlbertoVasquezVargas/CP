#include<bits/stdc++.h>
using namespace std;

typedef long double ld;

int main()
{
	ld a , b , c;
	while( cin >> a >> b >> c )
	{
		if( a > b ) swap( a , b );
		if( a > c ) swap( a , c );
		if( b > c ) swap( b , c );
		if( c >= a + b ){
			puts( "-1.000" );
			continue;
		}
		ld p = ( a + b + c )/2;
		ld S = sqrt( p * ( p - a ) * ( p - b ) * ( p - c ) );
		printf( "%.3lf\n" , double( 4.0*S/3.0 ) );
	}
}
