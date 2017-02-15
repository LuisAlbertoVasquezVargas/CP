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

#define N 100000

typedef long long ll;
typedef vector< ll > vll;
typedef pair< ll , ll > pll;
typedef vector< pll > vpll;
typedef vector< int > vi;

#define NEUTRAL 0
#define v1 ( ( node << 1 ) + 1 )
#define v2 ( v1 + 1 )
#define med ( (a + b) >> 1 )
#define LEFT v1 , a , med
#define RIGHT v2 , med + 1 , b

ll T[ 4 * N ];

void build_tree( int node , int a , int b ){
	if( a == b ){
		T[ node ] = 0;
		return;
	}
	build_tree( LEFT );
	build_tree( RIGHT );
	T[ node ] = 0;
}
void update( int node , int a , int b , int x , ll val ){
	if( x > b || a > x ) return;
	if( a == b ){
		T[ node ] = val;
		return;
	}
	update( LEFT , x , val );
	update( RIGHT , x , val );
	T[ node ] = max( T[ v1 ] , T[ v2 ] );
}
ll query( int node , int a ,  int b , int lo , int hi ){
	if( lo > b || a > hi ) return NEUTRAL;
	if( a >= lo && hi >= b ) return T[ node ];
	return max( query( LEFT , lo , hi ) , query( RIGHT , lo , hi ) );
}

int main(){
	ios_base :: sync_with_stdio( 0 );
	int n;
	while( cin >> n ){
		vll D( n ) , V( n ) , T( n );
		build_tree( 0 , 0 , n - 1 );
		vpll vec;
		REP( i , n ){
			cin >> D[ i ] >> V[ i ] >> T[ i ];
			vec.pb( mp( D[ i ] , i ) );
		}
		sort( all( vec ) );
		vi id( n );
		REP( i , n ) id[ vec[ i ].se ] = i;
		
		ll ans = 0;
		REP( i , n ){
			int lo = lower_bound( all( vec ) , mp( D[ i ] - T[ i ] , LLONG_MIN ) ) - vec.begin();
			int hi = upper_bound( all( vec ) , mp( D[ i ] , LLONG_MAX ) ) - vec.begin();
			hi --;
			ll cur = query( 0 , 0 , n - 1 , lo , hi ) + V[ i ];
			ans = max( ans , cur );
			update( 0 , 0 , n - 1 , id[ i ] , cur );
		}
		cout << ans << '\n';
	}
}


