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
		vi v;
		REP( i , n ){
			int x;
			sc( x );
			v.pb( x );
		}
		sort( all( v ) );
		ll timer = 0;
		int ans = 0;
		REP( i , SZ( v ) ){
			if( timer > v[ i ] ) continue;
			ans ++;
			timer += v[ i ];
		}
		printf( "%d\n" , ans );
	}
}


