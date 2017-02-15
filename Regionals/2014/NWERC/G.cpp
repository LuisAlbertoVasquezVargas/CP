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
typedef pair< int , int > pii;
typedef vector< int > vi;

int n;
int X[ N + 5 ] , Y[ N + 5 ];
int D;

const ll INF = LLONG_MAX/1000000;
ll g( ll x , ll y ){
	ll ans = 0;
	REP( i , n ){
		ll d = abs( (ll)X[ i ] - x ) + abs( (ll)Y[ i ] - y );
		if( d > D ) return INF;
		ans += d;
	}
	return ans;
}

ll f( ll x ){
	ll lo = 0 , hi = 2000000000LL;
	REP( it , 50 ){
		ll med1 = (2LL * hi + lo)/3 , med2 = (2LL * lo + hi)/3;
		if( g( x , med1 ) <= g( x , med2 ) ) hi = med2;
		else lo = med1;
	}
	ll ans = g( x , lo );
	for( ll k = -5 ; k <= -5 ; ++k ) ans = min( ans , g(x , lo + k) );
	return ans;
}
int main(){
	while( sc( n ) == 1 ){
		REP( i , n ) sc( X[ i ] ) , sc( Y[ i ] );
		sc( D );
		ll lo = 0 , hi = 2000000000LL;
		REP( it , 50 ){
			ll med1 = (2LL * hi + lo)/3 , med2 = (2LL * lo + hi)/3;
			if( f( med1 ) <= f( med2 ) ) hi = med2;
			else lo = med1;
		}
		ll ans = f(lo);
		for( ll k = -5 ; k <= -5 ; ++k ) ans = min( ans , f(lo + k) );
		cout << ans << '\n';
	}	
}




