#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define sc( x ) scanf( "%d" , &x )

#define N 200005
#define INF (1LL<<62)

typedef long long ll;

struct Point
{
	ll x , y;
	Point(){ x = y = 0; }
	Point( ll x , ll y ): x ( x ) , y( y ) {}
};
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
ll cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x;}
ll area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A );}

int n;
Point P[ N ];
ll AC[ N ];
// P is ordered counterclockwise
// 0 based
ll query( int x , int y ){
	if( y >= x )
		return AC[ y ] - AC[ x ] + area( Point() , P[ y ] , P[ x ] );
	swap( x , y );
	return AC[ n ] - (AC[ y ] - AC[ x ] + area( Point() , P[ y ] , P[ x ] ));
}
ll f( int i , int j )
{
	ll S = query( i , j );
	return abs( AC[ n ] - S - S );
}
int main()
{
	while( sc( n ) == 1 )
	{
		REP( i , n )
		{
			int x , y;
			sc( x ) , sc( y );
			P[ i ] = Point( x , y );
		}
		REP( i , n ) AC[ i + 1 ] = AC[ i ] + area( Point() , P[ i ] , P[ ( i + 1 )%n ] );
		ll mini = INF;
		int x , y;
		REP( i , n )
		{
			int lo = 1 , hi = n - 2;
			while( hi - lo > 4 )
			{
				int med1 = ( 2*lo + hi )/3;
				int med2 = ( lo + 2*hi )/3;
				if( f( i , ( i + med1 )%n ) < f( i , ( i + med2 )%n ) )
					hi = med2;
				else lo = med1;
			}
			//cout << i << endl;
			ll mini2 = INF;
			int ind = -1;
			for( int k = max( 1 , lo - 4 ) ; k <= min( n - 2 , hi + 4 ) ; ++k )
				if( f( i , ( i + k )%n ) < mini2 ) mini2 = f( i , ( i + k )%n ) , ind = k;
			if( mini2 < mini )
				x = i , y = ( i + ind )%n , mini = mini2;
		}
		//cout << mini << endl;
		printf( "%d %d\n" , x + 1 , y + 1 );
	}
}
