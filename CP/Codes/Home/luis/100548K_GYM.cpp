#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) ) 

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define fi first
#define se second
#define mp make_pair

typedef long long ll;

ll g( ll a , ll b ){
	if( a == 0 && b == 0 ) return 1;
	if( a == 0 || b == 0 ) return 2;
	if( b % a == 0 ) return 1 + b/a;
	if( a % b == 0 ) return 1 + a/b;
	if( a < b ){
		ll q = b/a;
		if( q & 1 ) return q + g( b % a , a );
		return q + g( a , b % a );
	}else{
		ll q = a/b;
		if( q & 1 ) return q + g( b , a % b );
		return q + g( a % b , b );
	}
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		ll a , b;
		cin >> a >> b;
		cout << "Case #" << tc + 1 << ": " << g( a , b ) << '\n';
	}
}
