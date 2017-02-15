#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

int main()
{
	int n , x;
	while( sc( n ) == 1 ){
		if( !n ) break;
		int ans = 0;
		REP( i , n ) sc( x ) , ans ^= x;
		puts( ans ? "Yes" : "No" );
	}
}
