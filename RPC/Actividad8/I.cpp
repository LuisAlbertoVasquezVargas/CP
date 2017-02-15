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
typedef vector< vi > vvi;

int main(){
	int K , S , X , Y;
	while( sc( K ) == 1 ){
		sc( S );
		sc( X ) , sc( Y );
		vvi T( K , vi( X ) );
		REP( i , K ) REP( j , X ) sc( T[ i ][ j ] );
		vi V( X );
		REP( i , S ) REP( j , X ){
			int x;
			sc( x );
			V[ j ] = max( V[ j ] , x );
		}
		REP( i , K ) {
			REP( j , X ) T[ i ][ j ] = min( T[ i ][ j ] , Y - V[ j ] );
			REP( j , X ) printf( "%d%c" , T[ i ][ j ] , (j + 1 == X ? 10 : 32) );
		}
	}
}

