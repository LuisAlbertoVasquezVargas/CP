#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

int main(){
	int cases;
	sc( cases );
	while( cases -- ){
		int n , x , ans = 0;
		sc( n );
		bool Ones = 1;
		REP( i , n ) {
			sc( x );
			ans = ans xor x;
			if( x != 1 ) Ones = 0;
		}
		if( Ones ){
			puts( !ans ? "John" : "Brother" );
		}else 	puts( ans ? "John" : "Brother" );
	}
}
