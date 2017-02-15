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
#define INF (1<<29)

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;

int X[ N + 5 ];
int DP[ N + 5 ][ N + 5 ] , A[ N + 5 ][ N + 5 ];

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		vi v( n );
		REP( i , n ) sc( v[ i ] );
		vi LIS1( n , 1 ) , LIS2( n , 1 );
		REP( i , n ){
			REP( j , i ) 
				if( v[ i ] > v[ j ] ) LIS1[ i ] = max( LIS1[ i ] , 1 + LIS1[ j ] );
		}
		
		for( int i = n - 1 ; i >= 0 ; --i ){
			for( int j = n - 1 ; j > i ; --j )
				if( v[ i ] > v[ j ] ) LIS2[ i ] = max( LIS2[ i ] , 1 + LIS2[ j ] );
		}
		
		vi vec( n );
		REP( i , n ) vec[ i ] =  LIS1[ i ] + LIS2[ i ] - 1;
		X[ 0 ] = 0;
		REP( i , n ) X[ i + 1 ] = X[ i ] + vec[ i ];
		
		REP( i , n ) REP( j , i ) DP[ i ][ j ] = INF;
		for( int len = 1 ; len <= n ; len++ ){
			for( int L = 0 ; L + len - 1 < n ; L++ ){
				int R = L + len - 1;
				if( len <= 1 ){
					A[ L ][ R ] = L;
					DP[ L ][ R ] = 0;
					continue;
				}
				int lo = A[ L ][ R - 1 ] , hi = A[ L + 1 ][ R ];
				DP[ L ][ R ] = INF;
				for( int i = lo ; i <= hi ; i++ ){
					ll aux = DP[ L ][ i ] + DP[ i + 1 ][ R ] + (X[ R + 1 ] - X[ L ]);
					if( DP[ L ][ R ] > aux ){
						DP[ L ][ R ] = aux;
						A[ L ][ R ] = i;
					}
				}
			}
		}
		cout << "Case " << tc + 1 << ": " << DP[ 0 ][ n - 1 ] << '\n';
	}
}



