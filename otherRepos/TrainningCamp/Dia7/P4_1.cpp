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
typedef unsigned long long ull;
typedef vector< ull > vull;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;

#define N 40000
#define L 2

const ll B = 27;
int n;
ull POT[ N + 5 ];
ull AC[ N + 5 ];
ull get( int i , int j ){
	int len = j - i + 1;
	return (AC[ j + 1 ] - (AC[ i ] * POT[ len ]));
}
int id;
bool f( int len , int target ){
	vector< pair< ull , int > > v;
	bool ok = 0;
	for( int i = 0 ; ; ++i ){
		int j = i + len - 1;
		if( j >= n ) break;
		ull p = get( i , j );
		v.pb( mp( p , i ) );
	}
	sort( all( v ) );
	id = INT_MIN;
	REP( i , SZ(v) ){
		int ind , maxi = INT_MIN;
		for( int j = i ; j < SZ(v) ; ++j )
			if( v[ i ].fi == v[ j ].fi ) ind = j , maxi = max( maxi , v[ j ].se);
			else break;
		if( ind - i + 1 >= target ){
			ok = 1;
			id = max( maxi , id );
		}
		ind = i;
	}
	return ok;
}
char s[ N + 5 ];
int main(){
	POT[ 0 ] = 1;
	REP( i , N ) POT[ i + 1 ] = (POT[ i ] * B);
	int target;
	while( sc( target ) == 1 ){
		if( !target ) break;
		scanf( "%s" , s );
		n = strlen( s );
		REP( i , n ) AC[ i + 1 ] = (AC[ i ] * B + (s[ i ] - 'a' + 1));

		if( target == 1 ){
			printf( "%d 0\n" , n );
			continue;
		}
		int lo = 1 , hi = n;
		if( !f( lo , target ) ){
			puts( "none" );
			continue;
		}
		while( hi - lo > 1 ){
			int med = (lo + hi) >> 1;
			if( f( med , target ) ) lo = med;
			else hi = med;
		}
		//test();
		//DEBUG( n );
		f( lo , target );
		printf( "%d %d\n" , lo , id );
	}
}



