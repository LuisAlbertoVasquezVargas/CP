#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

typedef pair< int , int > pii;
typedef long long ll;
typedef vector< int > vi;

int main(){
	ll n , m;
	int tc = 0;
	while( cin >> n >> m ){
		if( !n && !m ) break;
		ll ans = 0;
		for( ll i = 1 ; i <= n ; ++i )
			for( ll j = 1 ; j <= m ; ++j )
				ans += ( 4LL * (i - 1) * (j - 1) + 2LL*(i - 1LL) + 2LL*(j - 1LL) + 2LL* ( (i + 1LL)*(j + 1LL) - 4LL - (__gcd( i , j ) -1LL) ) + 4LL ) * ( n - i + 1LL ) * ( m - j + 1LL ) ;
		cout << "Case " << ++tc << ": " << ans << '\n';
	}
}


