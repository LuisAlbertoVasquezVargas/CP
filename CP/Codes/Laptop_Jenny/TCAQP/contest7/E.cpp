#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define N 100000

typedef vector< int > vi;

int b[ N + 5 ];
int LIS( vi &a ){
    int sz = 0;
    int n = a.size();
    REP( i , n ){
        int j = lower_bound( b , b + sz , a[ i ] ) - b;
        b[ j ] = a[ i ];
        if( j == sz ) sz++;
    }
    return sz;
} 

int main(){
	int n;
	while( sc( n ) == 1 ){
		vi a( n );
		REP( i , n ) sc( a[ i ] );
		printf( "%d\n" , LIS( a ) );
	}
}
