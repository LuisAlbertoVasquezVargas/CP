#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define N 32

typedef unsigned long long ull;
typedef long double ld;

ull n;
//map< ull , int > memo;
/*
int isWinning( ull p ){
	if( 9*p >= n ) return 1;
	if( memo.count( p ) ) return memo[ p ];
	int dev = 0;
	for( int t = 2 ; t <= 9 ; t += 7 )
		if( !isWinning( t*p ) ) {
			dev = 1;
			break;
		}
	//cout << p << " " << dev << endl;
	return memo[ p ] = dev;
}
*/
ld pow( ld a , int b ){
	ld ans = 1;
	while( b ){
		if( b & 1 ) ans = ans * a;
		b >>= 1;
		a = a * a;
	}
	return ans;
}
ull powInt( ull a , int b ){
	ull ans = 1;
	while( b ){
		if( b & 1 ) ans = ans * a ;
		b >>= 1;
		a *= a;
	}
	return ans;
}
bool DP[ N + 5 ][ N + 5 ];

int main(){
	while( sc( n ) == 1 ){
		//memo.clear();
		//puts( isWinning( 1 ) ? "Stan wins." : "Ollie wins." );
		//puts( isWinning( 1 ) ? "Stan wins." : "Ollie wins." );
		for( int a = N ; a >= 0 ; --a )
			for( int b = N ; b >= 0 ; b-- ){
				bool &dev = DP[ a ][ b ] = 0;
				ld pot = pow( 2 , a ) * pow( 9 , b );
				//cout << a << " " << b << " " << pot << endl;
				if( pot > 429496729.0 ){
					dev = 1;
					continue;
				}
				ull pt = powInt( 2 , a ) * powInt( 9 , b );
				//cout << a << " " << b << " " << pot << endl;
				if( pt * 9 >= n ) {
					dev = 1;
					continue;
				}
				if( !DP[ a + 1 ][ b ] ) dev = 1;
				if( !DP[ a ][ b + 1 ] ) dev = 1;
			}
		puts( DP[ 0 ][ 0 ] ? "Stan wins." : "Ollie wins." );
	}
}
