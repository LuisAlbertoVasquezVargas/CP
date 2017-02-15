#include<bits/stdc++.h>
using namespace std;
 
#define sc(x) scanf( "%d" , &x )
#define REP(i , n) for( int i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )
 
#define pb push_back
#define all(v) v.begin() , v.end()
#define SZ(v) ((int)(v).size())
 
#define mp make_pair
#define fi first
#define se second

#define DEBUG( x ) cerr << #x << " " << x << endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;

void doit( int &lastZero , vi &a , ll timer ){
	if( lastZero == SZ( a ) - 1 ) return;
	while( lastZero + 1 < SZ( a ) && !a[ lastZero + 1 ] ) lastZero ++;
	
	timer -= lastZero + 1;
	
	if( timer <= 0 ) return;
	
	for( int pos = lastZero + 1 ; pos < SZ( a ) ; ++pos ){
		ll cur = min( timer , (ll)a[ pos ] );
		a[ pos ] -= cur;
		timer -= cur;
		if( timer == 0 ) return;
		timer --;
	}
}
bool f( ll timer , vi a , int m ){
	int n = SZ( a );
	int pos = 0;
	REP( i , m ) doit( pos , a , timer );
	return a == vi( n );
}

int main(){
	int n , m;
	while( sc( n ) == 1 ){
		sc( m );
		vi a( n + 1 );
		REP( i , n ) sc( a[ i + 1 ] );
		
		
		ll lo = 0 , hi = 1000000000000000;
		if( f( lo, a , m ) ){
			cout << '0' << '\n';
			continue;
		}
		
		while( hi - lo > 1 ){
			ll med = (lo + hi) >> 1;
			if( f( med , a , m ) ) hi = med;
			else lo = med;
		}
		cout << hi << '\n';
	}
}


