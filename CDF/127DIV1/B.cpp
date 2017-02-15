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

#define N 1000

typedef long long ll;
typedef vector< ll > vll;
typedef long double ld;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;

int C[ N + 1 ][ N + 1 ];
ll SQ( ll x ){ return x * x ;}
int main(){
	int n , m;
	while( sc( n ) == 1 ){
		sc( m );
		
		REP( i , n ) REP( j , m ) sc( C[ i ][ j ] );
		ld x = 0 , y = 0 , S = 0;
		REP( i , n )REP( j , m ){
			x += (ld)(4 * i + 2) * C[ i ][ j ];
			y += (ld)(4 * j + 2) * C[ i ][ j ];
			S += (ld)C[ i ][ j ];
		}
		if( S != 0 ) x /= (4.0 * S) , y /= (4.0 * S);
		int X = round( x ) , Y = round( y );
		vll best( 3 , LLONG_MAX );
		for( int i = max( 0 , X - 2 ) ; i <= min( n , X + 2 ) ; ++i ){
			for( int j = max( 0 , Y - 2 ) ; j <= min( m , Y + 2 ) ; ++j ){
				ll cur = 0;
				REP( a , n ) REP( b , m )
					cur += (ll) C[ a ][ b ] * ( SQ( 4LL * i - (4LL * a + 2LL) ) + SQ( 4LL * j - (4LL * b + 2) ) );
				vll temp = { cur , i , j };
				best = min( best , temp );
			}
		}
		cout << best[ 0 ] << '\n';
		cout << best[ 1 ] << " " << best[ 2 ] << '\n';
	}
}




