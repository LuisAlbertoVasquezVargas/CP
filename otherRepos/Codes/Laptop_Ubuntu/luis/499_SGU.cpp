#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()

#define N 1000000

#define test puts( "*************test***************" );

typedef vector< int > vi;

int P[ N + 5 ];
int AC[ N + 5 ];
void sieve(){
	clr( P , -1 );
	for( int i = 2 ; i * i <= N ; ++i )
		if( P[ i ] == -1 ) for( int j = i * i ; j <= N ; j += i ) P[ j ] = i;
}
void primefact( int n , vi &p , vi &e ){
	while( 1 ){
		if( n == 1 ) break;
		if( P[ n ] == -1 ){
			p.pb( n );
			e.pb( 1 );
			break;
		}
		int exp = 0;
		int prime = P[ n ];
		while( n % prime == 0 ) n /= prime , exp ++;
		p.pb( prime ) , e.pb( exp );
	}
}
int divisors[ 250 ];
void doit( int n ){
	vi p , e;
	primefact( n , p , e );
	int cnt = 1; divisors[0] = 1;
	int k = e.size();
	//REP( i , k ) cout << p[ i ] << " " << e[ i ] << endl;
	for( int i = 0 ; i < k ; i++ ){
		int m = cnt;
		for( int j = 0 ; j < e[i] ; j++ ){
			int sz = j * m ;
			for( int a = 0 ; a < m ; a++ ) divisors[ cnt++ ] = p[ i ] * divisors[ a + sz ]; 
		}
	}
	REP( i , cnt ) AC[ divisors[ i ] ]++ ;//, cout << divisors[ i ] << endl;
	//cout << endl;
}
int main()
{
	sieve();
	int n , x , ans = 0;
	sc( n );
	REP( i , n ) sc( x ) , doit( x );
	REP( i , N + 1 ) if( AC[ i ] >= 2 ) ans = i;
	printf( "%d\n" , ans );
}
