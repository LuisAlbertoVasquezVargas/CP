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

#define N 5000000LL

typedef vector< int > vi;
typedef long long ll;

int F[ N + 5 ] , G[ N + 5 ];

int main(){
	
	for( ll n = 1 ; 2LL * n * n <= N ; n ++ ){
		for( ll m = n + 1 ; n * n + m * m <= N ; m += 2 ){
			if( __gcd( n , m ) != 1 ) continue;
			ll a = m * m - n * n;
			ll b = 2LL * m * n;
			ll c = m * m + n * n;
			if( a + b + c > N ) break;
			for( ll k = 1 ; ; ++k ){
				ll x = (a + b + c) * k;
				if( x > N ) break;
				F[ x ]++;	
			}
		}
	}
	
	for( int i = 1 ; i <= N ; ++i )
		G[ i ] = G[ i - 1 ] + (F[ i ] == 1);
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		printf( "%d\n" , G[ n ] );
	}
}


