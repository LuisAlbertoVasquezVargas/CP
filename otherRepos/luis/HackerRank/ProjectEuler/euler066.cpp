#include<bits/stdc++.h>
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

#define N 10000
#define M 100000000

typedef long long ll;

bool isSQ( ll x ){
	ll r = (ll)round( sqrt( x ) );
	return r * r == x;
}
int solve( int D ){
	if( isSQ( D ) ) return -1;
	for( int x = 2 ; ; ++x ){
		ll t = (ll)(x - 1) * (ll) (x + 1);
		if( t % D == 0 ){
			ll y = t / D;
			assert( y < 1e17 );
			if( isSQ( y ) ) return x;	
		}
	}
}
int main(){
	for( int i = 2 ; i <= N ; ++i ){
		cout << i << ' ' << solve( i ) << endl;
	}
}


