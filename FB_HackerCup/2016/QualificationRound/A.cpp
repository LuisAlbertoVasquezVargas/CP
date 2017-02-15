#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < (n) ; ++i )

typedef vector< int > vi;
typedef long long ll;

ll f( ll x ){
	return (x * (x - 1)) >> 1;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		vi x( n ) , y( n );
		REP( i , n ) sc( x[ i ] ) , sc( y[ i ] );

		ll ans = 0 ;
		REP( i , n ){
			vi v;
			map< int , int > freq;
			REP( j , n ){
				int dx = x[ i ] - x[ j ];
				int dy = y[ i ] - y[ j ];
				freq[ dx * dx + dy * dy ] ++;
			}
			for( auto t : freq )
				ans += f( t.second );
		}
		printf( "Case #%d: %lld\n" , tc + 1 , ans );
	}
}
