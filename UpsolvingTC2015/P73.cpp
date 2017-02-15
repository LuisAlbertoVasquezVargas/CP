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

#define N 20

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int n;
int A[ N + 1 ][ N + 1 ];
bool used[ 1 << N ];
ll memo[ 1 << N ];
ll dp( int mask ){
	int ones = __builtin_popcount( mask );
	if( ones == n ) return 1LL;
	if( used[ mask ] ) return memo[ mask ];
	used[ mask ] = 1;
	ll &dev = memo[ mask ] = 0;
	int pos = ones;
	REP( i , n )
		if( A[ pos ][ i ] ){
			if( !(mask & (1 << i)) )
				dev += dp( mask ^ (1 << i) );
		}
	return dev;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		sc( n );
		REP( i , n ) REP( j , n ) sc( A[ i ][ j ] );
		clr( used , 0 );
		cout << dp( 0 ) << '\n';
	}
}


