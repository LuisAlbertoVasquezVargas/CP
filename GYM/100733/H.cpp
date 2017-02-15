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

#define N 26
#define M 1000000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int P[ N + 1 ][ N + 1 ] , F[ N + 1 ][ N + 1 ];
char S[ M + 5 ];
int main(){
	while( sc( P[ 0 ][ 0 ] ) == 1 ){
		REP( i , N ) REP( j , N ){
			if( !i && !j )continue;
			sc( P[ i ][ j ] );
		}
		REP( i , N ) P[ i ][ i ] = 0;
		REP( k , N ) REP( i , N ) REP( j , N ) 
			P[ i ][ j ] = min( P[ i ][ j ] , P[ i ][ k ] + P[ k ][ j ] );
		scanf( "%s" , S );
		int n = strlen( S );
		
		REP( a , N ) REP( b , N ){
			F[ a ][ b ] = INT_MAX;
			REP( c , N ){
				int cost = 0;
				cost += ( (a == c) ? 0 : P[ a ][ c ] );
				cost += ( (b == c) ? 0 : P[ b ][ c ] );
				F[ a ][ b ] = min( F[ a ][ b ] , cost );
			}
		}
		ll ans = 0;
		for( int i = 0 , j = n - 1 ; i <= j ; i++ , j -- ){
			ans += F[ S[ i ] - 'a' ][ S[ j ] - 'a' ];
		}
		cout << ans << '\n';
	}
}


