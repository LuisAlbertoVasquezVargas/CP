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

#define N 1000
#define INF (1LL<<60)

typedef vector< int > vi;
typedef long long ll;

ll memo[ N + 5 ][ N + 5 ];
bool used[ N + 5 ][ N + 5 ];
int A[ N + 5 ][ N + 5 ];
int n;
bool valid( int x ){ return x >= 0 && x < n;}
ll dp( int i , int j ){
	if( !valid( i ) ) return INF;
	if( !valid( j ) ) return INF;
	if( !i && !j ) return A[ i ][ j ];
	if( used[ i ][ j ] ) return memo[ i ][ j ];
	used[ i ][ j ] = 1;
	ll &dev = memo[ i ][ j ] = INF;
	dev = min( dev , A[ i ][ j ] + dp( i , j - 1 ) );
	dev = min( dev , A[ i ][ j ] + dp( i - 1 , j ) );
	return dev;
}
int main(){	
	while( sc( n ) == 1 ){
		REP( i , n ) REP( j , n ) sc( A[ i ][ j ] );
		clr( used , 0 );
		printf( "%lld\n" , dp( n - 1 , n - 1 ) );
	}
}


