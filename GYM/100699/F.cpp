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

#define N 100

typedef long long ll;
typedef long double ld;
typedef pair< int , int > pii;
typedef vector< int > vi;

vi G[ N + 5 ];
int A[ N + 5 ];
int F[ N + 5 ] , C[ N + 5 ];
void dfs( int u ){
	F[ u ] = A[ u ];
	C[ u ] = 1;
	for( auto v : G[ u ] ){
		dfs( v );
		F[ u ] += F[ v ];
		C[ u ] += C[ v ];
	}
}

int main(){
	int n;
	while( sc( n ) == 1 ){
		REP( i , n ){
			int p ;
			sc( p ) , sc( A[ i ] );
			p --;
			if( p >= 0 )
				G[ p ].pb( i );
		}
		dfs( 0 );
		ld maxi = 0;
		REP( i , n ) maxi = max( maxi , (ld)F[ i ] / (ld)C[ i ] );
		printf( "%.3f\n" , (double)maxi );
	}
}



