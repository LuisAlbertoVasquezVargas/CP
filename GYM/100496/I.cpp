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
typedef long double ld;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

int solve( int n ){
	vpii A;
	for( int k = 0 ; k <= n ; ++k )
		for( int m = 0 ; k + m <= n ; ++m ){
			A.pb( mp( k , m ) );
		}
	int r = SZ(A);
	DEBUG( r );
	int ans = 0;
	REP( mask , (1 << r) ){
		bool ok = 0;
		REP( i , r )
			if( A[ i ].fi + A[ i ].se == n ){
				if( mask & (1 << i) ) ok = 1;
			}
		if( !ok ) continue;
		ok = 1;
		REP( k , 10 ){
			ld eval = 0;
			REP( i , r )
				if( mask & (1 << i) ) eval += pow( (ld)k , A[ i ].fi ) * pow( (ld)(1 - k) , A[ i ].se );
			if( abs( eval - 1 ) < 1e-8 ) continue;
			ok = 0;
			break;
		}
		if( ok ) ans ++;
	}
	return ans;
}

ll C[ N + 5 ][ N + 5 ];
void init( int n ){
    clr( C, 0 );
	REP( i , n + 1 ) C[ i ][ i ] = C[ i ][ 0 ] = 1;
    for( int i = 2 ; i <= n ; ++i )
         for( int j = 1 ; j <= i ; ++j )
            C[ i ][ j ] = ( C[ i - 1 ][ j ] + C[ i - 1 ][ j - 1 ] );
}
int cata( int n ){ return C[ 2 * n ][ n ] / (n + 1);}
int main(){
	freopen("immetric.in", "r", stdin);
	freopen("immetric.out", "w", stdout);
	
	//for( int i = 1 ; i <= 6 ; ++i ) cout << solve( i ) << '\n';
	init( N );
	int n , tc = 0;
	while( sc( n ) == 1 ){
		if( !n ) break;
		printf( "Case #%d: %d\n" , ++tc , cata( n ) );
	}
}


