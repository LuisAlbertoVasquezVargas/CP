#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

struct Point
{
	int x , y;
	Point(){}
	Point( int x , int y ) : x( x ) , y( y ){}
	void read(){ sc( x ) , sc( y ); }
};
Point operator - ( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
int cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x;}
int area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A );}
bool between( const Point &A , const Point &B , const Point &P ){
	return min( A.x , B.x ) <= P.x && P.x <= max( A.x , B.x ) &&
	 	   min( A.y , B.y ) <= P.y && P.y <= max( A.y , B.y );
}
bool onSegment( const Point &A , const Point &B , const Point &P ){ 
	return area( A , B , P ) == 0 && between( A , B , P );
}
bool intersects( const Point &P1 , const Point &P2 , const Point &P3 , const Point &P4 )
{
	int A1 = area( P3 , P4 , P1 );
	int A2 = area( P3 , P4 , P2 );
	int A3 = area( P1 , P2 , P3 );
	int A4 = area( P1 , P2 , P4 );
	if( ( ( A1 > 0 && A2 < 0 ) || ( A1 < 0 && A2 > 0 ) ) &&
		( ( A3 > 0 && A4 < 0 ) || ( A3 < 0 && A4 > 0 ) ) ) return 1;
	if( onSegment( P3 , P4 , P1 ) ) return 1;
	if( onSegment( P3 , P4 , P2 ) ) return 1;
	if( onSegment( P1 , P2 , P3 ) ) return 1;
	if( onSegment( P1 , P2 , P4 ) ) return 1;
	return 0;
}
int main()
{
	int cases;
	sc( cases );
	while( cases -- )
	{
		int n;
		sc( n );
		vector< Point > A ( n ) , B( n );
		REP( i , n ) A[ i ].read() , B[ i ].read();
		int ans = 0;
		REP( i , n )
		{
			bool ok = 1;
			REP( j , n )
				if( i != j && intersects( A[ i ] , B[ i ] , A[ j ] , B[ j ] ) )
				{
					ok = 0;
					break;
				}
			ans += ok;
		}
		printf( "%d\n" , ans );
	}
}
