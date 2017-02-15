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

#define IT 200

typedef long long ll;
typedef long double ld;
typedef pair< int , int > pii;
typedef vector< int > vi;

bool f( ll K , ll a , ll b , ld &x ){
	bool ans = 0;
	x = 1e10;
	if( 2LL * b * (K - 1) <= (a - b) ){
		x = min( x , (ld)(a - b)/(ld)(2.0*(K - 1.0)) );
		ans = 1;
	}
	if( 2 * K * b <= (a + b) ){
		x = min( x , (ld)(a + b)/(ld)(2.0*K) );
		ans = 1;
	}
	return ans;
}
int main(){
	int a , b;
	while( sc( a ) == 1 ){
		sc( b );
		if( b > a ){
			puts( "-1" );
			continue;
		}
		ll lo = 1 , hi = 2000000000LL;
		ld ans;
		while( hi - lo > 1 ){
			ll med = (lo + hi) >> 1;
			if( f( med , a , b , ans ) ) lo = med;
			else hi = med;
		}
		f( lo , a , b , ans );
		printf( "%.15f\n" , (double)ans );
	}
}




