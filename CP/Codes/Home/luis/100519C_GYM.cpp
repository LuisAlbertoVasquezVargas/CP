#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

typedef vector< int > vi;
typedef long long ll;

ll floor( ll a , ll b ){ return a / b; };
ll ceil( ll a , ll b ){ return a == 0 ? 0 : ((a - 1)/b + 1);}
int main(){
	ll a , b , c;
	while( cin >> a >> b >> c ){
		if( a >= b ) cout << ceil( c , b ) << " " << ceil( c , b ) << '\n';
		else{
			ll ans1 = ceil( c , a ) , L = floor( b , a ) , X = floor( c , a );
			ll Y = c % a + a * ( X % L );
			ll ans2 = floor( X , L ) + ceil( Y , b );
			cout << ans1 << " " << ans2 << '\n';
		}
	}
}


