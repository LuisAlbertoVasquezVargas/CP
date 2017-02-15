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
typedef vector< vi > vvi;
typedef vector< bool > vb;
typedef vector< vb > vvb;

const int MOD = 1000000007;
vvi memo;
vvb used;
vi val , freq;
int mode;
int dp( int last , int cur ){
	if( last == -1 ) {
		if( mode ) return cur == 0;
		return 1;
	}
	if( used[ last ][ cur ] ) return memo[ last ][ cur ];
	used[ last ][ cur ] = 1;
	
	int &dev = memo[ last ][ cur ] = dp( last - 1 , cur );
	if( cur - 1 >= 0 ) dev = ((ll)dev + (ll)freq[ last ] * (ll)dp( last , cur - 1 ) )%MOD;
	return dev;
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	int n , K;
	ll L;
	while( cin >> n ){
		cin >> L >> K;
		vi A( n );
		REP( i , n ) cin >> A[ i ];
		
		vi B = A;
		val.clear();
		freq.clear();
		sort( all( B ) );
		REP( i , SZ(B) ){
			int ind = -1;
			for( int j = i ; j < SZ(B) ; ++j )
				if( B[ i ] == B[ j ] ) ind = j;
				else break;
			val.pb( B[ i ] );
			freq.pb( ind - i + 1 );
			i = ind;
		}
		ll g = L / n;
		memo = vvi( SZ( val ) + 5 , vi( K + 5 ) );
		used = vvb( SZ( val ) + 5 , vb( K + 5 ) );
		mode = 1;
		int ans = 0;
		for( int len = 1 ; len <= min( g , (ll)K ) ; ++len )
			ans = ( (ll)ans + (ll)((g - len + 1) % MOD) * (ll)dp( SZ(val) - 1 , len ) )%MOD;
		used = vvb( SZ( val ) + 5 , vb( K + 5 ) );
		mode = 0;
		int lvl = (int)min( g , (ll)K - 1 );
		REP( i , (int)(L % n) ){
			int pos = lower_bound( all( val ) , A[ i ] ) - val.begin();
			ans = ans + dp( pos , lvl );
			if( ans >= MOD ) ans -= MOD;
		}
		cout << ans << '\n';
	}
}



