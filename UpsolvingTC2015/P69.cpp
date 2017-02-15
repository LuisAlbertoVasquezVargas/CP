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

#define NODES 3400000
#define ALP 2

int NEXT[ NODES ][ ALP ] , node ,term[ NODES ] , F[ NODES ];

void init(){
	node = 1;
	clr( term , 0 );
	clr( NEXT , 0 );
	clr( F , 0 );
}
void add( ll num ){
	int p = 0;
	for( int i = 32 ; i >= 0 ; --i ){
		int c = 0;
		if( num & (1LL << i) ) c = 1;
		if( !NEXT[ p ][ c ] ) NEXT[ p ][ c ] = node++;
		p = NEXT[ p ][ c ];
		F[ p ] ++;
	}
	term[ p ] = 1;
}
ll solve( ll num ){
	int p = 0;
	ll ans = 0;
	for( int i = 32 ; i >= 0 ; --i ){
		int c = 0;
		if( num & (1LL << i) ) c = 1;
		c ^= 1;
		if( NEXT[ p ][ c ] ){
			ans |= (1LL << i);
			p = NEXT[ p ][ c ];
		}else{
			p = NEXT[ p ][ c ^ 1 ];
		}
	}
	return ans;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		init();
		ll r = 0;
		add( r );
		ll ans = 0;
		REP( i , n ){
			int x;
			sc( x );
			ans = max( ans , (ll)x );
			r ^= x;
			ans = max( ans , (ll)solve( r ) );
			add( r );
		}
		printf( "%lld\n" , ans );
	}
}

