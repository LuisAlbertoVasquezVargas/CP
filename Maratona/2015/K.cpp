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

#define N 2000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

bool used[ N + 5 ][ N + 5 ];
pii memo[ N + 5 ][ N + 5 ];
char S[ N + 1 ];
int T[ N + 1 ]; 
pii dp( int lo , int hi ){
	if( lo > hi ) return mp( 0 , 0 );
	if( lo == hi ) return mp( T[ lo ] , 1 );
	if( used[ lo ][ hi ] ) return memo[ lo ][ hi ];
	used[ lo ][ hi ] = 1;
	pii &dev = memo[ lo ][ hi ] = mp( 0 , 0 );
	dev = max( dev , dp( lo , hi - 1 ) );
	dev = max( dev , dp( lo + 1 , hi ) );
	if( S[ lo ] == S[ hi ] ) {
		pii cur = dp( lo + 1 , hi - 1 );
		dev = max( dev , mp( cur.fi + T[ lo ] + T[ hi ] , cur.se + 2 ) );
	}
	return dev;
}
int main(){
	while( scanf( "%s" , S ) == 1 ){
		int n = strlen( S );
		int K ;
		sc( K );
		REP( i , n ) T[ i ] = 0;
		REP( i , K ){
			int x;
			sc( x );
			x --;
			T[ x ] = 1;
		}
		REP( i , n ) REP( j , n ) used[ i ][ j ] = 0;
		pii p = dp( 0 , n - 1 );
		printf( "%d\n" , p.se );
	}
}



