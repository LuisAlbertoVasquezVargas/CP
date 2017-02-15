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
typedef vector< int > vi;

int dx[] = { +1 , -1 };

int main(){
	int n;
	while( sc( n ) == 1 ){
		vi x( n );
		REP( i , n ) sc( x[ i ] );
		vi vis( n );
		int cur = 0 , ans = 0 , pos = 0 , dir = 0;
		while( 1 ){
			if( cur == n ) break;
			int jump = 0;
			REP( L , n + 1 ){
				int npos = pos + dx[ dir ] * L;
				if( npos >= 0 && npos < n ){
					if( !vis[ npos ] && x[ npos ] <= cur ){
						vis[ npos ] = 1;
						cur ++;
						pos = npos;
						jump = 1;
						break;
					}
				}
			}
			if( jump ) continue;
			ans ++;
			dir ^= 1;
			REP( L , n + 1 ){
				int npos = pos + dx[ dir ] * L;
				if( npos >= 0 && npos < n ){
					if( !vis[ npos ] && x[ npos ] <= cur ){
						vis[ npos ] = 1;
						cur ++;
						pos = npos;
						jump = 1;
						break;
					}
				}
			}
		}
		printf( "%d\n" , ans );
	}
}


