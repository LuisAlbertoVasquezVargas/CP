#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define N 100
#define INF (1e100)
#define EPS (1e-8)

typedef long double ld;
#define Vector Point
struct Point
{
	ld x , y;
	Point(){}
	Point( ld x , ld y ) : x( x ) , y( y ){}
	ld dist2(){ return x*x + y*y; }
	Point ort(){ return Point( -y , x ); }
};

Point operator + ( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
Point operator - ( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
Point operator * ( const Point &A , const ld &K ){ return Point( A.x * K , A.y * K );}
Point operator / ( const Point &A , const ld &K ){ return Point( A.x / K , A.y / K );}
ld cross( const Point &A , const Point &B ){ return A.x * B.y - A.y * B.x ; }
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A ); }

ld dist( const Point &A , const Point &B ){ return ( B - A ).dist2(); }
bool isParallel( const Point &A , const Point &B , const Point &C , const Point &D ){
	return abs( cross( B - A , D - C ) ) < EPS;
}
bool between( const Point &A , const Point &B , const Point &P ){
	return 	min( A.x , B.x ) < P.x + EPS && P.x < max( A.x , B.x ) + EPS && 	
 			min( A.y , B.y ) < P.y + EPS && P.y < max( A.y , B.y ) + EPS;
}
bool onSegment( Point A , Point B , Point P ){
	return between( A , B , P ) && abs( area( A , B , P ) ) < EPS ;
}
Point lineIntersection( const Point &A , const Point &B , const Point &C , const Point &D ){
	return A + ( ( B - A ) * ( cross( C - A , D - C ) / cross( B - A , D - C ) ) );
}
ld distPointLine( Point A , Point B , Point P ){
	Vector V = ( B - A ) , VT = V.ort();
	Point I = lineIntersection( A , B , P , P + VT );
	if( onSegment( A , B , I ) ) return dist( I , P );
	return min( dist( P , A ) , dist( P , B ) );
}
ld distLineLine( Point A , Point B , Point C , Point D ){
	ld ans = distPointLine( C , D , A );
	ans = min( ans , distPointLine( C , D , B ) );
	ans = min( ans , distPointLine( A , B , C ) );
	ans = min( ans , distPointLine( A , B , D ) );
	return ans;		 
}

Point INNER[ N + 5 ] , OUTER[ N + 5 ];
int n , m;


ld solve(){
	ld ans = INF;
	REP( i , n ) REP( j , m ) 
		ans = min( ans , distLineLine( INNER[ i ] , INNER[ (i + 1)%n ] , OUTER[ j ] , OUTER[ (j + 1)%m ] ) );
	return sqrt( abs( ans ) )/2.0;
}
int main(){
	int cases , x , y;
	sc( cases );
	while( cases -- ){
		sc( n );
		REP( i , n ){
			sc( x ) , sc( y );
			INNER[ i ] = Point( x , y );
		}
		sc( m );
		REP( i , m ){
			sc( x ) , sc( y );
			OUTER[ i ] = Point( x , y );
		}
		printf( "%.10f\n" , (double)solve() );
	}
}
