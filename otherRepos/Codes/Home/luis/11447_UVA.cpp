#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define EPS (1e-8)

#define Polygon vector< Point >
typedef long double ld;

struct Point
{
	ld x , y;
	Point(){}
	Point( ld x , ld y ) : x( x ) , y( y ) {}
	void read() { cin >> x >> y; }
}O( 0 , 0 );
Point operator -( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
ld cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x;}
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A ); }
ld area( const Polygon &P )
{
	ld S = 0 ;
	int nP = P.size();
	REP( i , nP )
		S += area( O , P[ i ] , P[ i+1==nP?0:(i+1) ] );
	return abs( S );
}
int main()
{
	int tc;
	sc( tc );
	while( tc-- )
	{
		int n , W;
		sc( n );
		Polygon Poly( n );
		REP( i , n ) Poly[ i ].read();
		sc( W );
		ld PercentIni , spentWater , waterFall;
		cin >> PercentIni >> spentWater >> waterFall;
		PercentIni /= 100.0;
		ld s = area( Poly );
		ld SS = W*s/2.0 , S = SS;
		if( S*PercentIni < spentWater - EPS )
		{
			printf( "Lack of water. " );
			S = 0;
		}else S = S*PercentIni - spentWater;
		if( S + waterFall - EPS > SS )
		{
			printf( "Excess of water. " );
			S = SS;
		}else S += waterFall;
		printf( "Final percentage: %d" , int( 100.0*S/SS ) );
		puts( "%" );
	}	
}
