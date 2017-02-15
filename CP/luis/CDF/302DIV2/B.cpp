#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )
 
#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())
 
#define mp make_pair
#define fi first
#define se second

typedef vector< int > vi;
typedef vector< vi > vvi;

int main(){
	int n , K;
	while( sc( n ) == 1 ){
		sc( K );
		vvi T( n , vi( n ) );
		int cnt = 0;
		REP( i , n ) REP( j , n ) 
			if( !((i + j) &1) ) cnt ++;
		if( cnt >= K ){
			puts( "YES" );
			REP( i , n ) REP( j , n ) 
				if( !((i + j) &1) && K ){
					T[ i ][ j ] = 1;
					K --;
				}
			REP( i , n ) {
				REP( j , n ) printf( "%c" , T[ i ][ j ] ? 'L' : 'S' );
				puts( "" );
			}
		}else{
			puts( "NO" );
		}
	}
}
