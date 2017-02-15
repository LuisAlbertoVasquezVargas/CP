#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)v.size())

#define mp make_pair
#define fi first
#define se second

#define N 1000

typedef vector< int > vi;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
int G[ N + 5 ] , color[ N + 5 ];
int n;
bool isSorted(){
	REP( i , n ) if( G[ i ] != i ) return 0;
	return 1;
}
int main(){
	int x , tc = 0;
	while( sc( n ) == 1 ){
		if( !n ) break;
		vi F( N + 1 ) , mapa( F ) , v , cost( n );
		REP( i , n ){
			sc( x );
			F[ x ]++;
			v.pb( x );
		}
		int sz = 0;
		REP( i , N + 1 ) if( F[ i ] ) mapa[ i ] = sz , cost[ sz ] = i , sz ++;
		clr( G , 0 );
		REP( i , n ) G[ i ] = mapa[ v[ i ] ];
		int ans = 0 ;
		sz = 1;
		clr( color , 0 );
		REP( i , n ) {
			if( G[ i ] == i ) continue;
			if( color[ i ] != 0 ) continue;
			int p = i;
			int mini = 1e8 , sum = 0 , len = 0;
			while( color[ p ] != sz ){
				mini = min( mini , cost[ p ] );
				sum += cost[ p ]; 
				color[ p ] = sz , p = G[ p ];
				len ++;
			}
			int op1 = (sum - mini) + mini * ( len - 1 );
			int op2 = mini + cost[ 0 ] + sum + cost[ 0 ] * len;
			ans += min( op1 , op2 );
			sz ++;
		}
		printf( "Case %d: %d\n" , ++ tc , ans );
		puts("");
	}
}

