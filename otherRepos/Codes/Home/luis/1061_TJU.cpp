#include<bits/stdc++.h>

using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

struct Point
{
	int x , y , z;
	Point(){ x = y = z = 0 ;}
	Point( int x , int y , int z ) : x( x ) , y( y ) , z( z ) {}
};
Point operator -( const Point &A , const Point &B ){
	return Point( A.x - B.x , A.y - B.y , A.z - B.z );
}
Point cross( const Point &A , const Point &B ){
	return Point( A.y*B.z - A.z*B.y , -( A.x*B.z - A.z*B.x ) , A.x*B.y - A.y*B.x );
}
int dot( const Point &A , const Point &B ){
	return A.x*B.x + A.y*B.y + A.z*B.z;
}
int volume( Point A , Point B , Point C , Point D ){
	return dot( D - A , cross( B - A  , C - A ) );
}
int volume( Point A , Point B , Point C ){
	return A.x*B.y*C.z + A.y*B.z*C.x + A.z*B.x*C.y - ( A.z*B.y*C.x + A.y*B.x*C.z + A.x*B.z*C.y );
}
Point P[ 500 ];
int main()
{
	int cases , F , n , x , y , z ;
	sc( cases );
	
	while( cases -- ){
		sc( F );
		int ans = 0;
		REP( i , F ){
			sc( n );

			REP( j , n ) {
				sc( x ) , sc( y ) , sc( z ) ;
			 	P[ j ] = Point( x , y , z );
			}
			int temp = 0;
			for( int j = 0 ; j + 1 < n ; ++j )
			{
				//temp += volume( Q , P[ j ] , P[ (j + 1) ] );
				temp += volume( Point() , P[ 0 ] , P[ j ] , P[ (j + 1) ] );
			}
			cout << temp << " ";

			ans += temp;
		}
		cout << '\n';
		cout << "ans : " << ans/6 << '\n';
	}
	return 0;
}
