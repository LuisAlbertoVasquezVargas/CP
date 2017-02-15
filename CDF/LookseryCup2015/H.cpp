#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define SZ( v ) ((int)(v).size())
#define all( v ) v.begin() , v.end()

#define mp make_pair
#define fi first
#define se second

#define EPS (1e-9)
typedef long long ll;
typedef vector< int > vi;
typedef long double ld;
typedef vector< ld > vld;
typedef pair< ld , ld > pld;

ld A[ 2 ][ 2 ];
pld mult( ld a , ld b , ld c , ld d ){
	vld x;
	x.pb( a * c ) , x.pb( a * d );
	x.pb( b * c ) , x.pb( b * d );
	sort( all( x ) );
	return mp( x[ 0 ] , x[ 3 ] );
}
bool inter( pld X , pld Y ){
	if( X.fi > Y.fi ) swap( X , Y );
	return Y.fi <= X.se;
}
bool solve( ld x , vld lo , vld hi ){
	return inter( mult( x , x , lo[ 0 ] , hi[ 0 ] ) , mult( lo[ 1 ] , hi[ 1 ] , lo[ 2 ] , hi[ 2 ] ) );
}

bool solve( ld t ){
	REP( i , 2 )REP( j , 2 ){
		vld lo , hi;
		lo.pb( -t + A[ i ^ 1 ][ j ^ 1 ] );
		hi.pb( +t + A[ i ^ 1 ][ j ^ 1 ] );
		REP( a , 2 )REP( b , 2 ){
			if( ((a + b)&1) != ((i + j)&1) ){
				lo.pb( -t + A[ a ][ b ] );
				hi.pb( +t + A[ a ][ b ] );
			}
		}
		if( solve( A[ i ][ j ] - t , lo , hi ) ) return 1;
		if( solve( A[ i ][ j ] + t , lo , hi ) ) return 1;
	}
	return 0;
}

int main(){
	ios_base :: sync_with_stdio( 0 );
	while( cin >> A[ 0 ][ 0 ] ){
		REP( i , 2 ) REP( j , 2 ){
			if( !i && !j ) continue;
			cin >> A[ i ][ j ];
		}
		ld lo = 0 , hi = 1e10;
		REP( it , 200 ){
			ld med = (lo + hi)/2.0;
			if( solve( med ) ) hi = med;
			else lo = med;
		}
		printf( "%.15f\n" , (double) hi );
	}
}


