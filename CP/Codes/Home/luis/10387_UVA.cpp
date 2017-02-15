#include<bits/stdc++.h>
using namespace std;

#define PI acos( -1.0 )

typedef long double ld;

int main()
{
	int a , b , s , m , n;
	while( scanf( "%d%d%d%d%d" , &a , &b , &s , &m , &n ) == 5 )
	{
		if( a == 0 ) break;
		ld x = a*m , y = b*n; 
		ld ang = atan( 1.0*y/x );
		ld t = 1.0*sqrt( x*x + y*y )/s;
		printf( "%.2f %.2f\n" , double( ang*(180/PI) ) , double( t ) );
	}
}
