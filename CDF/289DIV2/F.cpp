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

#define N 500
#define MOD 1000000007

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

bool used[ 2 ][ N + 1 ][ N + 1 ];
int memo[ 2 ][ N + 1 ][ N + 1 ];
int P[ N + 1 ];
int n;

int dp( int lo , int hi , int flag ){
	if( lo >= hi ) return 1;
	if( used[ flag ][ lo ][ hi ] ) return memo[ flag ][ lo ][ hi ];
	used[ flag ][ lo ][ hi ] = 1;
	int &dev = memo[ flag ][ lo ][ hi ] = 0;
	if( flag ){
		// P[ lo ] ..... P[ k ] , P[ k + 1 ] ... P[ hi ]
		dev = dp( lo , hi , 0 );
		for( int k = lo ; k < hi ; ++k )
			if( P[ lo ] < P[ k + 1 ] )
				dev = ((ll)dev + (ll) dp( lo , k , 0 ) * (ll) dp( k + 1 , hi , 1 ) )%MOD;
	}else{
		// P[ lo ] , P[ lo + 1 ] ... P[ k ] , P[ k + 1 ] ... P[ hi ]
		dev = dp( lo + 1 , hi , 0 );
		for( int k = lo + 1 ; k < hi ; ++k )
			if( P[ lo + 1 ] < P[ k + 1 ] ) 
				dev = ((ll)dev + (ll) dp( lo + 1 , k , 0 ) * (ll) dp( k + 1 , hi , 1 ) )%MOD;
	}
	return dev;
}
int main(){
	while( sc( n ) == 1 ){
		REP( i , n ) sc( P[ i ] );
		clr( used , 0 );
		printf( "%d\n" , dp( 0 , n - 1 , 0 ) );
	}
}


