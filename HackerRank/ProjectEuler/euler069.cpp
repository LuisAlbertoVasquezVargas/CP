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

#define N 100000

typedef vector< int > vi;
typedef unsigned long long ull;
typedef vector< ull > vull;
typedef long double ld;

bool P[ N + 5 ];
vull primes;
int main(){
	clr( P , 1 );
	P[ 0 ] = P[ 1 ] = 0;
	for( int j = 4 ; j <= N ; j += 2 ) P[ j ] = 0;
	for( int i = 3 ; i * i <= N ; i += 2 )
		if( P[ i ] ) for( int j = i * i ; j <= N ; j += i ) P[ j ] = 0;
	REP( i , N + 1 ) 
		if( P[ i ] ) primes.pb( i );
	int cases;
	sc( cases );
	REP( tc , cases ){
		ull x;
		scanf( "%llu" , &x );
		ull num = 1;
		ld NUM = 1;
		int pos = 0;
		while( 1 ){
			NUM *= (ld)primes[ pos ];
			if( NUM > 1e19 ) break;
			
			if( num * primes[ pos ] >= x ) break;
			num *= primes[ pos ];
			pos ++;
		}
		printf( "%llu\n" , num );
	}
}


