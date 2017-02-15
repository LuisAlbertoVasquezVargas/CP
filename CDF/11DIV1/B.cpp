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

int main(){
	int x;
	while( sc( x ) == 1 ){
		x = abs( x );
		for( ll n = 0 ; ; ++n ){
			ll T = n * (n + 1);
			T >>= 1;
			//DEBUG( T );
			if( (x & 1) == (T & 1) ){
				if( x <= T ){
					printf( "%d\n" , (int)n );
					break;
				}
			}
		}
	}
}



