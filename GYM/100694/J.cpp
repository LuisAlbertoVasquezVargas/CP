#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define INF (1<<20)
#define N 200000

#define DEBUG( x ) cerr << #x << " " << (x) << endl;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef long long ll;

void add( vvi &a , vvi &b ){
	for( auto x : b ) a.pb( x );
}
void impr( vi &v ){
	printf( "%d" , SZ( v ) );
	for( auto x : v ) printf( " %d" , x + 1 );
	puts( "" );
}
int main(){
	int n , m , K;
	while( sc( n ) == 1 ){
		sc( m ) , sc( K );
		vi x( n ) , y( m );
		REP( i , n ) sc( x[ i ] );
		REP( i , m ) sc( y[ i ] );
		vvi ans;
		for( int i = 0 , j = 0 ; i < n ; ++i ){
			while( 1 ){
				if( j == m ) break;
				if( y[ j ] < x[ i ] ) j++;
				else break;
			}
			if( j == m ) break;
			
			int ind = i;
			for( int k = 0 ; (i + k < n) && (j + k < m) ; ++k )
				if( x[ i + k ] == y[ j + k ] ) ind = i + k;
				else break;
			int L = ind - i + 1;
			vvi temp( (L - 1) / K + 1 );
			REP( k , L )
				temp[ k / K ].pb( i + k );
			add( ans , temp );
			i = ind;
		}
		printf( "%d\n" , SZ( ans ) );
		for( auto vec : ans ) impr( vec );
	}
}


