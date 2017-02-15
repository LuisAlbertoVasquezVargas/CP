#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef vector< int > vi;

#define EPS (1e-8)

#define Vector Point

typedef double ld;
typedef long long ll;

inline bool equals( ld x , ld y ){ return abs( x - y ) < EPS; }
inline bool Less( ld x , ld y ){ return x < y - EPS; }
inline bool LessOrEquals( ld x , ld y ){ return Less( x , y ) || equals( x , y ); }

struct Point{
	ld x , y;
	Point(){ x = y = 0; }
	Point( ld x , ld y ) : x( x ) , y( y ) {}
	Point ort(){ return Point( -y , x ); }
};
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
Point operator *( const Point &A , const ld &k ){ return Point( A.x * k , A.y * k ); }
Point operator /( const Point &A , const ld &k ){ return Point( A.x / k , A.y / k );}

ld cross( const Point &A , const Point &B ){ return A.x * B.y - A.y * B.x; }
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A ); }
Point lineIntersection( const Point &A , const Point &B , const Point &C , const Point &D ){
	return A + ( B - A )*( cross( C - A , D - C ) / cross( B - A , D - C ) );
}

struct rPoint{
	ll x , y;
	rPoint(){ x = y = 0; }
	rPoint( ll x , ll y ) : x( x ) , y( y ) {}
	rPoint ort(){ return rPoint( -y , x ); }
};
rPoint operator -( const rPoint &A , const rPoint &B ){ return rPoint( A.x - B.x , A.y - B.y ); }
rPoint operator +( const rPoint &A , const rPoint &B ){ return rPoint( A.x + B.x , A.y + B.y ); }
bool operator ==( const rPoint &A , const rPoint &B ){ return A.x == B.x && A.y == B.y ; }

ll cross( const rPoint &A , const rPoint &B ){ return A.x * B.y - A.y * B.x; }
ll area( const rPoint &A , const rPoint &B , const rPoint &C ){ return cross( B - A , C - A ); }


Point P[ 3 ];
rPoint rP[ 3 ];

int main(){
	//int x , y;
	ld x , y;
	while( cin >> x >> y ){

		P[ 0 ] = Point( x , y );
		REP( i , 3 ){
			if( !i ) continue;
			cin >> x >> y;
			P[ i ] = Point( x , y );

		}
		Point I;

		if( equals( area( P[ 0 ] , P[ 1 ] , P[ 2 ] ) , 0.0 ) ){
			puts( "Impossible" );
			continue;
		}
		Point M = (P[ 0 ] + P[ 1 ])/2.0;
		Vector V = (P[ 1 ] - P[ 0 ]).ort();
		Point N = (P[ 1 ] + P[ 2 ])/2.0;
		Vector W = (P[ 2 ] - P[ 1 ]).ort();
		I = lineIntersection( M , M + V , N , N + W );
		cout << I.x << " " << I.y << '\n';
		//printf( "%.6lf %.6lf\n" , (double)I.x , (double)I.y );
	}	
}


