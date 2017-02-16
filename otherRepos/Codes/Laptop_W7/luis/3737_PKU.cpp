#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	long double S , pi = acos( -1.0 );
	while( cin >> S )
	{
		long double r2 = S/( 4*pi );
		long double r = sqrt( r2 );
		long double t = (S - pi*r*r)/(pi*r);
		long double t2 = t*t;
		long double H = sqrt( t2 - r2 );
		printf( "%.2f\n" , double( pi*r2*H/3.0 ) );
		printf( "%.2f\n" , double( H ) );
		printf( "%.2f\n" , double( r ) );
	}

}


