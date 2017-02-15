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

int main(){
	int n , m;
	while( sc( n ) == 1 ){
		sc( m );
		vi a( n );
		REP( i , n ) sc( a[ i ] );
		vi b( m );
		
		REP( i , m ) sc( b[ i ] ) , b[ i ] --;
		
		vi STACK;
		vi vis( n );
		REP( i , m ){
			if( vis[ b[ i ] ] ) continue;
			STACK.pb( b[ i ] );
			vis[ b[ i ] ] = 1;
		}
		REP( i , n )
			if( !vis[ i ] ) STACK.pb( i );
		reverse( all( STACK ) );
		ll ans = 0;
		for( auto id : b ){
			vi temp;
			while( 1 ){
				int pos = STACK.back();
				STACK.pop_back();
				if( pos == id ){
					break;
				}else{
					temp.pb( pos );
					ans += a[ pos ];
				}
			}
			while( !temp.empty() ){
				STACK.pb( temp.back() );
				temp.pop_back();
			}
			STACK.pb( id );
		}
		cout << ans << '\n';
	}
}



