#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define clr( t , val ) memset( t , val , sizeof( t ) )

#define N 3399594

int AC[ N + 5 ];
int P[ N + 5 ];

void sieve(){
	clr( P , -1 );
	for( int i = 2 ; i * i <= N ; ++i )
		if( P[ i ] == -1 ) for( int j = i * i ; j <= N ; j += i ) P[ j ] = i;
}
int fact( int n ){
	int ans = 0;
	while( 1 ){
		if( n == 1 ) return ans;
		if( P[ n ] == -1 ){
			ans++;
			return ans;
		}
		int p = P[ n ];
		while( n % p == 0 ) n /= p , ans++;
	}
}
int main()
{
	sieve();	
	for( int i = 2 ; i <= N ; ++i )
		AC[ i ] = AC[ i - 1 ] + fact( i ) ;
	/*for( int i = 0 ; i <= 10 ; ++i )
		cout << i << " : " << AC[ i ] << endl;*/
	int n , tc = 0;
	while( sc( n ) == 1 ){
		if( n < 0 ) break;
		if( binary_search( AC , AC + N + 1 , n ) ) printf( "Case %d: %d!\n" , ++tc , lower_bound( AC , AC + N + 1 , n ) - AC );
		else printf( "Case %d: Not possible.\n" , ++ tc );
	}
}
