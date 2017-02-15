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

#define test puts("************test************");
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 100000
#define ALP 2
#define LAST 31

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

ll AC[ 34 * N + 5 ];
int NEXT[ 34 * N + 5 ][ ALP ] , node;

void init(){
	node = 1;
	clr( NEXT , 0 );
}
void add( ll x ){
	int p = 0;
	for( int i = LAST ; i >= 0 ; --i ){
		int cur = (x & (1LL << i)) > 0;
		assert( cur <= 1 );
		if( !NEXT[ p ][ cur ] ) NEXT[ p ][ cur ] = node++;
		p = NEXT[ p ][ cur ];
	}
}
ll get( ll x ){
	int p = 0;
	ll ans = 0;
	for( int i = LAST ; i >= 0 ; --i ){
		int cur = (x & (1LL << i)) > 0;
		if( NEXT[ p ][ cur ^ 1 ] ){
			ans |= (1LL << i);
			p = NEXT[ p ][ cur ^ 1 ];
			continue;
		}
		if( NEXT[ p ][ cur ] ){
			p = NEXT[ p ][ cur ];
			continue;
		}
		assert( 0 );
		break;
	}
	return ans;
}
////  1110011
////  00011
int main(){
	ios_base :: sync_with_stdio( 0 );
	int cases;
	cin >> cases ;
	REP( tc , cases ){
		init();
		int n;
		cin >> n;
		ll maxi = 0;
		add( 0LL );
		REP( i , n ){
			ll x;
			cin >> x;
			AC[ i + 1 ] = AC[ i ] ^ x;
			ll y = get( AC[ i + 1 ] );
			maxi = max( maxi , y );
			add( AC[ i + 1 ] );
		}
		cout << maxi << '\n';
	}
}


