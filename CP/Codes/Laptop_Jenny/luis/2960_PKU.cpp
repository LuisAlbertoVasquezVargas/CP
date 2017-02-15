//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define N 10000

int k;
int moves[ N + 5 ];
bool SET[ N + 5 ];
/*int memo[ N + 5 ];
int grundy( int n ){
	if( n == 0 ) return 0;
	int &dev = memo[ n ];
	if( dev == -1 ){
		dev = 0;
		set< int >S;
		for( int i = 0 ; i < k && n - moves[ i ] >= 0 ; ++i )
			S.insert( grundy( n - moves[ i ] ) );
		while( S.count( dev ) ) dev++;
	}
	return dev;
}*/
int DP[ N + 5 ];
int main(){
	int x , S;
	while( sc( k ) == 1 ){
		if( !k ) break;
		REP( i , k ) sc( moves[ i ] );
		sort( moves , moves + k );
		k = unique( moves , moves + k ) - moves;
		//clr( memo , -1 );
		for( int n = 0 ; n <= N ; ++n ){
			int &dev = DP[ n ];
			if( n == 0 ) {
				dev = 0;
				continue;
			}
			dev = 0;
			REP( i , n + 1 ) SET[ i ] = 0;
			for( int i = 0 ; i < k && n - moves[ i ] >= 0 ; ++i )
				SET[ DP[ n - moves[ i ] ] ] = 1;
			while( SET[ dev ] ) dev++;
		}
		sc( S );
		while( S -- ){
			int n;
			sc( n );
			int ans = 0;
			REP( i , n ) sc( x ) , ans ^= DP[ x ];
			putchar( ans ? 'W' : 'L' );
		}
		puts( "" );
	}
}
