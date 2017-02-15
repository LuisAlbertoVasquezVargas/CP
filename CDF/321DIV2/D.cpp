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

#define N 18

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

inline int ones( int x ){ return __builtin_popcount( x );}
int len , n;
int A[ N + 1 ];
int G[ N + 1 ][ N + 1 ];
bool used[ N + 1 ][ 1 << N ];
ll memo[ N + 1 ][ 1 << N ];
ll dp( int u , int mask ){
	if( ones( mask ) == len ) return 0;
	if( used[ u ][ mask ] ) return memo[ u ][ mask ];
	used[ u ][ mask ] = 1;
	
	ll &dev = memo[ u ][ mask ] = 0;
	REP( v , n )
		if( !(mask & (1 << v)) )
			dev = max( dev , (ll)G[ u ][ v ] + (ll)A[ v ] + dp( v , mask | (1 << v) ) );
	return dev;
}
int main(){
	int m;
	while( sc( n ) == 1 ){
		sc( len ) , sc( m );
		REP( i , n ) sc( A[ i ] );
		clr( G , 0 );
		REP( i , m ){
			int u , v , w ;
			sc( u ) , sc( v ) , sc( w );
			u -- , v --;
			G[ u ][ v ] = w;
		}
		clr( used , 0 );
		ll ans = 0;
		REP( i , n ) ans = max( ans , A[ i ] + dp( i , (1 << i) ) );
		cout << ans << '\n';
	}
}



