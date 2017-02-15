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

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef long double ld;

const ld g = 1.0;
const ld INF = 1e100;
ld eval( ld xi , ld yi , ld l ){
	ld num = yi;
	ld den = ( 2.0 * xi / (l * g) ) * ( 1.0 - (xi / l) );
	//if( abs( den ) < 1e-12 ) return INF;
	//if( den < 0 ) return 0;
	return sqrt( num / den );
}
ld f( ld l , ld vy ){
	//if( abs( vy ) < 1e-12 ) return INF;
	ll vx = l * g / ( 2.0 * vy );
	return hypot( vx , vy );
}
ld get( ld l , ld tope ){
	ld lo = tope , hi = 1e9;
	ld vy = sqrt( l * g / 2.0 );
	if( vy >= tope ) return f( l , vy );
	return f( l , tope );
	/*
	REP( it , 200 ){
		ld med1 = (2.0 * lo + hi) / 3.0 , med2 = (2.0 * hi + lo) /3.0;
		if( f( l , med1 ) < f( l , med2 ) ) hi = med2;
		else lo = med1;
	}
	return lo;
	*/
}
ld solve( int IT , int d , ld l , int n , vi &x , vi &y ){
	ld tope = 0.00;
	REP( it , IT ){
		ll lo = (ld)it * l , hi = lo + l;
		REP( i , n ){
			if( abs( x[ i ] - lo ) < 1e-12 ) return INF;
			if( abs( x[ i ] - hi ) < 1e-12 ) return INF;
			if( lo <= x[ i ] && x[ i ] <= hi ){
				tope = max( tope , eval( (ld)x[ i ] - lo , (ld)y[ i ] , l ) );
			}
		}
	}
	return get( l , tope );
}


int main(){
	int d , n , b;
	while( sc( d ) == 1 ){
		sc( n ) , sc( b );
		vi x( n ) , y( n );
		REP( i , n ) sc( x[ i ] ) , sc( y[ i ] );
		ld ans = 1e100;
		for( int L = 1 ; L <= b + 1 ; ++L ){
			ld l = (ld) d / L;
			ans = min( ans , solve( L , d , l , n , x , y ) );
		}
		printf( "%.15f\n" , (double) ans );
	}	
}







