#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

typedef long long ll;

ll lcm( ll a , ll b ){
	return a * ( b / __gcd( a , b ) );
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n , d;
		sc( n ) , sc( d );
		ll LCM = 1;
		REP( i , n ){
			int x;
			sc( x );
			LCM = lcm( LCM , x - d );
		}
		cout << LCM << '\n';
	}
}


