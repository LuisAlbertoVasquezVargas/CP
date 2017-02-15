#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define N 5000000

typedef long long ll;
typedef vector< int > vi;
typedef pair< int , int > pii;

int P[ N + 5 ];
void sieve(){
	clr( P , -1 );
	for( int i = 2 ; i * i <= N ; ++i )
		if( P[ i ] == -1 )
			for( int j = i * i ; j <= N ; j += i ) P[ j ] = i;
}
void primefact( int n , int &ct ){
	while( 1 ){
		int p = P[ n ];
		if( n == 1 ){
			return;
		}
		if( p == -1 ){
			ct ++;
			break;
		}
		while( n % p == 0 ) {
			ct ++;
			n /= p;
		}
	}
}
int T[ N + 5 ];
int main(){
	sieve();	
	T[ 0 ] = T[ 1 ] = 1;
	for( int i = 2 ; i <= N ; ++i ){
		int ct = 0;
		primefact( i , ct );
		T[ i ] = T[ i - 1 ] + ct;
	}
	int n;
	while( sc( n ) == 1 ){
		REP( it , n ){
			int b , a;
			sc( b ) , sc( a );
			printf( "%d\n" , T[ b ] - T[ a ] );
		}
	}
}


