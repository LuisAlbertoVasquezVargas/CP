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

#define N 200000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

char S[ N + 5 ];
int main(){
	int n;
	while( sc( n ) == 1 ){
		scanf( "%s" , S );
		vi cnt( 2 );
		REP( i , 2 ) cnt[ i ] = count( S , S + n , '0' + i );
		int len = min( cnt[ 0 ] , cnt[ 1 ] );
		printf( "%d\n" , n - 2 * len );
	}
}

