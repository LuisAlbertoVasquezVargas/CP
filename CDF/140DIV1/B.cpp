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

#define N 100000

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef vector< vvpii > vvvpii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector< vvvi > vvvvi;

ll AC[ N + 5 ];
int n;
ll corner;
ll solve( ll k ){
	if( k == 1 ){
		if( n == 1 ) return 0;
		return corner;
	}
	ll S = 0;
	ll len = 1 , last = 0 , lvl = 0;
	while( 1 ){
		if( last >= n ) break;
		ll hi = min( last + len - 1 , (ll)n - 1 );
		ll sum = AC[ hi + 1 ] - AC[ last ];
		S += sum * lvl;
		last = hi + 1;
		len *= k;
		lvl ++;
	}
	return S;	
}
int main(){
	
	while( sc( n ) == 1 ){
		vll v;
		REP( i , n ){
			int x;
			sc( x );
			v.pb( x );
		}
		sort( all( v ) );
		reverse( all( v ) );
		
		REP( i , n ) AC[ i + 1 ] = AC[ i ] + v[ i ];
		corner = 0;
		for( ll i = 0 ; i < n ; ++i ) corner += i * v[ i ];
		int Q;
		sc( Q );
		REP( q , Q ){
			int x;
			sc( x );
			if( q ) cout << ' ';
			cout << solve( x );
		}
		cout << '\n';
	}
}



