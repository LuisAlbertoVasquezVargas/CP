#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define N 200
#define INF (1e10)

typedef vector< int > vi;
typedef long double ld;

struct Point{
	ld x ,y;
	Point(){ x = y = 0;}
	Point( ld x , ld y ) : x( x ) , y( y ) {}
	ld dist(){ return hypot( x , y );}
};

Point operator - ( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
Point operator + ( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y );}
ld dist( const Point &A , const Point &B ){ return (B - A).dist();}
Point P[ N + 5 ];
bool used[ N + 5 ][ N + 5 ];
ld memo[ N + 5 ][ N + 5 ];
int n;
ld Dist( int a , int b ){
	if( (a + 1)%n == b ) return 0;
	return dist( P[ a ] , P[ b ] );
}
ld dp( int lo , int hi ){
	if( (lo + 3)%n == hi ) return 0;
	if( (lo + 2)%n == hi ) return 0;
	if( (lo + 1)%n == hi ) return 0;
	if( (lo + 0)%n == hi ) return 0;
	if( used[ lo ][ hi ] ) return memo[ lo ][ hi ];
	used[ lo ][ hi ] = 1;
	ld &dev = memo[ lo ][ hi ] = INF;
	for( int i = (lo + 1)%n ; i != hi ; i = (i + 2)%n )
		for( int j = (i + 1)%n ; j != (hi + 1)%n ; j = (j + 2)%n ){
			dev = min( dev , Dist( lo , i ) + Dist( i , j ) + Dist( j , hi ) + dp( lo , i ) + dp( i , j ) + dp( j , hi ) );
		}
	return dev;
}
int main(){
	while( sc( n ) == 1 ){
		n *= 2;
		REP( i , n ){
			double x , y;
			scanf( "%lf%lf" , &x , &y );
			P[ i ] = Point( x , y );
		}
		clr( used , 0 );
		printf( "%.4f\n" , (double) dp( 0 , n - 1 ) );
	}	
}
