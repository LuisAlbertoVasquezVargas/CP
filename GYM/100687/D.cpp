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
typedef long double ld;


ll n , m , K;
bool f( ll t ){
	ll nK = K - t;
	ll nm = m - t;
	if( nK < 0 ) return 0;
	return 3LL * nK >= nm + n;
}
ll solve(){
	ll lo = 0 , hi = m;
	if( f( hi ) ) return hi;
	while( hi - lo > 1 ){
		ll med = (lo + hi) >> 1;
		if( f( med ) ) lo = med;
		else hi = med;
	}
	return lo;
}
int main(){	
	while( cin >> n >> m >> K ){
		if( 3LL * K < n + m ){
			cout << -1 << '\n';
			continue;
		}
		cout << m - solve() << '\n';
	}
}


