#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define N 100000

typedef long long ll;
int S , n ;
int A[ N + 5 ] ;
bool vis[ N + 5 ];
bool L[ N + 5 ];
void solve(){
	map< int , int > M;
	REP( i , S ) M[ i + 1 ]--;
	vis[ 0 ] = 1;
	REP( i , n ) vis[ i + 1 ] = 0;
	REP( i , S ){
		M[ A[ i ] ]++;
		if( M[ A[ i ] ] == 0 ) M.erase( A[ i ] );
		if( M.empty() ) vis[ i + 1 ] = 1;
	}
	for( int i = S ; i < n ; ++i ){
		M[ A[ i ] ] ++;
		if( M[ A[ i ] ] == 0 ) M.erase( A[ i ] );		
		M[ A[ i - S ] ]--;
		if( M[ A[ i - S ] ] == 0 ) M.erase( A[ i - S ] );
		if( M.empty() ) vis[ i + 1 ] = 1;
	}
	
	int ans = 0;
	set< int >SET , SET2;
	REP( i , n + 1 ) L[ i ] = 0;
	L[ 0 ] = 1;
	for( int i = 1 ; i <= n ; ++i ){
		if( !SET2.count( A[ i - 1 ] ) ) L[ i ] = 1;
		else break;
		SET2.insert( A[ i - 1 ] );
	}
	/*REP( i , n + 1 ) cout << setw( 3 ) << ( i == 0 ? 0 : A[ i -  1 ] ) << " ";
	cout << endl;
	REP( i , n + 1 ) cout << setw( 3 ) << vis[ i ] << " ";
	cout << endl;
	REP( i , n + 1 ) cout << setw( 3 ) << L[ i ] << " ";
	cout << endl; 	  	 */
	REP( i , S ){
		if( SET.size() == min( n , i ) ){
			int k = n - i;
			while( k >= 0 && vis[ k ] ) k -= S;
			if( k <= 0 ) ans ++;
			else if( k < S && L[ k ] ) ans ++;
		}
		if( n - i >= 1 ) SET.insert( A[ n - i - 1 ] );
	}
	printf( "%d\n" , ans );
}
int main(){
	int cases;
	sc( cases );
	while( cases -- ){
		sc( S ) , sc( n );
		REP( i , n ) sc( A[ i ] );
		solve();
	}
}

