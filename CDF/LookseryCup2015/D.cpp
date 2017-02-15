#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define SZ( v ) ((int)(v).size())
#define all( v ) v.begin() , v.end()

#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef vector< int > vi;
typedef vector< vi > vvi;
int main(){
	ios_base :: sync_with_stdio( 0 );
	int n , m;
	while( cin >> n >> m ){
		vector< string > S( n ) , T;
		REP( i , n ) cin >> S[ i ];
		vvi X( n + 1 , vi( m + 1 ) ) , Y( X );
		REP( i , n ) REP( j , m ){
			//X[ i + 1 ][ j + 1 ] = X[ i ][ j + 1 ] + X[ i + 1 ][ j ] - X[ i ][ j ];
			if( S[ i ][ j ] == 'W' ) X[ i + 1 ][ j + 1 ] += +1;
			else X[ i + 1 ][ j + 1 ] += -1;
		}
	
		int ans = 0;
		for( int i = n ; i >= 1 ; i -- )
			for( int j = m ; j >= 1 ; --j ){
				/*
				int sum = 0;
				REP( a , i )REP( b , j ) sum += Y[ a + 1 ][ b + 1 ];
				*/
				if( Y[ i ][ j ] == X[ i ][ j ] ) continue;
				ans ++;
				int cur = X[ i ][ j ] - Y[ i ][ j ];
				REP( a , i )REP( b , j ) Y[ a + 1 ][ b + 1 ] += cur;
			}
		cout << ans << '\n';
	}
}


