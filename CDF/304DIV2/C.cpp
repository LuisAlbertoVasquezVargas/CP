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

ll POT[ 20 ];
bool ok , found;
set< ll > SET;
ll getHash( deque< int > &v ){
	ll ans = 0;
	REP( i , SZ( v ) ) ans = ans * 10 + v[ i ];
	return ans;
}
int winner;
int ans;
void f( deque< int > &a , deque< int > &b , int d ){
	if( !ok ) return;
	if( found ) return;
	ll code = getHash( a ) * POT[ SZ( b ) + 1 ] + getHash( b );
	if( SET.count( code ) ){
		ok = 0;
		return;	
	}
	SET.insert( code );
	if( !SZ( a ) ){
		winner = 1;
		found = 1;
		ans = d;
		return;
	}
	if( !SZ( b ) ){
		winner = 0;
		found = 1;
		ans = d;
		return;
	}
	deque< int > v = a , w = b;
	int x = v.back() , y = w.back();
	v.pop_back() , w.pop_back();
	if( x < y ){
		w.push_front( min( x , y ) );
		w.push_front( max( x , y ) );
	}else{
		v.push_front( min( x , y ) );
		v.push_front( max( x , y ) );
	}
	f( v , w , d + 1 );
}
int main(){
	POT[ 0 ] = 1;
	for( int i = 1 ; i <= 19 ; ++i ) POT[ i ] = POT[ i - 1 ] * 10LL;
	
	int n;
	while( sc( n ) == 1 ){
		int k1 , k2;
		deque< int > v , w;
		sc( k1 );
		REP( i , k1 ){
			int x;
			sc( x );
			v.pb( x );
		}
		sc( k2 );
		REP( i , k2 ){
			int x;
			sc( x );
			w.pb( x );
		}
		reverse( all( v ) );
		reverse( all( w ) );
		SET.clear();
		ok = 1;
		found = 0;
		f( v , w , 0 );
		if( !ok ){
			puts( "-1" );
			continue;
		}
		printf( "%d %d\n" , ans , winner + 1 );
	}
}


