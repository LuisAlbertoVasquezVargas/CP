#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 200000
#define IT 160

typedef long long ll;
typedef long double ld;
typedef pair< int , int > pii;
typedef vector< int > vi;

ld INF = 1e11;
int A[ N + 1 ];
ld a[ N + 1 ];
int n;
ld DP[ N + 1 ];
ld get(){
	DP[ 0 ] = a[ 0 ];
	for( int i = 1 ; i < n ; ++i )
		DP[ i ] = max( a[ i ] , a[ i ] + DP[ i - 1 ] );
	return *max_element( DP , DP + n );
}
ld f( ld x ){
	ld ans = 0;
	REP( i , n ) a[ i ] = (A[ i ] - x);
	ans = max( ans , get() );
	REP( i , n ) a[ i ] = -(A[ i ] - x);
	ans = max( ans , get() );
	return ans;
}
int main(){	
	while( sc( n ) == 1 ){
		REP( i , n ) sc( A[ i ] );
		ld lo = -INF , hi = INF;
		REP( it , IT ){
			ld med1 = (lo * 2.0 + hi)/3.0 , med2 = (lo + hi * 2.0)/3.0;
			if( f( med1 ) < f( med2 ) )
				hi = med2;
			else lo = med1;
		}
		printf( "%.15f\n" , (double) f( lo ) );
	}
}



