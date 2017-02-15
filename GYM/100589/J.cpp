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
typedef vector< vll > vvll;
typedef pair< int , int > pii;
typedef vector< int > vi;

vll solve( vll &a , vll &b , vll &p ){
	vll AC( SZ(p) + 1 );
	int len = SZ( p );
	for( int i = len - 1 ; i >= 0 ; --i )
		AC[ i ] = AC[ i + 1 ] + p[ i ];
	vll ans( SZ(a) );
	REP( i , SZ(a) ){
		int pos = lower_bound( b.begin() + i , b.end() , a[ i ] ) - b.begin();
		if( pos >= SZ( p ) ) continue;
		ans[ i ] = AC[ pos ];
	}
	return ans;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n = 3;
		vvll T( n );
		vi L( n );
		REP( i , n ){
			sc( L[ i ] );
			T[ i ].resize( L[ i ] );
			REP( j , L[ i ] ) {
				int x;
				sc( x );
				T[ i ][ j ] = x;
			}
		}
		
		
		vll vec( L[ n - 1 ] , 1LL );
		for( int i = n - 2 ; i >= 0 ; --i )
			vec = solve( T[ i ] , T[ i + 1 ] , vec );
		ll ans = 0;
		REP( i , SZ( vec ) ) ans += vec[ i ];
		cout << ans << '\n';
	}
}


