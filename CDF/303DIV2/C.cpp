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

typedef long long ll;
typedef vector< int > vi;
typedef pair< int , int > pii;

int main(){
	int n;
	while( sc( n ) == 1 ){
		vi x( n ) , h( n );
		REP( i , n ){
			sc( x[ i ] ) , sc( h[ i ] );
		}
		x.pb( 2000000009 );
		int ans = 1 , last = x[ 0 ];
		for( int i = 1 ; i < n ; ++i ){
			if( x[ i ] - last > h[ i ] ){
				ans ++ , last = x[ i ];
				continue;
			}
			if( x[ i ] + h[ i ] < x[ i + 1 ] ){
				ans ++;
				last = x[ i ] + h[ i ];
				continue;
			}
			last = x[ i ];
		}
		printf( "%d\n" , ans );
	}
}
