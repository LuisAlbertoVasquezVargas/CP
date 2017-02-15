#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define all( v ) v.begin() , v.end()

#define EPS (1e-8)

typedef long double ld;

struct Point
{
	ld x , y;
	Point(){}
	Point( ld x , ld y ) : x( x ) , y( y ) {}
	ld dist(){ return sqrt( x*x + y*y ); }
	void read(){ cin >> x >> y;}
};
bool operator < ( const Point A , const Point &B ){ return A.x == B.x ? A.y < B.y : A.x < B.x; }
Point operator - ( const Point A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
ld cross( const Point & A , const Point & B ){ return A.x*B.y - A.y*B.x; }
ld area( const Point & A , const Point & B , const Point &C ){ return cross( B - A  , C - A );}

typedef vector< Point > Polygon ;
Polygon convexHull( Polygon P )
{
	sort( all( P ) );
	int nP = P.size() , k = 0;
	Point H[ nP<<1 ];
	REP( i , nP )
	{
		while( k >= 2 && area( H[ k - 2 ] , H[ k - 1 ] , P[ i ] ) < EPS ) k--;
		H[ k++ ] = P[ i ];
	}
	for( int i = nP - 2 , sz = k ; i >= 0 ; --i )
	{
		while( k > sz && area( H[ k - 2 ] , H[ k - 1 ] , P[ i ] ) < EPS ) k--;
		H[ k++ ] = P[ i ];
	}
	if( k == 0 ) return Polygon();
	return Polygon( H , H + k - 1 );
}
int main()
{
	int cases;
	cin >> cases;
	REP( tc , cases )
	{
		if( tc )puts( "" );
		int n;
		cin >> n;
		Polygon P( n );
		REP( i , n ) P[ i ].read();
		P = convexHull( P );
		int nP = P.size();
		ld sum = 0;
		REP( i , nP ) sum += (P[ (i + 1)%nP ] - P[ i ]).dist();
		ld mini = 1e100;
		REP( i , nP )
		{
			ld d1 = P[ i ].dist() , d2 = P[ (i + 1)%nP ].dist();
			mini = sum - (P[ (i + 1)%nP ] - P[ i ]).dist() + d1 + d2 + 2; 
		}
		printf( "%.2f\n" , double( mini ) );
	}
}
