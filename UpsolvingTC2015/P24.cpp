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

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 100000
#define LOGN 20

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;


ll rmq[ LOGN + 1 ][ N + 5 ];

ll query( int a , int b ){ 
	int r = 31 - __builtin_clz( b - a + 1 );
	return __gcd( rmq[ r ][ a ] , rmq[ r ][ b - (1<<r) + 1 ] );
}
int n;
int get( int x , int y ){
	int lo = y , hi = n - 1;
	ll target = query( x , y );
	if( query( x , hi ) == target ) return hi;
	while( hi - lo > 1 ){
		int med = (lo + hi)>>1;
		if( query( x , med ) == target ) lo = med;
		else hi = med;
	}
	return lo;
}

int main(){
	ios_base :: sync_with_stdio( 0 );
	int cases;
	cin >> cases;
	REP( tc , cases ){
		cin >> n;
		REP( i , n ) cin >> rmq[ 0 ][ i ];
		
		for( int k = 1 ; k <= LOGN ; ++k )
			for( int i = 0 ; i + (1<<k) <= n ; ++i )
				rmq[ k ][ i ] = __gcd( rmq[ k - 1 ][ i ] , rmq[ k - 1 ][ i + (1<<(k - 1)) ] );	
		ll ans = 0;
		for( int i = 0 ; i < n ; ++i ){
			for( int j = i ; j < n ; ++j ){
				j = get( i , j );
				ans = max( ans , (ll)(j - i + 1) * query( i , j ) );
			}
		}
		cout << ans << '\n';
	}
}


