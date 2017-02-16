#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define sc( x ) scanf( "%d" , &x )

#define EPS (1e-8)
#define IT (50)

typedef long double ld;
struct Point
{
	ld x , y;
	Point(){ x = y = 0; }
	Point( ld x , ld y ) : x( x ) , y( y ){}
	ld dist(){ return sqrt( x*x + y*y ); }
	Point unit(){ ld k = dist() ; return abs( k ) < EPS ? Point():Point( x/k , y/k );}
	Point ort(){ return Point( -y , x );}
	void print(){ printf( "%.6f %.6f\n" , double( x ) , double( y ) ); }
};
Point operator + ( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y );}
Point operator - ( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
Point operator * ( const Point &A , const ld &k ){ return Point( A.x*k , A.y*k );}
Point operator / ( const Point &A , const ld &k ){ return Point( A.x/k , A.y/k );}
ld cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x;}
Point lineIntersection( const Point &A , const Point &B , const Point &C , const Point &D ){
	return A + ( B - A )*( cross( C - A , D - C )/cross( B - A , D - C ) );
}
typedef Point Vector;
Point bisectrix( Point V , Point W ){
	return ( V.unit() + W.unit() ).unit();
}
ld distPointLine( Point A , Point B , Point C ){
	Point H = lineIntersection( A , B , C , C + ( B - A ).ort() );
	return ( H - C ).dist();
}
ld h( Point PV , Vector V , ld LV , Point PW , Vector W , ld LW ){
	Point A = PV + ( V*LV );
	Point B = PW + ( W*LW );
	return (A - B).dist() - distPointLine( PV , PW , A ) - distPointLine( PV , PW , B );
}
ld g( Point PV , Vector V , ld LV , Point PW , Vector W , ld maxvalue )
{
	ld lo = 0 , hi = maxvalue;
	REP( it , IT ){
		ld med = ( lo + hi )/2;
		if( h( PV , V , LV , PW , W , med ) < 0 ) hi = med;
		else lo = med;
	}
	return lo;
}
Point P[ 5 ];
ld solvex , solvey , solvez ;
bool solve = 0;
ld f( Point O , Vector U , Vector V , Vector W , ld x )
{
	ld y = g( P[ 0 ] , U , x , P[ 1 ] , V , ( O - P[ 1 ] ).dist() );
	ld z = g( P[ 0 ] , U , x , P[ 2 ] , W , ( O - P[ 2 ] ).dist() );
	if( solve )solvex = x , solvey = y , solvez = z;
	return h( P[ 1 ] , V , y , P[ 2 ] , W , z );
}
int main()
{
	int X[ 5 ] , Y[ 5 ];
	
	while( sc( X[ 0 ] ) == 1 )
	{
		sc( Y[ 0 ] );
		for( int i = 1 ; i < 3 ; ++i ) cin >> X[ i ] >> Y[ i ];
		if( X[ 0 ] == 0 && Y[ 0 ] == 0 && X[ 1 ] == 0 && Y[ 1 ]  == 0 && X[ 2 ] == 0 && Y[ 2 ] == 0 ) break;
		REP( i , 3 ) P[ i ] = Point( X[ i ] , Y[ i ] );
		Vector U , V , W;
		U = bisectrix( P[ 1 ] - P[ 0 ] , P[ 2 ] - P[ 0 ] );
		V = bisectrix( P[ 0 ] - P[ 1 ] , P[ 2 ] - P[ 1 ] );
		W = bisectrix( P[ 0 ] - P[ 2 ] , P[ 1 ] - P[ 2 ] );
		Point O = lineIntersection( P[ 0 ] , P[ 0 ] + U , P[ 1 ] , P[ 1 ] + V );
		ld lo = 0 , hi = ( O - P[ 0 ] ).dist() ;
		REP( it , IT )
		{
			ld med = ( lo + hi )/2;
			if( f( O , U , V , W , med ) > 0 ) hi = med;
			else lo = med;
		}
		solve = 1;
		f( O , U , V , W , lo );
		solve = 0;
		Point A = P[ 0 ] + ( U*solvex );
		Point B = P[ 1 ] + ( V*solvey );
		Point C = P[ 2 ] + ( W*solvez );
		//A.print() , B.print() , C.print();
		ld R1 = distPointLine( P[ 0 ] , P[ 1 ] , A );
		printf( "%.6f " , double( R1 ) );
		ld R2 = distPointLine( P[ 0 ] , P[ 1 ] , B );
		printf( "%.6f ", double( R2 ) );
		ld R3 = distPointLine( P[ 0 ] , P[ 2 ] , C );
		printf( "%.6f\n" , double( R3 ) );
	}
}
