#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 80
#define B 27LL
#define MOD1 1000000007LL
#define MOD2 1000000009LL
#define INF (1<<28)
#define EPS (1e-5)

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef pair< ll , ll > pll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< ll > vll;
typedef vector< ull > vull;

int hash1[ N + 5 ][ N + 5 ] , hash2[ N + 5 ][ N + 5 ];
bool used[ N + 5 ][ N + 5 ];
int memo[ N + 5 ][ N + 5 ];
int dp( int i , int j ){
	if( j < i ) return 0;
	if( i == j ) return 1;
	if( used[ i ][ j ] ) return memo[ i ][ j ];
	used[ i ][ j ] = 1;
	int &dev = memo[ i ][ j ] = INF;
	int n = j - i + 1;
	for( int k = i ; k < j ; ++k ){
		int m = k - i + 1;
		for( int d = 1 ; d * m <= n ; ++d ){
			if( hash1[ i ][ k ] == hash1[ i + (d-1)*m ][ i + d*m - 1 ] &&
			 	hash2[ i ][ k ] == hash2[ i + (d-1)*m ][ i + d*m - 1 ] )
				dev = min( dev , dp( i , k ) + dp( i + d*m , j ) );
			else break;
		}
	}
	return dev;
}
int main(){
	sync;
	string s;
	while( getline( cin , s ) ){
		if( s[ 0 ] == '*' ) break;
		int n = s.size();
		REP( i , n ) s[ i ] = s[ i ] - 'A' + 1;
		for( int i = 0 ; i < n ; ++i ){
			ll H1 = 0 , H2 = 0;
			for( int j = i ; j < n ; ++j ){
				H1 = ( H1 * B + s[ j ] )%MOD1;
				H2 = ( H2 * B + s[ j ] )%MOD2;
				hash1[ i ][ j ] = H1;
				hash2[ i ][ j ] = H2;
			}
		}
		REP( i , n ) REP( j , n ) used[ i ][ j ] = 0;
		printf( "%d\n" , dp( 0 , n - 1 ) );
	}
}


