#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define N 10000
#define EPS (1e-8)
#define INF (1e100)

typedef long double ld;
typedef vector< int > vi;

struct Point{
	ld x , y;
	Point(){}
	Point( ld x , ld y ) : x( x ) , y( y ) {}
	ld dist(){ return sqrt( abs( x * x + y * y ) ); }
}P[ N + 5 ];
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
ld dist( Point A , Point B ){ return (B - A).dist(); }
bool equals( ld x , ld y ){ return abs( x - y ) < EPS; }
bool Less( ld x , ld y ){ return x < y - EPS ; }
struct cmpX{
	bool operator()( const Point &A , const Point &B ) const {
		if( !equals( A.x , B.x ) ) return Less( A.x , B.x );
		return Less( A.y , B.y );
	}
};
struct cmpY{
	bool operator()( const Point &A , const Point &B ) const {
		if( !equals( A.y , B.y ) ) return Less( A.y , B.y );
		return Less( A.x , B.x );
	}
};

int main(){
	int n;
	while( cin >> n ){
		if( !n ) break;
		REP( i , n ) cin >> P[ i ].x >> P[ i ].y;
		sort( P , P + n , cmpX() );
		ld H = INF;
		int lo = 0;
		set< Point , cmpY > SET;
		set< Point , cmpY > :: iterator y1 , y2 , y3;
		REP( i , n ){
			while( P[ i ].x - P[ lo ].x > H ){
				SET.erase( P[ lo ] );
				lo ++;
			}
			y1 = SET.lower_bound( Point( -INF , P[ i ].y - H ) );
			y2 = SET.lower_bound( Point( -INF , P[ i ].y + H ) );
			for( y3 = y1 ; y3 != y2 ; y3 ++ )
				H = min( H , dist( P[ i ] , *y3 ) );
			SET.insert( P[ i ] );
		}
		if( Less( H , 10000 ) ) printf( "%.4f\n" , (double)H );
		else  puts( "INFINITY" );
	}
}


