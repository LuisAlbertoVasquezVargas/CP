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

#define N 45

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef pair< ll , ll > pll;
typedef vector< int > vi;

vll F( N + 1 );

void gcdext( ll &g , ll &x , ll &y , ll a , ll b ){// ASUMING a >= b
	if( b == 0 )
		g = a , x = 1 , y = 0;
	else gcdext( g , y , x , b , a%b ) , y = y - ( a/b )*x;
}
int main(){
	F[ 1 ] = 1;
	for( int n = 2 ; n <= N ; ++n )
		F[ n ] = F[ n - 1 ] + F[ n - 2 ];
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		pll p( n - 1 , 1 );
		for( int i = 1 ; i <= N ; ++i ){
			ll g , xg , yg ;
			ll a = F[ i - 1 ] , b = F[ i ];
			gcdext( g , yg , xg , b , a );
			assert( g == 1 );
			ll X0 = xg * (ll)(n/g) , Y0 = yg * (ll)(n/g);
			ll c = n;
			assert( a * X0 + b * Y0 == c );
			//a = F[ i - 1 ] , b = F[ i ];
			//test();
			//DEBUG2( a , b );
			if( b == 0 ) continue;
			ll curk = (1LL - X0)/b;
			for( ll k = curk - 5 ; k <= curk + 5 ; ++k ){
				ll nx = X0 + k * (b / g);
				ll ny = Y0 - k * (a / g);
				assert( a * nx + b * ny == c );
				//DEBUG2( nx , ny );
				if( 0 < nx && nx <= ny ) p = min( p , mp( ny , nx ) );
			}
		}
		cout << p.se << " " << p.fi << '\n';
	}
}






