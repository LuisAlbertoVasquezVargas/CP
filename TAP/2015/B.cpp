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
typedef long double ld;
typedef vector< ld > vld;
typedef pair< int , int > pii;
typedef vector< int > vi;

bool f( ll t , ll L , ll K ){//chapa mayor >= t
	if( t == 0 ) return 1;
	int cnt = 0;
	for( int i = 0 ; i < L ; ++i ){
		ll cur = 0;
		int ind = -1;
		for( int j = i ; j < L ; ++j )
			if( cur < t ) cur += (ll)( 2LL * j + 1LL ) , ind = j;
			else break;
		if( cur >= t ) cnt ++;
		i = ind;
	}
	return cnt >= K;
}
int main(){
	int L , K;
	while( sc( L ) == 1 ){
		sc( K );
		ll lo = 0 , hi = (ll)L * (ll)L + 5;
		while( hi - lo > 1 ){
			ll med = (lo + hi) >> 1;
			if( f( med , L , K ) ) lo = med;
			else hi = med;
		}
		cout << lo << '\n';
	}
}


