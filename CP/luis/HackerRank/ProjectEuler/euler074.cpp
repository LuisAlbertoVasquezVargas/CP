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

#define N 3000000
#define M 1000000

typedef vector< int > vi;
typedef long long ll;

int vis[ N + 5 ] , F[ N + 5 ];
int fact[ 20 ];
int next( int x ){
	if( F[ x ] != -1 ) return F[ x ];
	if( x == 0 ) return 1;
	int S = 0;
	while( x ){
		S += fact[ x % 10 ];
		x /= 10;
	}
	return F[ x ] = S;
}

vi T[ 65 ];
int main(){
	clr( F , -1 );
	fact[ 0 ] = 1LL;
	for( ll i = 1 ; i <= 9 ; ++i ) fact[ i ] = fact[ i - 1 ] * i;
	
	for( int i = 0 ; i <= M ; ++i ){
		vi vec;
		int num = i;
		while( 1 ){
			if( vis[ num ] ) break;
			vis[ num ] = 1;
			vec.pb( num );
			num = next( num );
		}
		REP( i , SZ( vec ) ) vis[ vec[ i ] ] = 0;
		T[ SZ( vec ) ].pb( i );
	}

	int cases;
	sc( cases );
	REP( tc , cases ){
		int n , L;
		sc( n ) , sc( L );
		vi vec;
		for( int x : T[ L ] )
			if( x <= n ) vec.pb( x );
			else break;
		if( !SZ( vec ) ){
			puts( "-1" );
			continue;
		}
		REP( i , SZ( vec ) ) printf( "%d%c" , vec[ i ] , (i + 1 == SZ(vec)) ? 10 : 32 );
	}
}



