#include<bits/stdc++.h>
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
typedef pair< int , int > pii;
typedef vector< int > vi;

ll f( ll d , vi &v ){
	ll ans = 0 ;
	for( auto x : v ){
		ans += upper_bound( all( v ) , x + d ) - lower_bound( all( v ) , x - d );
		ans --;
	}
	return ans >> 1;
}
int main(){
	int n , K;
	while( sc( n ) == 1 ){
		sc( K );
		if( n == 0 && K == 0 ) break;
		vi v;
		REP( i , n ){
			int x;
			sc( x );
			v.pb( x );
		}
		sort( all( v ) );
		ll lo = 0 , hi = 1e9 + 10;
		while( hi - lo > 1 ){
			ll med = (lo + hi) >> 1;
			if( f( med , v ) >= K ) hi = med;
			else lo = med;
		}
		ll d = hi;
		K -= f( lo , v );
		assert( K >= 1 );
		vi vec;
		for( auto x : v )
			if( binary_search( all( v ) , x + d ) ) vec.pb( x );
			
		int ans = vec[ K - 1 ];
		printf( "%d %d\n" , ans , ans + d );
	}
}


