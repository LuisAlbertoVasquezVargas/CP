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

#define N 4005
#define MOD 1000000007

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;



int C[ N + 5 ][ N + 5 ];
void init(){
    clr( C, 0 );
	REP( i , N + 1 ) C[ i ][ i ] = C[ i ][ 0 ] = 1;
    for( int i = 2 ; i <= N ; ++i )
         for( int j = 1 ; j <= i ; ++j )
            C[ i ][ j ] = ( C[ i - 1 ][ j ] + C[ i - 1 ][ j - 1 ] ) % MOD;
}
bool used[ N + 5 ];
int memo[ N + 5 ];
int dp( int n ){
	if( n == 0 ) return 1;
	if( used[ n ] ) return memo[ n ];
	used[ n ] = 1;
	int &dev = memo[ n ] = 0;
	for( int k = 0 ; k < n ; ++k )
		dev = (dev + (ll) C[ n - 1 ][ k ] * (ll) dp( k ) )%MOD;
	return dev;
}
int main(){
	init();
	int n;
	while( sc( n ) == 1 ){
		ll ans = 0;
		for( int u = 1 ; u <= n ; ++u )
			ans = (ans + (ll)C[ n ][ u ] * (ll) dp( n - u ) ) %MOD;
		cout << ans << '\n';
	}
}

