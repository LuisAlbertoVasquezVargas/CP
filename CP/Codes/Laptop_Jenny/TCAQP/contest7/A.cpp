#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define sc( x ) scanf( "%d" , &x )

#define pb push_back
#define all( v ) v.begin() , v.end()

typedef long long ll;
typedef unsigned long long ull;
typedef vector< ull > vull;
typedef long double ld;

struct Point{
	ld x , y;
	Point(){ x = y = 0; }
	Point( ld x , ld y ) : x( x ) , y( y ) {}
}O;
Point operator + ( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y );}
Point operator - ( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
ld cross( const Point &A , const Point &B ){ return A.x * B.y - A.y * B.x ; }
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A );}
vector< Point > P;
int main()
{
	int k ;
	ld x , y;
	while( sc( k ) == 1 ){
		if( !k ) break;
		P.resize( k );
		ld S = 0;
		REP( i , k ){
			cin >> x >> y;
			P[ i ] = Point( x , y );
		}
		REP( i , k ) S += area( O , P[ i ] , P[ (i + 1)%k ] );
		S /= 2 ;
		S = round( abs( S ) );
		int ans = int( S );
		printf( "%d\n" , ans );
	}
}
