#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)

typedef vector< int > VI;

int main(){
	int cases;
	scanf( "%d" , &cases );
	REP( tc , cases ){
		int n;
		scanf( "%d" , &n );
		VI a( n + 1 ) , b( n + 1 );
		REP( i , n ) scanf( "%d" , &a[ i + 1 ] );
		REP( i , n ) scanf( "%d" , &b[ i ] );
		int ans = 0;
		REP( i , n )
			if( a[ i + 1 ] - a[ i ] >= b[ i ] ) ans ++;
		printf( "%d\n" , ans );
	}
}


