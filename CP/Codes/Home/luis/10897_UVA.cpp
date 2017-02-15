#include<bits/stdc++.h>
using namespace std;

#define R 6371.01
#define PI acos( -1.0 )

typedef long double ld;

int main()
{
	int cases;
	cin >> cases;
	while( cases -- )
	{
		ld degrees , minutes , seconds;
		string dir;
		cin >> degrees >> minutes >> seconds >> dir;
		ld latitude = degrees + minutes/60 + seconds/3600;
		latitude *= ( PI/180 );
		if( dir == "N" ) latitude = -latitude;
		cin >> degrees >> minutes >> seconds >>dir;
		ld longitude = degrees + minutes/60 + seconds/3600 ;
		longitude *= ( PI/180 );
		if( dir == "E" ) longitude = 2*PI - longitude;
		ld a1 = latitude , b1 = longitude;
		cin >> degrees >> minutes >> seconds >> dir;
		latitude = degrees + minutes/60 + seconds/3600;
		latitude *= ( PI/180 );
		if( dir == "N" ) latitude = -latitude;
		cin >> degrees >> minutes >> seconds >>dir;
		longitude = degrees + minutes/60 + seconds/3600 ;
		longitude *= ( PI/180 );
		if( dir == "E" ) longitude = 2*PI - longitude;
		ld a2 = latitude , b2 = longitude;
		printf( "%.2f\n" , double( R*( acos( sin( a1 )*sin( a2 ) + cos( a1 )*cos( a2 )*cos( b1 - b2 ) ) ) ) );
	}
}
