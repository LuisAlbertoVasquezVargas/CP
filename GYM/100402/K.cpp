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

#define N 64

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef vector< string > vs;

string toBin( ll x ){
	string s;
	while( x ){
		s.pb( '0' + (x&1) );
		x >>= 1;
	}
	sort( all( s ) );
	return s;
}
int ones[ N + 1 ] , zeroes[ N + 1 ]; 
bool used[ N + 1 ][ N + 1 ][ N + 1 ];
int memo[ N + 1 ][ N + 1 ][ N + 1 ];
int n , len;
int dp( int pos , int odd , int even ){
	if( pos == n ) return even == len;
	if( used[ pos ][ odd ][ even ] ) return memo[ pos ][ odd ][ even ];
	used[ pos ][ odd ][ even ] = 1;
	int &dev = memo[ pos ][ odd ][ even ] = 0;
	for( int k = 0 ; k <= min( odd , ones[ pos ] ) ; ++k ){
		if( odd - k <= zeroes[ pos ] ){
			int c1 = k;
			int c2 = odd - k;
			int c3 = ones[ pos ] - k;
			int c4 = zeroes[ pos ] - c2;
			dev |= dp( pos + 1 , c2 + c3 , c1 + c4 );
		}
	}
	return dev;
}
ll ANS[ N + 1 ];
void rec( int pos , int odd , int even , vi &ODD , vi &EVEN ){
	if( pos == n ) {
		assert( even == len );
		return;
	}
	
	for( int k = 0 ; k <= min( odd , ones[ pos ] ) ; ++k ){
		if( odd - k <= zeroes[ pos ] ){
			int c1 = k;
			int c2 = odd - k;
			int c3 = ones[ pos ] - k;
			int c4 = zeroes[ pos ] - c2;
			if( dp( pos + 1 , c2 + c3 , c1 + c4 ) ){
				vi a , b;
				REP( i , odd ){
					if( i < c1 ){
						b.pb( ODD[ i ] );
						ANS[ pos ] |= ( 1LL << ODD[ i ] );
					}
					else a.pb( ODD[ i ] );
				}
				REP( i , even ){
					if( i < c3 ){ 
						a.pb( EVEN[ i ] );
						ANS[ pos ] |= ( 1LL << EVEN[ i ] );
					}else b.pb( EVEN[ i ] );
				}
				rec( pos + 1 , c2 + c3 , c1 + c4 , a , b );
				return;
			}
		}
	}
	assert( 0 );
}
int main(){
	
	freopen( "xor.in" , "r" , stdin );
	freopen( "xor.out" , "w" , stdout );
	
	while( cin >> n ){
		vs vec;
		len = 0;
		REP( i , n ){
			ll x ;
			cin >> x;
			string s = toBin( x );
			len = max( len , SZ( s ) );
			vec.pb( s );
		}
		REP( i , n ) {
			vec[ i ].resize( len , '0' );
			sort( all( vec[ i ] ) );
			ones[ i ] = count( all( vec[ i ] ) , '1' );
			zeroes[ i ] = count( all( vec[ i ] ) , '0' );
		}
		clr( used , 0 );
		if( !dp( 0 , 0 , len ) ){
			puts( "impossible" );
			continue;
		}
		clr( ANS , 0 );
		vi a , b;
		REP( i , len ) b.pb( i );
		rec( 0 , 0 , len , a , b );
		REP( i , n ) cout << (ANS[ i ]) << char( i + 1 == n ? 10 : 32 );
	}
}





