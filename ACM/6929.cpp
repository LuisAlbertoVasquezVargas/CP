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
typedef pair< int , int > pii;
typedef vector< int > vi;

bool solve( int n , int k ){
	if( k < 2 ) return 0;
	int cur = n / k - (k - 1);
	if( cur <= 0 ) return 0;
	if( cur & 1 ) return 0;
	cur >>= 1;
	printf( "%d = %d" , n >> 1 , cur );
	for( int i = 1 ; i < k ; ++i )
		printf( " + %d" , cur + i );
	puts( "" );
	return 1;
}
void solve( int n ){
	for( int d = 1 ; d * d <= n ; ++d ){
		if( n % d == 0 ){
			if( solve( n , d ) ) return;
			if( solve( n , n/d ) ) return;
		}
	}
	puts( "IMPOSSIBLE" );
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		solve( 2 * n );
	}
}
