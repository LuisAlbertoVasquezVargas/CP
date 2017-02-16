#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define N 100000
int b[ N + 5 ] , mapa[ N + 5 ];
int main(){
	int cases , n , x;
	sc( cases );
	REP( tc , cases ){
		sc( n );
		REP( i , n ){
			sc( x );
			x--;
			mapa[ x ] = i;
		}
		int sz = 0;
		REP( i , n ){
			sc( x );
			x --;
			x = mapa[ x ];
			int pos = lower_bound( b , b + sz , x ) - b;
			b[ pos ] = x;
			if( pos == sz ) sz ++;
		}
		printf( "%d\n" , sz );
	}
}
