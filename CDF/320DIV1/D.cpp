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

#define N 100000

typedef long long ll;
typedef vector< ll > vll;
typedef long double ld;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

ll B = 27;
char S[ N + 5 ];
vll MOD = { 1000000007 , 1000000009 };
ll POT[ 2 ][ N + 5 ];
ll AC[ 2 ][ N + 5 ];
ll T[ 2 ];
pii getHash( int lo , int hi ){
	if( lo > hi ) return mp( 0 , 0 );
	REP( k , 2 ) {
		T[ k ] = AC[ k ][ hi + 1 ] - AC[ k ][ lo ] * POT[ k ][ hi - lo + 1 ];
		T[ k ] %= MOD[ k ];
		if( T[ k ] < 0 ) T[ k ] += MOD[ k ];
	}
	return mp( T[ 0 ] , T[ 1 ] );
}
vll ha , hb;
pii combine( pii a , pii b , int lb ){
	ha = { a.fi , a.se };
	hb = { b.fi , b.se };
	REP( k , 2 ) {
		T[ k ] = ha[ k ] * POT[ k ][ lb ] + hb[ k ];
		T[ k ] %= MOD[ k ];
	}
	return mp( T[ 0 ] , T[ 1 ] );
}
int main(){
	REP( k , 2 ){
		POT[ k ][ 0 ] = 1;
		for( int i = 1 ; i <= N ; ++i )
			POT[ k ][ i ] = (B * POT[ k ][ i - 1 ]) % MOD[ k ];
	}
	int n , m;
	while( sc( n ) == 1 ){
		sc( m );
		scanf( "%s" , S );
		REP( i , n ) S[ i ] = S[ i ] - 'a' + 1;
		
		REP( i , n ) cout << (int)S[ i ];
		cout << endl;
		
		REP( k , 2 ) REP( i , n ) 
			AC[ k ][ i + 1 ] = (AC[ k ][ i ] * B + S[ i ]) % MOD[ k ];
		pii h = getHash( 0 , n - 1 );
		vpii vec;
		REP( i , n ){
			pii L = getHash( 0 , i - 1 );
			pii R = getHash( i + 1 , n - 1 );
			for( int c = 1 ; c <= m ; ++c ){
				pii temp;
				temp = combine( L , mp( c , c ) , 1 );
				temp = combine( temp , R , (n - 1) - (i + 1) + 1 );
				if( temp != h ) vec.pb( temp );
			}
		}
		sort( all( vec ) );
		int ans = unique( all( vec ) ) - vec.begin();
		printf( "%d\n" , ans );
	}
}


