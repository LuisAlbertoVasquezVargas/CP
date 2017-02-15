#include<bits/stdc++.h>
using namespace std;

#define REP( i , n )for( int i = 0 ; i < n ; ++i )
#define all( v ) v.begin() , v.end()
#define pb push_back
 
#define EPS (1e-8)

typedef long double ld;

struct Point
{
	ld x , y;
	Point(){}
	Point( ld x , ld y ) : x( x ) , y( y ) {}
	void read(){ cin >> x >> y; }
};
typedef vector< Point > Polygon;
bool operator < ( const Point &A , const Point &B ){ return abs( A.x - B.x ) < EPS ? A.y < B.y - EPS: A.x < B.x - EPS ; }
bool operator == ( const Point &A , const Point &B ){ return abs( A.x - B.x ) < EPS ? abs( A.y - B.y ) < EPS: 0 ; }
Point operator + ( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
Point operator - ( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
Point operator * ( const Point &A , const ld k ){ return Point( A.x * k , A.y * k ); }
ld cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x;}
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A );}
bool between( const Point &A , const Point &B , const Point &P ){
	return min( A.x , B.x ) < P.x + EPS && P.x < max( A.x , B.x ) + EPS &&
		   min( A.y , B.y ) < P.y + EPS && P.y < max( A.y , B.y ) + EPS ;
}
bool onSegment( const Point &A , const Point &B , const Point &P ){
	return abs( area( A , B , P ) ) < EPS && between( A , B , P );
}
bool intersects( const Point &P1 , const Point &P2 , const Point &P3 , const Point &P4 ){
	ld A1 = area( P3 , P4 , P1 );
	ld A2 = area( P3 , P4 , P2 );
	ld A3 = area( P1 , P2 , P3 );
	ld A4 = area( P1 , P2 , P4 );
	if( ( ( A1 > EPS && A2 < -EPS ) || ( A1 < -EPS && A2 > EPS ) ) && 
		( ( A3 > EPS && A4 < -EPS ) || ( A3 < -EPS && A4 > EPS ) ) ) return 1;
	if( onSegment( P3 , P4 , P1 ) ) return 1;
	if( onSegment( P3 , P4 , P2 ) ) return 1;
	if( onSegment( P1 , P2 , P3 ) ) return 1;
	if( onSegment( P1 , P2 , P4 ) ) return 1;
	return 0;
}
Point lineIntersection( const Point &A , const Point &B , const Point &C , const Point &D ){
	return A + ( B - A )*( cross( C - A , D - C )/cross( B - A , D - C ) );
}
bool sameLine( const Point &P1 , const Point &P2 , const Point &P3 , const Point &P4 ){
	return abs( area( P1 , P2 , P3 ) ) < EPS && abs( area( P1 , P2 , P4 ) ) < EPS;
}
bool pointInPoly(const vector <Point> &P, const Point &A)
{
    int nP = P.size(), cnt = 0;
    for( int i = 0 ; i < nP ; i++ )
    {
        int inf = i , sup = ( i + 1 )%nP;
        if( P[ inf ].y > P[ sup ].y ) swap( inf , sup );
        if( P[ inf ].y <= A.y && A.y < P[ sup ].y )
            if( area( A , P[ inf ] , P[ sup ] ) > 0 )
                cnt++;
    }
    return (cnt % 2) == 1;
}

int main()
{
	int n , m;
	while( cin >> n )
	{
		if( n < 3 )break;
		Polygon P1( n );
		REP( i , n ) P1[ i ].read();
		cin >> m;
		if( m < 3 )break;
		Polygon P2( m );
		REP( i , m ) P2[ i ].read();
		vector< Point >P;
		REP( i , n ) REP( j , m )
			if( intersects( P1[ i ] , P1[ (i + 1)%n ] , P2[ j ] , P2[ ( j + 1 )%m ] ) )
			{
				Point I = lineIntersection( P1[ i ] , P1[ (i + 1)%n ] , P2[ j ] , P2[ ( j + 1 )%m ] );
				P.pb( I );
			}
		REP( i , n ) REP( j , m )
			if( onSegment( P1[ i ] , P1[ ( i + 1 )%n ] , P2[ j ] ) )
				P.pb( P2[ j ] );
		REP( i , n ) REP( j , m )
			if( onSegment( P2[ j ] , P2[ ( j + 1 )%m ] , P1[ i ] ) )
				P.pb( P1[ i ] );
		REP( j , m )
			if( pointInPoly( P1 , P2[ j ] ) )
				P.pb( P2[ j ] );
		REP( i , n )
			if( pointInPoly( P2 , P1[ i ] ) )
				P.pb( P1[ i ] );
		sort( all( P ) );
		P.resize( unique( all( P ) ) - P.begin() );
		int nP = P.size();
		printf( "%d\n" , nP );
		REP( i , nP )
			printf( "%.2f %.2f\n" , double( P[ i ].x ) , double( P[ i ].y ) );
	}
}
