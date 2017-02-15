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

ll count( ll x , ll m ){
	if( x < 0 ) return 0LL;
	return x/m + 1;
}
ll solve( ll a , ll b , ll m ){
	return count( b , m ) - count( a - 1 , m );
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	int n ;
	ll m;
	while( cin >> n >> m ){
		ll S = 0 , ans = 0;
		REP( i , n ){
			int d;
			cin >> d;
			ans += solve( S , S + d - 1 , m );
			S += d + 1;
		}
		cout << ans << '\n';
	}
}

