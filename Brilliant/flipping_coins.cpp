#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define N 100
#define INF 1234567

typedef long long ll;
typedef vector< int > vi;
typedef vector< vi > vvi;
// i 
int main(){
	vvi dist( N + 5 , vi( N + 5 , INF ) );
	queue< int > Q;
	int x = 0 , y = 100;
	Q.push( x ) , Q.push( y );
	dist[ x ][ y ] = 0;
	while( !Q.empty() ){
		x = Q.front(); Q.pop();
		y = Q.front(); Q.pop();
		for( int i = 0 ; i <= x ; ++i ){
			int j = 93 - i;
			if( 0 <= j && j <= y ){
				if( dist[ x - i + j ][ y - j + i ] >= INF ){
					Q.push( x - i + j ); Q.push( y - j + i );
					dist[ x - i + j ][ y - j + i ] = 1 + dist[ x ][ y ];
				}
			}
		}
	}
	printf( "%d\n" , dist[ 100 ][ 0 ] );
}


