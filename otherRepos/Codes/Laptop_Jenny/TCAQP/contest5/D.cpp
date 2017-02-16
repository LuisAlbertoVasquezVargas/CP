#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define mp make_pair
#define fi first
#define se second

#define N 1000
#define EPS (1e-8)

typedef pair< int , int > pii;
typedef long double ld;

struct Point
{
	ld x , y;
	Point(){}
	Point( ld x , ld y ) : x( x ) , y( y ) {}
	Point ort(){ return Point( -y , x );}
	
};
typedef Point Vector;
Point operator + ( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y );}
Point operator - ( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
Point operator / ( const Point &A , const ld &K ){ return Point( A.x/K , A.y/K );}
Point operator * ( const Point &A , const ld &K ){ return Point( A.x*K , A.y*K );}
ld cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x;}
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A ); }

Point lineIntersection( const Point &A , const Point &B , const Point &C , const Point &D ){
	return A + ( B - A )*( cross( C - A , D - C ) / cross( B - A , D - C ) );
}
bool isInt( ld x ){ return abs( round( x ) - x ) < EPS; }
bool isInt( ld x , ld y ){ return isInt( x ) && isInt( y ); }
bool isInt( Point P ){ return isInt( P.x , P.y );}
int n;
int X[ N + 5 ] , Y[ N + 5 ];
set< pii > SET;
bool f( int ind ){
	for( int i = ind + 1 ; i < n ; ++i ){
		Point A( X[ ind ] , Y[ ind ] ) , B( X[ i ] , Y[ i ] );
		Point M = (A + B)/2.0;
		Vector V = ( B - A ) , VT = V.ort();
		bool solve = 1;
		REP( j , n ){
			if( j == ind ) continue;
			if( j == i ) continue;
			Point P( X[ j ] , Y[ j ] );
			Point I = lineIntersection( M , M + VT , P , P + V );
			Point Q = P + ( I - P )*2.0;
			if( !isInt( Q ) ) {
				solve = 0;
				break;
			}
			int x = (int)round( Q.x ) , y = (int)round( Q.y );
			if( !SET.count( mp( x , y ) ) ){
				solve = 0;
				break;
			}
		}
		if( solve ) return 1;
	}
	return 0;
}
bool solve(){
	Point A( X[ 0 ] , Y[ 0 ] ) , B( X[ 1 ] , Y[ 1 ] );
	Point VT = ( B - A ).ort();
	for( int i = 2 ; i < n ; ++i ){
		Point P( X[ i ] , Y[ i ] );
		Point I = lineIntersection( A , B , P , P + VT );
		Point Q = P + ( I - P )*2.0;
		if( !isInt( Q ) )
			return 0;
		int x = (int)round( Q.x ) , y = (int)round( Q.y );
		if( !SET.count( mp( x , y ) ) ) return 0;
	}
	return 1;
}
int main()
{
	int x , y;
	while( sc( n ) == 1 ){
		if( n == -1 ) break;
		SET.clear();
		REP( i , n ) sc( x ) , sc( y ) , X[ i ] = x , Y[ i ] = y , SET.insert( mp( x , y ) );
		if( f( 0 ) ){
			puts( "Y" );
			continue;
		}
		//	puts( "not solve for 0" );
		if( f( 1 ) ){
			puts( "Y" );
			continue;
		}
		//	puts( "not found" );
		puts( solve() ? "Y" : "N" );
	}
}
