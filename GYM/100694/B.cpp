#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define INF (1<<20)
#define N 200000

#define DEBUG( x ) cout << #x << " " << (x) << endl;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef long long ll;

ll solve( ll p , ll n , ll x ){
	if( x == 0 ) return 0;
	ll ans = LLONG_MAX;
	ll cur = (x/p);
	ans = min( ans , x - cur * p + cur );
	cur = (x - 1LL)/p + 1LL;
	ans = min( ans , min( n , cur * p ) - x + cur );
	return ans;
}
int main(){
	ll p , n , x;
	while( cin >> p >> n >> x ){
		ll ans = solve( p , n , x );
		ans = min( ans , (n - 1LL)/p + 1LL + solve( p , n , n - x ) );
		cout << ans << '\n';
	}
}
