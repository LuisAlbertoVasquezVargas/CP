#include<bits/stdc++.h>
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

#define N 100000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int main(){
	int n , m , K;
	while( sc( n ) == 1 ){
		sc( m ) , sc( K );
		vi A( m + 1 );
		REP( i , m + 1 )
			sc( A[ i ] );
		int cnt = 0;
		REP( i , m ){
			int cur = A[ i ] xor A[ m ];
			if( __builtin_popcount( cur ) <= K ) cnt ++;
		}
		printf( "%d\n" , cnt );
	}

}
