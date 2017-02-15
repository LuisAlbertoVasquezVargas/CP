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

#define N 10000000
#define M 50

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int P[ N + 5 ];
void sieve(){
	clr( P , -1 );
	for( int i = 2 ; i * i <= N ; ++i )
		if( P[ i ] == -1 )
			for( int j = i * i ; j <= N ; j += i ) P[ j ] = i;
}
void primefact( int n , vi &pr , vi &ex ){
	while( 1 ){
		int p = P[ n ];
		if( n == 1 ){
			return;
		}
		if( p == -1 ){
			pr.pb( n ) , ex.pb( 1 );
			break;
		}
		int exp = 0 ;
		while( n % p == 0 ) {
			exp ++;
			n /= p;
		}
		pr.pb( p ) , ex.pb( exp );
	}
}

vi getAllDivisors( vi pr , vi ex ){
	int k = pr.size();
	vi divisors( 1 , 1 );

	REP( i , k ){
		int m = divisors.size();
		REP( j , ex[ i ] )
			REP( a , m ) divisors.pb( pr[ i ] * divisors[ a + j * m ] );
	}
	return divisors;
}
vi DIVI[ N + 5 ];
int CNT[ N + 5 ];
void calc( int d ){
	if( CNT[ d ] != -1 ) return;
	vi p , e;
	primefact( d , p , e );
	DIVI[ d ] = getAllDivisors( p , e );
	CNT[ d ] = accumulate( all( e ) , 0 );
}
int n ;
int A[ M + 5 ];
bool used[ M + 5 ][ M + 5 ];
int memo[ M + 5 ][ M + 5 ];
int dp( int pos , int cur ){
	if( pos == n ) return 0;
	if( used[ pos ][ cur ] ) return memo[ pos ][ cur ];
	used[ pos ][ cur ] = 1;
	int &dev = memo[ pos ][ cur ] = A[ pos ] + dp( pos + 1 , cur );
	int g = 0 , S = 0;
	for( int r = pos ; r < n ; ++r ){
		g = __gcd( g , A[ r ] );
		S += A[ r ];
		calc( g );
		for( auto d : DIVI[ g ] ){
			calc( d );
			assert( S % d == 0 );
			if( cur - CNT[ d ] >= 0 )
				dev = min( dev , S / d + dp( r + 1 , cur - CNT[ d ] ) );
		}
	}
	return dev;
}
int main(){
	sieve();
	clr( CNT , -1 );
	int m;
	while( sc( n ) == 1 ){
		sc( m );
		REP( i , n ) sc( A[ i ] );
		clr( used , 0 );
		printf( "%d\n" , dp( 0 , m ) );
	}	
}


