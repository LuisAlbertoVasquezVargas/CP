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

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

ll f( ll T , ll S , ll q ){
	for( ll e = 1 , p = S ; ; e ++ ){
		p *= q;
		if( p >= T ) return e;
	}
	assert( 0 );
}
int main(){
	ll T , S , q;
	while( cin >> T >> S >> q )
		cout << f( T , S , q ) << '\n';
}


