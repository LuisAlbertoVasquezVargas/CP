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

#define N 1234
#define EPS (1e-8)

typedef long long ll;
typedef vector< int > vi;

double det;
bool invert( double A[ N ][ N ] , double B[ N ][ N ] , int n ){
	det = 1;
	REP( i , n ){
		int jmax = i ;
		for( int j = i + 1 ; j < n ; ++j )
			if( abs( A[ j ][ i ] ) > abs( A[ jmax ][ i ] ) ) jmax = j;
		if( jmax > i ) det = -det;
		REP( j , n )
			swap( A[ i ][ j ] , A[ jmax ][ j ] ) , swap( B[ i ][ j ] , B[ jmax ][ j ] );
		if( abs( A[ i ][ i ] ) < EPS ) {
			det = 0;
			return 0;
		}
		double tmp = A[ i ][ i ];
		det *= tmp;
		REP( j , n ) A[ i ][ j ] /= tmp , B[ i ][ j ] /= tmp;
		REP( j , n ){
			if( i == j )continue;
			tmp = A[ j ][ i ];
			REP( k , n )
				A[ j ][ k ] -= A[ i ][ k ]*tmp , B[ j ][ k ] -= B[ i ][ k ]*tmp;
		}
	}
	return 1;
}
double A[ N ][ N ] , B[ N ][ N ];
int main(){
	int n = 1000;
	
	B[ 0 ][ 0 ] = 1;
	
	REP( i , n ) A[ i ][ i ] = 1;
	for( int i = 1 ; i <= n - 3 ; ++i ){
		A[ i ][ i ] = 2;
		A[ i ][ i - 1 ] = -1;
		A[ i ][ i + 2 ] = -1;
	}
	
	cout << invert( A , B , n ) << endl;
	printf( "%.15f\n" , B[ 1 ][ 0 ] );
}


