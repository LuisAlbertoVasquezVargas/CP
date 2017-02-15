#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

typedef long long ll;

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		ll ans = 0;
		int last = 0;
		REP( i , n ){
			int x;
			sc( x );
			ans += max( 0 , x  - last );
			last = x;
		}
		printf( "%lld\n" , ans );
	}
}
