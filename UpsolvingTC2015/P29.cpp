#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define N 2000
#define M 20
#define INF (100000000)

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef vector< int > vi;

bool used[ N + 5 ][ M + 5 ];
int memo[ N + 5 ][ M + 5 ];
int n;
int A[ N + 5 ] , AC[ N + 5 ];
int get( int x ){
	if( x % 10 == 0 ) return x;
	if( x % 5 == 0 ) return x + 5;
	if( x % 10 < 5 ) return (x/10)*10;
	return (x/10)*10 + 10;
}
int dp( int pos , int d ){
	if( pos == n ) return 0;
	if( used[ pos ][ d ] ) return memo[ pos ][ d ];
	used[ pos ][ d ] = 1;
	int &dev = memo[ pos ][ d ] = INF;
	if( d - 1 >= 0 ){
		for( int i = pos ; i < n ; ++i )
			dev = min( dev , get( AC[i + 1] - AC[pos] ) + dp( i + 1 , d - 1 ) );
	}
	return dev;
}

int main(){
	while( sc( n ) == 1 ){
		int d;
		sc( d );
		REP( i , n ) sc( A[ i ] );
		REP( i , n ) AC[ i + 1 ] = AC[ i ] + A[ i ];
		clr( used , 0 );
		printf( "%d\n" , dp( 0 , d + 1 ) );
	}
}

