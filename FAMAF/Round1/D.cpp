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
typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef vector< int > vi;

int main(){
	vi len( 2 );
	while( scanf( "%d%d" , &len[ 0 ] , &len[ 1 ] ) == 2 ){
		vector< map< int , int > > mapa( 2 );
		REP( i , 2 ){
			REP( j , len[ i ] ){
				int x;
				sc( x );
				mapa[ i ][ x ] ++;
			}
		}
		
		vector< deque< pii > > P( 2 );
		REP( i , 2 ) P[ i ] = deque< pii > ( all( mapa[ i ] ) );
		
		reverse( all( P[ 1 ] ) );
		bool possible = 1;
		for( auto a : P[ 0 ] ){
			int freq = a.se;
			bool found = 0;
			while( SZ( P[ 1 ] ) ){
				int x = P[ 1 ][ 0 ].se;
				P[ 1 ].pop_front();
				if( x < freq ) continue;
				else {
					found = 1;
					break;
				}
			}
			if( !found ){
				possible = 0;
				break;
			}
		}
		puts( possible ? "1" : "0" );
	}
}



