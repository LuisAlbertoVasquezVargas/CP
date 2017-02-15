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

#define test puts("************test************");
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 100
#define MOD 1000000007LL

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< ll > vll;

ll pow( ll a , ll b , ll c ){
	ll ans = 1;
	while( b ){
		if( b & 1 ) ans = (ans * a)%c;
		a = (a * a)%c;
		b >>= 1;
	}
	return ans;
}
ll F[ N + 5 ] , C[ N + 5 ][ N + 5 ];
bool used[ N + 5 ][ N * N + 5 ];
ll memo[ N + 5 ][ N * N + 5 ];
ll factor[ N + 5 ][ N + 5 ];
int n;
ll dp( int pos , int cur ){
	if( pos == n ) return cur == 0 ;
	if( used[ pos ][ cur ] ) return memo[ pos ][ cur ];
	used[ pos ][ cur ] = 1;
	ll &dev = memo[ pos ][ cur ] = 0;
	for( int r = 0 ; r <= n ; ++r )
		if( cur - r >= 0 ) 
			dev = (dev + factor[ r ][ pos ] * dp( pos + 1 , cur - r ) )%MOD;
	return dev;
}
int main(){
	for( int i = 0 ; i <= N ; ++i ) C[ i ][ i ] = C[ i ][ 0 ] = 1;
	for( int i = 2 ; i <= N ; ++i )
		for( int j = 1 ; j < i ; ++j ){
			C[ i ][ j ] = C[ i - 1 ][ j - 1 ] + C[ i - 1 ][ j ];
			if( C[ i ][ j ] >= MOD ) C[ i ][ j ] -= MOD;
		}
	ll m , K;
	while( cin >> n >> m >> K ){
		REP( i , n ) F[ i ] = m/n;
		REP( i , m % n ) F[ i ] ++;
		clr( used , 0 );
		for( int r = 0 ; r <= n ; ++r )
			for( int pos = 0 ; pos < n ; ++ pos )
				factor[ r ][ pos ] = pow( C[ n ][ r ] , F[ pos ] , MOD );
		//REP( i , n ) cout << F[ i ] << " ";cout << endl;
		cout << dp( 0 , K ) << '\n';
	}
}

