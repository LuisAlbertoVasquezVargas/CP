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

#define N 700000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

ll get( ll s ){
	if( s < 0 ) return 0;
	return ((s + 2) * (s + 1)) >> 1;
}
ll solve( ll a , ll b , ll c , ll L , ll l ){
	// a + x , b + y , c + z
	ll z = l - c;
	if( z < 0 ) return 0;
	if( z > L ) return 0;
	if( L - z < 0 ) return 0;
	//a + b + x + y <= l
	//x + y <= l - (a + b)
	// x + y + z <= L
	// x + y <= L - z
	// a + x <= l - 1
	// b + y <= l - 1
	return get( min( l - (a + b) , L - z) );
}

int main(){
	ll a , b , c , L;
	while( cin >> a >> b >> c >> L ){
		ll ans = ((L + 3) * (L + 2) * (L + 1)) / 6LL;
		for( int l = 2 ; l <= N ; ++l ){
			ans -= solve( a , b , c , L , l );
			ans -= solve( a , c , b , L , l );
			ans -= solve( b , c , a , L , l );
		}
		cout << ans << '\n';
	}
}


