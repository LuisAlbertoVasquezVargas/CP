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
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		vvi v( 2 , vi( n ) );
		REP( i , 2 )
			REP( j , n ) sc( v[ i ][ j ] );
		
		REP( i , 2 ) sort( all( v[ i ] ) );
		ll ans = 0;
		REP( i , n ) ans += v[ 0 ][ i ] * v[ 1 ][ i ];
		printf( "%lld\n" , ans );
	}
}



