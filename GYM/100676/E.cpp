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

#define MAXVAL 10000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

const int cte = 31;
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		vi a;
		REP( i , n ){
			int x;
			sc( x );
			a.pb( x );
		}
		vi F( MAXVAL + 1 );
		ll ans = 0;
		for( int i = n - 1 ; i >= 0 ; --i ){
			int target = a[ i ];
			for( int k = max(0 , target - cte) ; k <= min(target + cte , MAXVAL) ; ++k )
				ans += F[ k ];
			F[ a[ i ] ] ++;
		}
		cout << ans << '\n';
	}
}


