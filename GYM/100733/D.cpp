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

#define N 1000000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

bool used[ N + 1 ];
int memo[ N + 1 ];
int n;
int A[ N + 1 ]; 
int dp( int pos ){
	if( pos >= n ) return 0;
	if( used[ pos ] ) return memo[ pos ];
	used[ pos ] = 1;
	int &dev = memo[ pos ] = dp( pos + 1 );
	dev = max( dev , A[ pos ] + dp( pos + 3 ) );
	return dev;
}

int main(){
	while( sc( n ) == 1 ){
		REP( i , n ) sc( A[ i ] );
		clr( used , 0 );
		for( int i = n - 1 ; i >= 0 ; --i ) dp( i );
		printf( "%d\n" , dp( 0 ) );
	}
}


