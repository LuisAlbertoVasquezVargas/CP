#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++ i )
#define sc( x ) scanf( "%d", &x )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define all( v ) v.begin() , v.end()
#define mp make_pair
#define pb push_back

#define cte 2001
#define N 4008
#define EPS (1e-8)
#define PI acos(-1.0)

#define Vector Point

typedef pair< int , int > pii;
typedef double ld;
struct Point
{
	ld x , y;
	Point(){ x = y = 0;}
	Point( ld x , ld y ) : x( x ) , y( y ) {}
	ld dist(){ return sqrt( x*x + y*y );}
	Point unit(){ ld k = dist() ; return abs( k ) < EPS ? Point() : Point( x/k , y/k ); }
	Point ort(){ return Point( -y , x );}
};
Point operator - ( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
Point operator + ( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y );}
Point operator * ( const Point &A , const ld &k ){ return Point( A.x*k , A.y*k );}
ld cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x;}
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A );}
Point lineIntersection( const Point &A , const Point &B , const Point &C , const Point &D ){
	return A + ( B - A )*( cross( C - A , D - C ) / cross( B - A , D - C ) );
}
//bool VIS[ N ][ N ];
//set< pii >VIS;
vector < pii > VIS;
int X[ N ] , Y[ N ];
int n;
inline bool isInt( const ld &x ){
	return abs( x - round( x ) ) < EPS;
}
bool f( const int &a , const int &b )
{
	Point A( X[ a ] , Y[ a ] ) , B( X[ b ] , Y[ b ] ) , C = ( A + B )*0.5;
	Vector V = ( B - A );
	REP( i , n )
	{
		if( i == a || i == b ) continue;
		Point P( X[ i ] , Y[ i ] );
		Point I = lineIntersection( C , C + V.ort() , P , P + V );
		Point Q = I*2 - P;
		if( isInt( Q.x ) && isInt( Q.y ) )
		{
			int x = round( Q.x ) , y = round( Q.y );
			if( !binary_search( all( VIS ) , mp( x , y ) ) ) return 0;
		}else return 0;
	}
	return 1;
}
bool solve()
{
	for( int i = 1 ; i < n ; ++i )
		if( f( 0 , i ) ) return 1;
	for( int i = 2 ; i < n ; ++i )
		if( f( 1 , i ) ) return 1;
	Point A( X[ 0 ] , Y[ 0 ] ) , B( X[ 1 ] , Y[ 1 ] );
	for( int i = 2 ; i < n ; ++i )
	{
		Point P( X[ i ] , Y[ i ] );
		Point I = lineIntersection( A , B  , P , P + ( B - A ).ort() );
		Point Q = I*2 - P;
		if( isInt( Q.x ) && isInt( Q.y ) )
		{
			int x = round( Q.x ) , y = round( Q.y );
			if( !binary_search( all( VIS ) , mp( x , y ) ) ) return 0;
		}
		else return 0;
	}
	return 1;
}
int main()
{
	int x , y ;
	while( sc( n ) == 1 )
	{
		if( n == -1 ) break;
		//clr( VIS , 0 );
		VIS.clear();
		VIS.resize( n );
		REP( i , n ) {
			sc( x ) , sc( y );
			X[ i ] = x , Y[ i ] = y;
			//VIS[ x + cte ][ y + cte ] = 1;
			//VIS.insert( mp( x , y ) );
			VIS[ i ] =  mp( x , y );
		}
		sort( all( VIS ) );
		puts( solve() ? "Y" : "N" );
	}
}
