#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define all( v ) v.begin() , v.end()
#define sc( x ) scanf( "%d" , &x )

#define pb push_back

#define EPS (1e-8)

typedef long double ld;
typedef long long ll;
struct Point
{
	ll x , y;
	Point(){}
	Point( int x , int y ) : x( x ) , y( y ) {}
	void read(){ sc( x ) , sc( y ); }
};
bool operator < ( const Point A , const Point &B ){ return A.x == B.x ? A.y < B.y : A.x < B.x; }
Point operator - ( const Point A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
ll cross( const Point & A , const Point & B ){ return A.x*B.y - A.y*B.x; }
ll area( const Point & A , const Point & B , const Point &C ){ return cross( B - A  , C - A );}

typedef vector< Point > Polygon ;
Polygon convexHull( Polygon P )
{
	sort( all( P ) );
	int nP = P.size() , k = 0;
	Point H[ nP<<1 ];
	REP( i , nP )
	{
		while( k >= 2 && area( H[ k - 2 ] , H[ k - 1 ] , P[ i ] ) < 0 ) k--;
		H[ k++ ] = P[ i ];
	}
	for( int i = nP - 2 , sz = k ; i >= 0 ; --i )
	{
		while( k > sz && area( H[ k - 2 ] , H[ k - 1 ] , P[ i ] ) < 0 ) k--;
		H[ k++ ] = P[ i ];
	}
	if( k == 0 ) return Polygon();
	return Polygon( H , H + k - 1 );
}

int main()
{
	int cases;
	sc( cases );
	while( cases-- )
	{
		int n;
		sc( n );
		Polygon P;
		REP( i , n )
		{
			int x , y;
			char s[ 5 ];
			scanf( "%d%d%s" , &x , &y , s );
			if( s[ 0 ] == 'Y' )
				P.pb( Point( x , y ) );
		}
		P = convexHull( P );
		int nP = P.size();
		printf( "%d\n" , nP );
		REP( i , nP )
			printf( "%d %d\n" , P[ i ].x , P[ i ].y );
	}
}
