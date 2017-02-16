//#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define sc( x ) scanf( "%d" , &x )

#define N 1005
#define EPS (1e-6)

typedef double ld;

#define Vector Point

struct Point
{
	int x , y;
	Point(){}
	Point( int x , int y ) : x( x ) , y( y ) {}
	Point ort(){ return Point( -y , x ); }
	ld dist(){ return sqrt( (ld)x*x + (ld)y*y ); }
};
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y );}

inline bool intersects( Point P1 , Point P2 , Point P3 , Point P4 ){
	if( P1.x > P2.x ) swap( P1 , P2 );
	if( P3.x > P4.x ) swap( P3 , P4 );
	if( P3.x > P2.x || P4.x < P1.x ) return 0;
	if( P1.y > P2.y ) swap( P1 , P2 );
	if( P3.y > P4.y ) swap( P1 , P2 );
	if( P3.y > P2.y || P1.y > P4.y ) return 0;
	return 1;
}
ld distPointLineSegment( Point A , Point B , Point P ){
	if( A.x == B.x )
	{
		if( A.y > B.y ) swap( A , B );
		if( A.y <= P.y && P.y <= B.y ) return abs( P.x - A.x );
		if( P.y < A.y ) return ( A - P ).dist();
		return ( B - P ).dist();
	}
	else
	{
		if( A.x > B.x ) swap( A , B );
		if( A.x <= P.x && P.x <= B.x ) return abs( P.y - A.y );
		if( P.x < A.x ) return ( P - A ).dist();
		return ( P - B ).dist();
	}
}
ld distLineSegments( const Point &A , const Point &B , const Point &C , const Point &D ){
	if( intersects( A , B , C , D ) )return 0;
	return min( distPointLineSegment( A , B , C ) , distPointLineSegment( A , B , D ) );
}
Point A[ N ] , B[ N ];
int id[ N ] , rank[ N ];
int Find( int x ){ 
	if( x == id[ x ] ) return x;
	return id[ x ] = Find( id[ x ] );
}
void Union(int pa, int pb)
{
	if(pa != pb)
	{
		if(rank[pa] < rank[pb]) id[pa] = pb;
		else if(rank[pa] > rank[pb]) id[pb] = pa;
		else
		{
			id[pb] = pa;
			rank[pa]++;
		}
	}
}
bool g( int a , int b , int n , ld dist ){
	REP( i , n ) id[ i ] = i , rank[ i ] = 0;
	for( int i = 0 ; i < n ; ++i )
		for( int j = i + 1 ; j < n ; ++j )
		{
			if( Find( a ) == Find( b ) ) return  1;
			int pa = Find( i ) , pb = Find( j );
			if( pa != pb && distLineSegments( A[ i ] , B[ i ] , A[ j ] , B[ j ] ) < dist + EPS ) 
			{	
				Union( pa , pb );
			}
		}
	return Find( a ) == Find( b );
}
ld f( int a , int b , int n ){
	ld lo = 0 , hi = 1e5;
	REP( it , 25 )
	{
		ld med = ( lo + hi )/2;
		if( g( a , b , n , med ) ) hi = med;
		else lo = med;
	}
	return hi;
}
int main()
{
	int n , x , y , L;
	while( sc( n )== 1 )
	{
		if( n == 0 ) break;
		REP( i , n )
		{
			sc( x ) , sc( y ) , sc( L );
			A[ i ] = Point( x , y );
			if( L >= 0 )
				B[ i ] = Point( x + L , y );
			else B[ i ] = Point( x , y - L );
		}
		printf( "%.2f\n" , double( f( 0 , 1 , n ) ) );
	}
}
