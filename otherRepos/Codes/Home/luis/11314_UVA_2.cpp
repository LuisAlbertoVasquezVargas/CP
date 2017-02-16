#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
struct Point
{
 	ld x , y;
 	Point(){ x = y = 0; }
 	Point( ld x , ld y ) : x( x ) , y( y ){}
 	ld dist(){ return sqrt( x*x + y*y );}
 	void print(){ printf( "%.4f %.4f\n" , double(x) , double(y) );}
}O;
Point operator - ( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
Point operator + ( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y );}
Point operator * ( const Point &A , const ld k ){ return Point( A.x * k , A.y * k );}
ld cross( const Point &A , const Point &B ){ return A.x * B.y - A.y * B.x;}
Point lineIntersection( const Point &A , const Point &B , const Point &C , const Point &D ){
	return A + ( ( B - A )*( cross( C - A , D - C ) / cross( B - A , D - C ) ) );
}
ld dist( const Point &A , const Point &B ){
	return ( B - A ).dist();
}
int main()
{
	int cases ;
	ld x , y , X , Y;
	cin >> cases;
	while( cases -- )
	{
		cin >> x >> y >> X >> Y;
		//cout << x << " " << y << " " << X << " " << Y << endl;
		if( x > X ) swap( x , X ) , swap( y , Y );
		Point A( x , y ) , B( X , Y );
		Point PA( -x , y ) , PB( X , -Y );
		Point YY( 0 , 1 ) , XX( 1 , 0 );
		//PA.print() , PB.print();
		Point IA = lineIntersection( PA , PB , O , YY );
		Point IB = lineIntersection( PA , PB , O , XX );
		//IB.print();IA.print();
		ld ans = dist( A , B ) + dist( B , IB ) + dist( IB , IA ) + dist( IA , A );
		printf( "%.3f\n" , double( ans ) );
	}
}
