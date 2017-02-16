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

#define N 100

typedef long long ll;
typedef vector< int > vi;

int S[ N + 5 ][ N + 5 ] , T[ N + 5 ][ N + 5 ];
int solve( vi vec ){
	int ans = vec[ 0 ];
	vi dp( SZ( vec ) );
	dp[ 0 ] = vec[ 0 ];
	for( int i = 1 ; i < SZ( vec ) ; ++i ){
		dp[ i ] = max( vec[ i ] , vec[ i ] + dp[ i - 1 ] );
		ans = max( ans , dp[ i ] );
	}
	return ans;
}
int main(){
	int n;
	cin >> n;
	REP( i , n ) REP( j , n ) cin >> S[ i ][ j ];
	REP( i , n ) REP( j , n ) T[ i ][ j + 1 ] = T[ i ][ j ] + S[ i ][ j ];
	int ans = S[ 0 ][ 0 ]; 
	for( int j1 = 0 ; j1 < n ; j1 ++ )
		for( int j2 = j1 ; j2 < n ; j2 ++ ){
			vi vec;
			REP( i , n ) vec.pb( T[ i ][ j2 + 1 ] - T[ i ][ j1 ] );
			ans = max( ans , solve( vec ) );
		}
	cout << ans << '\n';
}


