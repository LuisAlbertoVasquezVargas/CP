#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define SZ(v) ((int)(v).size())
#define pb push_back
#define all( v ) v.begin() , v.end()

#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair< ll , ll > pll;
typedef vector< pll > vpll;
typedef vector< int > vi;
struct Point{
	ll x , y;
	Point(){x = y = 0LL;}
	Point( ll x , ll y ) : x( x ) , y( y ){}
};
Point operator - ( const Point &A , const Point &B ){
	return Point( A.x - B.x , A.y - B.y );
}
ll cross( const Point &A , const Point &B ){
	return A.x * B.y - A.y * B.x;
}
ll area( const Point &A , const Point &B , const Point &C ){
	return cross( B - A , C - A );
}
ll area( vector< Point > P ){
	int n = SZ( P );
	ll ans = 0;
	REP( i , SZ( P ) )
		ans += area( Point() , P[ i ] , P[ (i + 1)%n ] );
	return abs( ans );
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		vpll v;
		REP( i , n ){
			int m;
			sc( m );
			vector< Point > P;
			REP( i , m ){
				int x , y;
				sc( x ) , sc( y );
				P.pb( Point( x , y ) );
			}
			v.pb( mp( area( P ) , i ) );
		}
		sort( all( v ) );
		vi ans( n );
		REP( i , n ) ans[ v[ i ].se ] = i;
		REP( i , n ) printf( "%d%c" , ans[ i ] , (i + 1 == n) ? 10 : 32 );
	}
}
