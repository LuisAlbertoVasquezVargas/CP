#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define N 800 

//int memo[ 2 ][ 2 ][ 2 ][ 2 ][ N + 5 ];
/*
int dp( int n , bool LB , bool LT , bool RB , bool RT ){
	if( n == 0 ) return 0;
	if( n == 1 ){
		if( LB + LT + RB + RT == 0 ) return 0;
		return 1;
	}
	int &dev = memo[ LB ][ LT ][ RB ][ RT ][ n ];
	if( dev == -1 ){
		dev = 0;
		vector< bool > SET( N + 5 );
		if( LB + LT == 0 ){
			SET[ dp( n - 2 , 0 , 1 , RB , RT ) ] = 1;
			SET[ dp( n - 2 , 1 , 0 , RB , RT ) ] = 1;
		} else SET[ dp( n - 1 , 0 , 0 , RB , RT ) ] = 1;
		if( RB + RT == 0 ){
			SET[ dp( n - 2 , LB , LT , 0 , 1 ) ] = 1;
			SET[ dp( n - 2 , LB , LT , 1 , 0 ) ] = 1;
		} else SET[ dp( n - 1 , LB , LT , 0 , 0 ) ] = 1;
		for( int i = 0 ; i <= n - 2 ; ++i ){
			SET[ dp( i , LB , LT , 0 , 0 ) xor dp( n - i - 2 , 0 , 1 , RB , RT ) ] = 1;
			SET[ dp( i , LB , LT , 0 , 0 ) xor dp( n - i - 2 , 1 , 0 , RB , RT ) ] = 1;
			SET[ dp( i , LB , LT , 0 , 1 ) xor dp( n - i - 2 , 0 , 0 , RB , RT ) ] = 1;
			SET[ dp( i , LB , LT , 1 , 0 ) xor dp( n - i - 2 , 0 , 0 , RB , RT ) ] = 1;
		}
		while( SET[ dev ] ) dev++;	
	}
	return dev;
}*/
int DP[ N + 5 ][ 2 ][ 2 ][ 2 ][ 2 ];
int main(){
	//clr( memo , -1 );
	for( int n =  0 ; n <= N ; ++n )
		REP( LB , 2 ) REP( LT , 2 ) REP( RB , 2 ) REP( RT , 2 )
		{
			int &dev = DP[ n ][ LB ][ LT ][ RB ][ RT ];
			if( n == 0 ) {
				dev = 0;
				continue;
			}
			if( n == 1 ){
				if( LB + LT + RB + RT == 0 ) {
					dev = 0;
					continue;
				}
				dev = 1;
				continue;
			}
			dev = 0;
			vector< bool > SET( N + 5 );
			if( LB + LT == 0 ){
				SET[ DP[ n - 2 ][ 0 ][ 1 ][ RB ][ RT ] ] = 1;
				SET[ DP[ n - 2 ][ 1 ][ 0 ][ RB ][ RT ] ] = 1;
			} else SET[ DP[ n - 1 ][ 0 ][ 0 ][ RB ][ RT ] ] = 1;
			if( RB + RT == 0 ){
				SET[ DP[ n - 2 ][ LB ][ LT ][ 0 ][ 1 ] ] = 1;
				SET[ DP[ n - 2 ][ LB ][ LT ][ 1 ][ 0 ] ] = 1;
			} else SET[ DP[ n - 1 ][ LB ][ LT ][ 0 ][ 0 ] ] = 1;
			for( int i = 0 ; i <= n - 2 ; ++i ){
				SET[ DP[ i ][ LB ][ LT ][ 0 ][ 0 ] xor DP[ n - i - 2 ][ 0 ][ 1 ][ RB ][ RT ] ] = 1;
				SET[ DP[ i ][ LB ][ LT ][ 0 ][ 0 ] xor DP[ n - i - 2 ][ 1 ][ 0 ][ RB ][ RT ] ] = 1;
				SET[ DP[ i ][ LB ][ LT ][ 0 ][ 1 ] xor DP[ n - i - 2 ][ 0 ][ 0 ][ RB ][ RT ] ] = 1;
				SET[ DP[ i ][ LB ][ LT ][ 1 ][ 0 ] xor DP[ n - i - 2 ][ 0 ][ 0 ][ RB ][ RT ] ] = 1;
			}
			while( SET[ dev ] ) dev++;	
		}
	int cases , n ;
	sc( cases );
	while( cases -- ){
		sc( n );
		puts( DP[ n ][ 0 ][ 0 ][ 0][ 0 ] ? "X" : "Y" );
	}
}
