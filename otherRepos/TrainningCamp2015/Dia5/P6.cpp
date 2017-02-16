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

#define N 500
#define INF (1<<29)

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int A[ N + 1 ][ N + 1 ];
bool used[ N + 1 ][ N + 1 ];
int memo[ N + 1 ][ N + 1 ];
int n , m;
int dp( int a , int b ){
	if( a == n - 1 && b == m - 1 ) return max( 1 , -A[ a ][ b ] );
	if( used[ a ][ b ] ) return memo[ a ][ b ];
	used[ a ][ b ] = 1;
	int &dev = memo[ a ][ b ] = INF;
	if( a + 1 < n ) dev = min( dev , max( 1 , -A[ a ][ b ] + dp( a + 1 , b ) ) );
	if( b + 1 < m ) dev = min( dev , max( 1 , -A[ a ][ b ] + dp( a , b + 1 ) ) );
	return dev;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		sc( n ) , sc( m );
		REP( i , n ) REP( j , m ) sc( A[ i ][ j ] );
		clr( used , 0 );
		printf( "%d\n" , dp( 0 , 0 ) );
	}
}




