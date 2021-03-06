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

#define LOGN 20
#define N 200000

typedef long long ll;
typedef vector< int > vi;
typedef vector< vi > vvi;

int calc( vi &v ){
	int ans = 0;
	REP( i , SZ( v ) ){
		if( !v[ i ] ) continue;
		int ind;
		for( int j = i ; j < SZ( v ) ; ++j )
			if( v[ j ] ) ind = j;
			else break;
		ans = max( ans , ind - i + 1 );
		i = ind;
	}
	return ans;
}
int main(){
	int n , m , Q;
	while( sc( n ) == 1 ){
		sc( m ) , sc( Q );
		vvi A( n , vi( m ) );
		REP( i , n ) REP( j , m ) sc( A[ i ][ j ] );
		vi ans( n );
		REP( i , n ) ans[ i ] = calc( A[ i ] );
		REP( i , Q ){
			int x , y;
			sc( x ) , sc( y );
			x -- , y --;
			A[ x ][ y ] ^= 1;
			ans[ x ] = calc( A[ x ] );
			printf( "%d\n" , *max_element( all( ans ) ) );
		}
	}
}


