#include<bits/stdc++.h>
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

#define N 500

typedef vector< int > vi;
int mod;
int n , m , b;
int a[ N + 5 ];
/*
bool used[ N + 5 ][ N + 5 ][ N + 5 ];
int memo[ N + 5 ][ N + 5 ][ N + 5 ];

int dp( int pos , int plan , int bugs ){
	if( pos == n ){
		if( plan == m && bugs <= b ) return 1;
		return 0;
	}
	if( used[ pos ][ plan ][ bugs ] ) return memo[ pos ][ plan ][ bugs ];
	used[ pos ][ plan ][ bugs ] = 1;
	
	int &dev = memo[ pos ][ plan ][ bugs ] = dp( pos + 1 , plan , bugs );
	if( plan + 1 <= m ) dev += dp( pos , plan + 1 , min( b + 1 , bugs + a[ pos ] ) );
	if( dev >= mod ) dev -= mod;
	return dev;
}
*/
int DP[ 2 ][ N + 5 ][ N + 5 ];
int main(){
	while( sc( n ) == 1 ){
		sc( m ) , sc( b ) , sc( mod );
		REP( i , n ) sc( a[ i ] );
		
		for( int pos = n ; pos >= 0 ; --pos ){
			for( int plan = m ; plan >= 0 ; --plan ){
				for( int bugs = b + 1 ; bugs >= 0 ; --bugs ){
					int &dev = DP[ pos & 1 ][ plan ][ bugs ] = 0;
					if( pos == n ){
						if( plan == m && bugs <= b ) dev = 1;
						else dev = 0;
						continue;
					}
					dev = DP[ (pos + 1) & 1 ][ plan ][ bugs ];
					if( plan + 1 <= m ) dev += DP[ pos & 1 ][ plan + 1 ][ min( b + 1 , bugs + a[ pos ] ) ];
					if( dev >= mod ) dev -= mod;
				}
			}
		}
		
		printf( "%d\n" , DP[ 0 ][ 0 ][ 0 ] );
	}
}
