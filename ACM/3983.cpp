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

#define N 100000
#define M 100

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

ll const INF = LLONG_MAX/2;
int C , n;
int X[ N + 5 ] , Y[ N + 5 ] , W[ N + 5 ];
ll memo[ M + 5 ][ N + 5 ];
bool used[ M + 5 ][ N + 5 ];
ll dif( int a , int b ){
	return (ll)abs( X[ a ] - X[ b ] ) + abs( Y[ a ] - Y[ b ] );
}
ll dp( int pos , int cap ){
	if( pos >= n + 1 ) return dif( n , 0 );
	if( used[ cap ][ pos ] ) return memo[ cap ][ pos ];
	used[ cap ][ pos ] = 1;
	ll &dev = memo[ cap ][ pos ] = dif( pos - 1 , 0 ) + dif( pos , 0 ) + dp( pos + 1 , C - W[ pos ] );
	if( cap - W[ pos ] >= 0 ) 
		dev = min( dev , dif( pos , pos - 1 ) + dp( pos + 1 , cap - W[ pos ] ) );
	return dev;
}

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		sc( C );
		sc( n );
		REP( i , n ) sc( X[ i + 1 ] ) , sc( Y[ i + 1 ] ) , sc( W[ i + 1 ] );
		
		REP( c , C + 1 ) REP( pos , n + 2 ) used[ c ][ pos ] = 0;
		if( tc ) cout << '\n';
		cout << dp( 1 , C ) << '\n';
	}
}


