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

#define N 10000

typedef vector< int > vi;
typedef unsigned long long ull;
typedef long long ll;

bool isSQ( ll x ){
	assert( x <= 9000000000000000000LL );
	ll lo = 0 , hi = 3000000000LL;
	while( hi - lo > 1 ){
		ll med = lo + ((hi - lo) >> 1);
		if( med * med <= x ) lo = med;
		else hi = med;
	}
	return lo * lo == x;
}
int main(){
	for( ll D = 2 ; D <= N ; ++D ){
		if( isSQ( D ) ) continue;
		for( ll k = 0 , x , y2; ; ++k ){
			x = D * k - 1;
			y2 = ( D * k - 2 ) * k;
			if( x > 0 && y2 > 0 && isSQ( y2 ) ){
				cout << D << " " << x << endl;
				break;
			}
			x = D * k + 1;
			y2 = ( D * k + 2 ) * k;
			if( x > 0 && y2 > 0 && isSQ( y2 ) ){
				cout << D << " " << x << endl;
				break;
			}
		}
	}
}


