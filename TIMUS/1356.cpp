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

#define N 4000000

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int P[ N + 5 ];
bool isPrime( int n ){
	if( n <= 2 ) return n == 2;
	if( !( n&1 ) ) return 0;
	if( n <= N ) return (P[ n ] == -1);
	for( int i = 3 ; i * i <= n ; i += 2 )
		if( n%i == 0 ) return 0;
	return 1;
}
vi primes;
void solve( int n ){
	if( isPrime( n ) && n >= 1 ){
		printf( "%d\n" , n );
		return;
	}
	for( int i = 0 ; i < SZ( primes ) ; ++i ){
		int cur = n - primes[ i ];
		if( cur <= 0 ) break;
		if( isPrime( cur ) ){
			printf( "%d %d\n" , primes[ i ] , cur );
			return;
		}
	}
	for( int i = 0 ; i < SZ( primes ) ; ++i )
		for( int j = i ; j < SZ( primes ) ; ++j ){
			int cur = n - primes[ i ] - primes[ j ];
			if( cur <= 0 ) break;
			if( isPrime( cur ) ){
				printf( "%d %d %d\n" , primes[ i ] , primes[ j ] , cur );
				return;
			}
		}
}

void sieve(){
	clr( P , -1 );
	P[ 0 ] = P[ 1 ] = 0;
	for( int i = 2 ; i * i <= N ; ++i )
		if( P[ i ] == -1 )
			for( int j = i * i ; j <= N ; j += i ) P[ j ] = i;
}
int main(){
	sieve();
	REP( i , N + 1 )
		if( P[ i ] == -1 ) primes.pb( i );
	
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		solve( n );
	}
}


