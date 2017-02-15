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

#define N 100

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int G[ N + 5 ][ N + 5 ];

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		int m = n * (n - 1);
		m >>= 1;
		clr( G , 0 );
		REP( i , m ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			G[ u ][ v ] = 1;
		}
		vi vec;
		REP( u , n ){
			int pos = -1;
			REP( i , SZ( vec ) ){
				int v = vec[ i ];
				if( G[ u ][ v ] ){
					pos = i;
					break;
				}
			}
			if( pos == -1 ){
				vec.pb( u );
			}else{
				vec.insert( vec.begin() + pos , u );
			}
		}
		REP( i , SZ(vec) ) printf( "%d%c" , vec[ i ] + 1 , (i + 1 == SZ(vec) ? 10 : 32 ) );
	}
}


