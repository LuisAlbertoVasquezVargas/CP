#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define all( v ) v.begin() , v.end()
#define fi first
#define se second

#define test puts( "**************test************" );

#define EPS (1e-8)
#define PI acos(-1.0)

typedef long double ld;
typedef pair< ld , ld > pldld;

struct Point
{
	ld x , y;
	Point(){ x = y = 0; }
	Point( ld x , ld y ) : x( x ) , y( y ) {}
	ld dist(){ return sqrt( x*x + y*y );}
};
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
bool operator < ( const Point &A , const Point &B ){ return abs( A.x - B.x ) < EPS ? A.y < B.y - EPS : A.x < B.x - EPS;}
bool operator ==( const Point &A , const Point &B ){ return abs( A.x - B.x ) < EPS && abs( A.y - B.y ) < EPS;}
ld cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x;}
ld dot( const Point &A , const Point &B ){ return A.x*B.x + A.y*B.y;}
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A );}
ld get_angle( const Point &A , const Point &B ){ ld t = atan2( cross( A , B )  , dot( A , B ) );return abs( t + PI )< EPS ? PI: t;}
typedef vector< Point > Polygon;
Polygon convexHull( Polygon Poly ){
	int nP = Poly.size() , k = 0 ;
	sort( all( Poly ) );
	Point H[ nP << 1 ];
	REP( i , nP )
	{
		while( k >= 2 && area( H[ k - 2 ] , H[ k - 1 ] , Poly[ i ] ) < -EPS ) k--;
		H[ k++ ] = Poly[ i ];
	}
	for( int i = nP - 2 , sz = k ; i >= 0 ; --i )
	{
		while( k > sz && area( H[ k - 2 ] , H[ k - 1 ] , Poly[ i ] ) < -EPS ) k--;
		H[ k++ ] = Poly[ i ];
	}
	if( k == 0 ) return Polygon();
	return Polygon( H , H + k - 1 );
}
vector< vector< pldld > > T;
bool cmp( const vector< pldld > &A , const vector< pldld > &B ){ 
	int nA = A.size();
	REP( i , nA )
		if( abs( A[ i ].fi - B[ i ].fi ) > EPS || abs( A[ i ].se - B[ i ].se ) > EPS ) return 0;
	return 1;
}

int main()
{
	int n;
	double x , y;
	scanf( "%d" , &n );
	Polygon Poly1( n ) , Poly2( n ) , poly1 , poly2;
	REP( i , n )
	{
		scanf( "%lf%lf" , &x , &y );
		Poly1[ i ] = Point( x , y );
	}
	REP( i , n )
	{
		scanf( "%lf%lf" , &x , &y );
		Poly2[ i ] = Point( x , y );
	}
	if( n <= 1 )
	{
		printf( "%.7f\n" , 0.0 );
		return 0;
	}
	int m = n;
	poly1 = Poly1;
	poly2 = Poly2;
	Poly1 = convexHull( Poly1 );
	Poly2 = convexHull( Poly2 );
	n = Poly1.size();

	T = vector< vector< pldld > > ( n , vector< pldld >( m ) );
	
	REP( i , n ){
		REP( j , m )
			if( poly2[ j ] == Poly2[ i ] ){
				T[ i ][ j ].fi = 0;
				T[ i ][ j ].se = 0;
			}
			else{
				T[ i ][ j ].fi = get_angle( Poly2[ (i + 1)%n ] - Poly2[ i ] , poly2[ j ] - Poly2[ i ] );
				T[ i ][ j ].se = (poly2[ j ] - Poly2[ i ]).dist();
			}
		sort( all( T[ i ] ) );
	}
	vector< pldld > V( m );
	REP( j , m ){
		if( poly1[ j ] == Poly1[ 0 ] ){
			V[ j ].fi = V[ j ].se = 0;
		}else{
			V[ j ].fi = get_angle( Poly1[ 1 ] - Poly1[ 0 ] , poly1[ j ] - Poly1[ 0 ] );
			V[ j ].se = ( poly1[ j ] - Poly1[ 0 ] ).dist();
		}
	}
	sort( all( V ) );
	ld ans = 1e100;
	REP( i , n )
		if( cmp( T[ i ] , V ) )
			ans = min( ans , abs( get_angle( Poly1[ 1 ] - Poly1[ 0 ] , Poly2[ (i + 1)%n ] - Poly2[ i ] ) ) );
	printf( "%.7f\n" , double( ans ) );
}
