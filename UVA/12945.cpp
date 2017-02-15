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

#define N 100

typedef long long ll;
typedef double ld;
typedef pair< int , int > pii;
typedef vector< int > vi;

ld X[ N + 1 ] , Y[ N + 1 ] , W[ N + 1 ];
const ld INF = 1e4;
const int IT = 80;
int n;
ld sq( ld x , ld y ){
	return x * x + y * y;
}
ld g( ld x , ld y ){
	ld ans = 0;
	REP( i , n )
		ans += sq( X[ i ] - x , Y[ i ] - y ) * W[ i ];
	return ans;
}
ld f( ld x ){
	ld lo = -INF , hi = INF;
    REP( it , IT ){
    	ld med1 = (lo * 2.0 + hi)/3.0 , med2 = (lo + hi * 2.0)/3.0;
        if( g( x , med1 ) < g( x , med2 ) )
            hi = med2;
        else lo = med1;
    }
    return g( x , lo );
}
int main(){
	while( sc( n ) == 1 ){
		REP( i , n ) {
			int x , y , w;
			sc( x ) , sc( y ) , sc( w );
			X[ i ] = x , Y[ i ] = y , W[ i ] = w;
		}
		ld lo = -INF , hi = INF;
        REP( it , IT ){
        	ld med1 = (lo * 2.0 + hi)/3.0 , med2 = (lo + hi * 2.0)/3.0;
            if( f( med1 ) < f( med2 ) )
                hi = med2;
            else lo = med1;
        }
        ld cur = (ld)round( f(lo) * 1000.0 );
		cur /= 1000.0;
        printf( "%.3f\n" , cur );
	}
}
