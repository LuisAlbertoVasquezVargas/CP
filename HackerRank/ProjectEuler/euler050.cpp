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

#define N 10000000

typedef vector< int > vi;
typedef long long ll;
typedef vector< ll > vll;
typedef long double ld;

bool P[ N + 5 ];

ll get( int a , int b , vll &AC ){
	assert( b + 1 < SZ( AC ) );
	return AC[ b + 1 ] - AC[ a ];
}
vi primes;
bool isPrime( ll x ){
	if( x <= N ) return P[ x ];
	for( int i = 0 ; (ll) primes[ i ] * primes[ i ] <= x && i < SZ( primes ) ; ++i )
		if( x % primes[ i ] == 0 ) return 0;
	return 1;	
}
int main(){
	clr( P , 1 );
	P[ 0 ] = P[ 1 ] = 0;
	for( int j = 4 ; j <= N ; j += 2 ) P[ j ] = 0;
	for( int i = 3 ; i * i <= N ; i += 2 )
		if( P[ i ] ) for( int j = i * i ; j <= N ; j += i ) P[ j ] = 0;

	for( int i = 0 ; i <= N ; ++i )
		if( P[ i ] ) primes.pb( i );
	/*
	REP( i , SZ( primes ) ) cout << primes[ i ] << " ";
	cout << endl;
	return 0;
	*/
	vll AC( SZ( primes ) + 1 );
	cout << "hello world";
	return 0;
	for( ll x : primes ) cout << x << endl;

	REP( i , SZ( primes ) ) AC[ i + 1 ] = AC[ i ] + primes[ i ];
	//REP( i , SZ( primes ) ) AC[ i + 1 ] = AC[ i ] + primes[ i ];
	
	cout << SZ( AC ) << endl;
	
	for( int k = 8 ; k <= 8 ; ++k ){
		for( int i = 0 ; ; ++i ){
			cout << i << endl;
			if( isPrime( get( i , i + k - 1 , AC ) ) ){
				cout << k << " " << i << endl;
				break;
			}	
		}
	}
} 




