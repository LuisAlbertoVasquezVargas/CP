#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) ) 

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define fi first
#define se second
#define mp make_pair

#define N 500000
#define LOGN 20

typedef long long ll;
typedef vector< int > vi;

int P[ N + 5 ];
void sieve(){
	clr( P , -1 );
	for( int i = 2 ; i * i <= N ; ++i )
		if( P[ i ] == -1 ) for( int j = i * i ; j <= N ; j += i ) P[ j ] = i;
}
int primefact( int n ){
	int ans = 0;
	while( 1 ){
		if( n == 1 ) break;
		if( P[ n ] == -1 ){
			ans += n;
			break;
		}
		int p = P[ n ];
		while( n % p == 0 ) n /= p , ans += p;
	}
	return ans;
}
int rmq[ LOGN + 1 ][ N + 5 ];

int query( int a , int b ){ 
	int r = 31 - __builtin_clz( b - a + 1 );
	return max( rmq[ r ][ a ] , rmq[ r ][ b - (1<<r) + 1 ] );
}
int main(){
	sieve();
	for( int i = 2 ; i <= N ; ++i ){
		int ans = 1 , p = i;
		while( 1 ){
			if( p == primefact( p ) ) break;
			ans ++;
			p = primefact( p );
		}
		rmq[ 0 ][ i ] = ans;
	}
	for( int k = 1 ; k <= LOGN ; ++k )
			for( int i = 0 ; i + ( 1 << k ) <= N + 1 ; ++i )
				rmq[ k ][ i ] = max( rmq[ k - 1 ][ i ] , rmq[ k - 1 ][ i + (1<<(k - 1)) ] );
	int cases;
	sc( cases );
	REP( tc , cases ){
		int a , b;
		sc( a ) , sc( b );
		if( a > b ) swap( a , b );
		printf( "Case #%d:\n%d\n" , tc + 1 , query( a , b ) );
	}
}


