#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

char s[ 10 ];
int main(){
	int cases , n;
	sc( cases );
	while( cases -- ){
		sc( n );
		int ans = 0;
		REP( i , n ){
			scanf( "%s" , s );
			if( s[ 0 ] != 'h' ) ans^= 1;
		}
		puts( ans ? "lxh" : "hhb" );
	}
}
