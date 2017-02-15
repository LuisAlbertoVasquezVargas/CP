#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define N 10000
#define LIM 67

typedef unsigned long long ull;

bool solve;
ull P = 1;
ull target;
bool PRIME[ N + 5 ];
int prime[ N + 5 ];
 
ull C[ LIM + 5 ][ LIM + 5 ];

ull pow( ull a , int b ){
	ull ans = 1;
	REP( i , b ) ans *= a;
	return ans;
}
void init(){
	clr( PRIME , 1 );
	for( int i = 2 ; i * i <= N ; ++i )
		if( PRIME[ i ] ) for( int j = i * i ; j <= N ; j += i ) PRIME[ j ] = 0;
	int pos = 0;
	for( int i = 2 ; i <= N ; ++i ) if( PRIME[ i ] ) prime[ pos ++ ] = i;
	REP( i , LIM + 1 ) C[ i ][ i ] = C[ i ][ 0 ] = 1; 
	for( int i = 2 ; i <= LIM ; ++i )
		for( int j = 1 ; j < i ; ++j ) C[ i ][ j ] = C[ i - 1 ][ j - 1 ] + C[ i - 1 ][ j ];
	//REP( i , LIM + 1 ) REP( j , LIM + 1 ) cout << C[ i ][ j ] << ( j == LIM ? "\n":" ");
}
void f( int e , ull prod , int sum , int pos ){
	//cout << e << " " << prod << " " << sum << " " << pos << endl;
	if( pos > LIM ) return;
	if( solve ) return;
	if( prod == target && P > 1 ){
		cout << target << " " << P << '\n';
		solve = 1;
		return;
	}
	if( e ) f( e - 1 , prod , sum , pos );
	if( sum + e <= LIM && target % C[ sum + e ][ e ] == 0 &&  prod <= target/C[ sum + e ][ e ] ){
		ull pot = pow( prime[ pos ] , e );
		P *= pot;
		f( e , prod * C[ sum + e ][ e ] , sum + e , pos + 1 );
		P /= pot;
	}
}
int main(){
	init();
	
	for( target = 2 ; target <= 100 ; target ++ ){
		solve = 0;
		REP( i , LIM ) {
			cout << "trying :" << i << endl;
			f( i , 1 , 0 , 0 );
			if( solve ) break;
		}
	}
	
	/*
	while( cin >> target ){
		solve = 0;
		REP( i , LIM ) {
			f( i , 1 , 0 , 0 );
			if( solve ) break;
		}
	}
	*/
}
