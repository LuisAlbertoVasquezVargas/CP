#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;
 
typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef double ld;

const ld EPS = 1e-8;
const ld PI = acos(-1.0);

inline bool equals( ld x , ld y ){ return abs( x - y ) < EPS; }
inline bool Less( ld x , ld y ){ return x < y - EPS; }
inline bool LessOrEquals( ld x , ld y ){ return Less( x , y ) || equals( x , y ); }
struct Point{
	ld x , y;
	Point(){ x = y = 0; }
	Point( ld x , ld y ) : x( x ) , y( y ) {}
	ld dist(){ return hypot( x , y );}
	Point ort(){ return Point( -y , x ); }
	void print(){ printf( "punto : %.4f %.4f\n" , double(x) , double(y) );}
};
typedef Point Vector;
Point operator - ( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
Point operator + ( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
Point operator * ( const Point &A , const ld &k ){ return Point( A.x * k , A.y * k ); }
bool operator == ( const Point &A , const Point &B ){ return equals( A.x , B.x ) && equals( A.y , B.y ) ; }

ld dot( const Point &A , const Point &B ){ return A.x * B.x + A.y * B.y ; }
ld cross( const Point &A , const Point &B ){ return A.x * B.y - A.y * B.x; }
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A ); }
ld dist( const Point &A , const Point &B ){ return (B - A).dist();}

Point lineIntersection( const Point &A , const Point &B , const Point &C , const Point &D ){
	return A + ( B - A ) * ( cross( C - A , D - C ) / cross( B - A , D - C ) );
}

typedef vector< Point > Polygon;

// line segment p-q intersect with line A-B.

// cuts polygon Q along the line formed by point a -> point b
// (note: the last point must be the same as the first point)
vector< Point > cutPolygon( Point a , Point b , Polygon Q ) {
	vector< Point > P;
	REP( i , SZ(Q) ){
		ld left1 = cross( b - a , Q[ i ] - a ) , left2 = 0;
		if( i != SZ(Q) - 1 ) left2 = cross( b - a , Q[ i + 1 ] - a );
		if( left1 > -EPS ) P.push_back( Q[ i ] );
		if (left1 * left2 < -EPS)
		P.push_back( lineIntersection( Q[ i ] , Q[ i + 1 ] , a , b ) );
	}
	
	if( !P.empty() && !(P.back() == P.front()) )
		P.push_back( P.front() );
	
	// make P’s first point = P’s last point
	return P;
}

int main(){
	int n;
	while( sc( n ) == 1 ){
		vi x( n ) , y( n );
		REP( i , n ) sc( x[ i ] ) , sc( y[ i ] );
		
		int xlo = *min_element( all( x ) ) - 1;
		int xhi = *max_element( all( x ) ) + 1;
		int ylo = *min_element( all( y ) ) - 1;
		int yhi = *max_element( all( y ) ) + 1;
		Polygon P;
		P.pb( Point( xlo , ylo ) );
		P.pb( Point( xhi , ylo ) );
		P.pb( Point( xhi , yhi ) );
		P.pb( Point( xlo , yhi ) );
		P.pb( Point( xlo , ylo ) );
		
		int maxi = INT_MIN , ind = -1;
		REP( i , n ){
			if( x[ i ] + y[ i ] > maxi ){
				maxi = x[ i ] + y[ i ];
				ind = i;
			}
		}
		Point a( x[ ind ] + 1 , y[ ind ] ) , b( x[ ind ] , y[ ind ] + 1 );
		P = cutPolygon( a , b , P );
		
		
		int mini = INT_MAX;
		REP( i , n ){
			if( x[ i ] + y[ i ] < mini ){
				mini = x[ i ] + y[ i ];
				ind = i;
			}
		}
		a = Point( x[ ind ] - 1 , y[ ind ] ) , b = Point( x[ ind ] , y[ ind ] - 1 );//(+1 , -1)
		P = cutPolygon( a , b , P );
		
		
		maxi = INT_MIN;
		REP( i , n ){
			if( y[ i ] - x[ i ] > maxi ){
				maxi = y[ i ] - x[ i ];
				ind = i;
			}
		}
		a = Point( x[ ind ] , y[ ind ] + 1 ) , b = Point( x[ ind ] - 1 , y[ ind ] );
		P = cutPolygon( a , b , P );
		
		
		mini = INT_MAX;
		REP( i , n ){
			if( y[ i ] - x[ i ] < mini ){
				mini = y[ i ] - x[ i ];
				ind = i;
			}
		}
		a = Point( x[ ind ] , y[ ind ] - 1 ) , b = Point( x[ ind ] + 1 , y[ ind ] );
		P = cutPolygon( a , b , P );
		
		ld ans = 0;
		REP( i , SZ(P) - 1 ) ans += dist( P[ i ] , P[ i + 1 ] );
		/*
		test();
		for( auto p : P ) cout << p.x << " " << p.y << endl;
		*/
		printf( "%.15f\n" , (double) ans );
	}
}



