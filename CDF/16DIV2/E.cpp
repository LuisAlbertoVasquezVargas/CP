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

#define N 18

typedef long long ll;
typedef long double ld;
typedef pair< int , int > pii;
typedef vector< int > vi;

int n;
ld P[ N + 1 ][ N + 1 ];
ld DP[ 1 << N ];

int main(){
	while( cin >> n ){
		REP( i , n ) REP( j , n ) cin >> P[ i ][ j ];
		DP[ (1 << n) - 1 ] = 1.0;
		for( int mask = (1 << n) - 2 ; mask >= 0 ; --mask ){
			DP[ mask ] = 0;
			int ones = __builtin_popcount( mask ) + 1;
			ld coef = (ones * (ones - 1)) /2.0;
			REP( i , n )
				if( !(mask & (1 << i)) ){
					REP( j , n )
						if( (mask & (1 << j)) )
							DP[ mask ] += (P[ j ][ i ]/ coef) * DP[ mask ^ (1 << i) ];
				}
		}
		REP( i , n ) printf( "%.15f%c" , (double)DP[ 1 << i ] , (i + 1 == n ? 10 : 32) );
	}
}
