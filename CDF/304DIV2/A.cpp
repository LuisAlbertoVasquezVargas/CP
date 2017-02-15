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

typedef long long ll;
typedef vector< int > vi;
typedef pair< int , int > pii;

int main(){
	ll k , n , w;
	while( cin >> k >> n >> w ){
		ll tot = k * (( w * ( w + 1LL ) ) / 2LL) ;
		ll ans = max( 0LL , tot - n);
		cout << ans << endl;
	}

}


