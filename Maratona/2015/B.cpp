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

ll INF = (1LL<<60);
int n , C;
ll memo[ 2 ][ N + 1 ];
bool used[ 2 ][ N + 1 ];
int A[ N + 1 ];
ll dp( int flag , int pos ){
	if( pos == n ){
		if(flag == 0) return 0;
		return -INF;
	}
	if( used[ flag ][ pos ] ) return memo[ flag ][ pos ];
	used[ flag ][ pos ] = 1;
	
	ll &dev = memo[ flag ][ pos ] = dp( flag , pos + 1 );
	if( flag == 0 ){
		dev = max( dev , -A[ pos ] + dp( 1 , pos + 1 ) );
	}else{
		dev = max( dev , +A[ pos ] - C + dp( 0 , pos + 1 ) );
	}
	return dev;
}
int main(){
	while( sc( n ) == 1 ){
		sc( C );
		REP( i , n ) sc( A[ i ] );
		//clear
		REP( i , n + 1 ) REP( k , 2 ) used[ k ][ i ] = 0;
		for( int i = n - 1 ; i >= 0 ; --i )
			REP( k , 2 ) dp( k , i );
		printf( "%lld\n" , max( dp( 0 , 0 ) , 0LL ) );
	}
}


