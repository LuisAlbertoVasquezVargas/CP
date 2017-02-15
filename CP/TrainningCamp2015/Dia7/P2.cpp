#include<vector>
#include<iostream>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define pb push_back
#define SZ( v ) ((int)(v).size())

#define N 100

typedef long long ll;
typedef vector< int > vi;

void get( ll n , vi &p , vi &e ){
	for( int i = 2 ; i * i <= n ; ++i )
		if( n % i == 0 ){
			p.pb( i );
			int ct = 0;
			while( n % i == 0 ) n /= i , ct ++;
			e.pb( ct );
		}	
	//test();
	if( n > 1 ) p.pb( n ) , e.pb( 1 );
}
ll C[ N + 1 ][ N + 1 ];
ll cata( ll n ){
	return C[ n + n ][ n ] / (n + 1);
}
int main(){
	REP( i , N ) C[ i ][ i ] = C[ i ][ 0 ] = 1;
	for( int i = 2 ; i <= N ; ++i )
		for( int j = 1 ; j < i ; ++j )
			C[ i ][ j ] = C[ i - 1 ][ j - 1 ] + C[ i - 1 ][ j ];
	ll n;
	while( cin >> n ){
		vi p , e;
		//test();
		get(n , p ,e);
		//test();
		ll ans = 1 , sum = 0;
		REP( i , SZ(e) ){
			sum += e[ i ];
			ans *= C[ sum ][ e[ i ] ];
		}
		ans *= cata( sum - 1 );
		cout << ans << '\n';
	}
}

