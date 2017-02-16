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
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< pii > vpii;

#define N 40000
#define L 2

vll MOD = { 1000000007LL , 1000000009LL };
const ll B = 31;
int n;
ll POT[ 2 ][ N + 5 ];
ll AC[ 2 ][ N + 5 ];
pii get( int i , int j ){
	int len = j - i + 1;
	vi v( L );
	REP( k , L ) {
		v[ k ] = (AC[ k ][ j + 1 ] - (AC[ k ][ i ] * POT[ k ][ len ])%MOD[ k ]);
		if( v[ k ] < 0 ) v[ k ] += MOD[ k ];
	}
	return mp( v[ 0 ] , v[ 1 ] );
	
}
int id;
bool f( int len , int target ){
	vpii v;
	for( int i = 0 ; ; ++i ){
		int j = i + len - 1;
		if( j >= n ) break;
		pii p = get( i , j );
		v.pb( p );
		id = i;
	}
	sort( all( v ) );
	REP( i , SZ(v) ){
		int ind;
		for( int j = i ; j < SZ(v) ; ++j )
			if( v[ i ] == v[ j ] ) ind = j;
			else break;
		ind = i;
		if( ind - i + 1 >= target ) return 1;
	}
	return 0;
}

int main(){
	ios_base :: sync_with_stdio( 0 );
	REP( k , 2 ) {
		POT[ k ][ 0 ] = 1;
		REP( i , N ) POT[ k ][ i + 1 ] = (POT[ k ][ i ] * B)%MOD[ k ];
	}
	int target;
	while( cin >> target ){
		if( !target ) break;
		string s;
		cin >> s;
		n = SZ( s );
		REP( k , 2 )
			REP( i , n ) AC[ k ][ i + 1 ] = (AC[ k ][ i ] * B + (s[ i ] - 'a' + 1))%MOD[ k ];
		//test();
		int lo = 1 , hi = n;
		if( !f( lo , target ) ){
			cout << "none\n";
			continue;
		}
		if( f( hi , target ) ){
			cout << hi << " " << id << '\n';
			continue;
		}
		while( hi - lo > 1 ){
			int med = (lo + hi) >> 1;
			if( f( med , target ) ) lo = med;
			else hi = med;
		}
		//test();
		f( lo , target );
		cout << lo << " " << id << '\n';
	}
}



