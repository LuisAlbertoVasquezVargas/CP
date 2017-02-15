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

typedef long long ll;
typedef vector< int > vi;

int F[ N + 5 ];

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		vi vec;
		REP( i , n ){
			int x;
			sc( x );
			if( !F[ x ] ){
				F[ x ] = 1;
				vec.pb( x );
			}
		}
		REP( i , SZ( vec ) ) F[ vec[ i ] ] = 0;
		printf( "%d\n" , SZ( vec ) );
	}
}


