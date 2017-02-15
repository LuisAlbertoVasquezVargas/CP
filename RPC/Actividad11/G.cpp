#include <bits/stdc++.h>
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

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef long double ld;

int main(){
	int tc = 0;
	int n , K;
	while( sc( n ) == 1 ){
		sc( K );
		if( n == 0 && K == 0 ) break;
		vpii v;
		REP( i , n ){
			int s , p;
			sc( s ) , sc( p );
			v.pb( mp( s , p ) );
		}
		sort( all( v ) );
		ld ans = 1e50;
		vll AC( n + 1 );
		REP( i , n ) AC[ i + 1 ] = AC[ i ] + (ll) v[ i ].fi;
		for( int i = 0 ; i < n ; ++i ){
			if( i + 1 >= K ){
				ll sum = AC[ K - 1 ] + (ll)v[ i ].fi;
				ans = min( ans , (ld)sum * (ld)v[ i ].se / (ld)v[ i ].fi );
			}
		}
		printf( "Case #%d: %.6f\n" , ++tc , (double ) ans );
	}
}





