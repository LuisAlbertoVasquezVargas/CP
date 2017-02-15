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
		vi T( n );
		REP( k , m ) REP( i , n ){
			int x;
			sc( x );
			T[ i ] += x;
		}
		pii p( 0 , 0 );
		REP( i , n )
			p = max( p , mp( T[ i ] , i ) );
		printf( "%d\n" , p.se + 1 );
	}
}


