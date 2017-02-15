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

#define test() cerr << "hola q hace" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 15

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;

bool used[ N ][ 1 << N ];
ll memo[ N ][ 1 << N ];
int n , K;
ll dp( int last , int mask ){
	if( mask == (1 << n) - 1 ) return 1;
	if( used[ last ][ mask ] ) return memo[ last ][ mask ];
	used[ last ][ mask ] = 1;
	ll &dev = memo[ last ][ mask ] = 0;
	REP( i , n )
		if( !(mask & (1 << i)) && abs(last - i) <= K ){
			dev += dp( i , mask | (1 << i) );
		}
	return dev;
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	int cases;
	cin >> cases;
	REP( tc , cases ){
		
		cin >> n >> K;
		clr( used , 0 );
		ll ans = 0;
		REP( last , n ) ans += dp( last , (1<<last) );
		cout << ans << '\n';
	}
}


