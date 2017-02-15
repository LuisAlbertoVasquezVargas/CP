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

#define test puts("************test************");
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 1200

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef long double ld;

int n;
int X[ N + 5 ] , Y[ N + 5 ];
ld d[ N + 5 ][ N + 5 ];
vi G[ N + 5 ];
int color[ N + 5 ];
void add( int u , int v ){
	G[ u ].pb( v );
}
bool f( ld dist ){
	REP( i , n ) G[ i ].clear();
	clr( color , -1 );
	for( int i = 0 ; i < n ; ++i )
		for( int j = i + 1 ; j < n ; ++ j ){
			if( d[ i ][ j ] <= dist ){
				add( i , j );
				add( j , i );
			}
		}
	queue< int > Q;
	REP( s , n ){
		if( color[ s ] != -1 ) continue;
		Q.push( s );
		color[ s ] = 0;
		while( !Q.empty() ){
			int u = Q.front();
			Q.pop();
			for( auto v : G[ u ] ){
				if( color[ v ] == -1 ){
					color[ v ] = color[ u ] ^ 1;
					Q.push( v );
				}else if( color[ v ] == color[ u ] ) return 0;
			}
		}
	}
	return 1;
}
int main(){	

	freopen( "radio.in" , "r" , stdin );
	freopen( "radio.out" , "w" , stdout );

	while( sc( n ) == 1 ){
		REP( i , n ) sc( X[ i ] ) , sc( Y[ i ] );
		REP( i , n ) REP( j , n ) d[ i ][ j ] = 0.5 * hypot( X[ i ] - X[ j ] , Y[ i ] - Y[ j ] );
		ld lo = 0 , hi = 1e5;
		REP( it , 50 ){
			ld med = (lo + hi)/2.0;
			if( f( med ) ) lo = med;
			else hi = med;
		}
		f( lo );
		printf( "%.15f\n" , (double) lo );
		REP( i , n ) printf( "%d%c" , color[ i ] + 1 , (i + 1 == n) ? 10 : 32 );
	}
}


