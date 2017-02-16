#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define PI acos( -1.0 )

int main()
{
	ld cte = 1/( cos( 9*PI/180 ) - sin( 9*PI/180 )/( tan( 72*PI/180 )) );
	ld L;
	while( cin >> L )
		printf( "%.10f\n" , double( cte*L ) );
}
