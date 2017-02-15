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
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;

ll solve( ll n ){
	vi vis( n );
	ll ans = 0;
	for( ll p = 1 ; p < n ; ++p ){
		vi vec;
		ll cur = p;
		while( 1 ){
			if( vis[ cur ] ) break;
			DEBUG( cur );
			vis[ cur ] = 1;
			vec.pb( cur );
			ans ++;
			cur = (cur * p)%n;
		}
		for( auto x : vec ) vis[ x ] = 0;
		test();
	}
	return ans;
}
int main(){
	ll n ;
	while( cin >> n ){
		cout << n << " " << (n - 1) * (n - 1) << " " << solve( n ) << endl;
	}
}

