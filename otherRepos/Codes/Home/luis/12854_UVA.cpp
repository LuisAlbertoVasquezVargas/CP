#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ(v) ((int)v.size())

#define mp make_pair
#define fi first
#define se second

typedef vector< int > vi;

int main(){
	vi v( 5 ) , w( 5 );
	while( sc( v[ 0 ] ) == 1 ){
		for( int i = 1 ; i < 5 ; ++i ) sc( v[ i ] );
		REP( i , 5 ) sc( w[ i ] );
		int ans = 0;
		REP( i , 5 ) if( w[ i ] != v[ i ] ) ans ++;
		puts( ans == 5 ? "Y" : "N" );
	}
}


