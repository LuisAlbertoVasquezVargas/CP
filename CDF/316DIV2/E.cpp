#include <bits/stdc++.h>
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

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 500
#define MOD 1000000007

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash


typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

char S[ N + 5 ][ N + 5 ];
int dx[] = { 0 , 1 };
int dy[] = { 1 , 0 };
//bool used[ N + 5 ][ N + 5 ][ N + 5 ];
//int memo[ N + 5 ][ N + 5 ][ N + 5 ];
int DP[ 2 ][ N + 5 ][ N + 5 ];
int n , m;
bool valid( int a , int b ){ return a >= 0 && a < n && b >= 0 && b < m ; }
/*
int dp( int x1 , int y1 , int x2 , int y2 ){
	if( x1 == n - 1 - x2 && y1 == m - 1 - y2 ) return 1;
	if( x1 == n - 1 - x2 && y1 == m - 1 - y2 - 1 ) 
		return S[ x1 ][ y1 ] == S[ n - 1 - x2 ][ m - 1 - y2 - 1 ];
	if( x1 == n - 1 - x2 - 1 && y1 == m - 1 - y2 ) 
		return S[ x1 ][ y1 ] == S[ n - 1 - x2 - 1 ][ m - 1 - y2 ];
	if( used[ x1 ][ y1 ][ x2 ] ) return memo[ x1 ][ y1 ][ x2 ];
	used[ x1 ][ y1 ][ x2 ] = 1;
	int &dev = memo[ x1 ][ y1 ][ x2 ] = 0;
	REP( k1 , 2 ){
		int nx1 = x1 + dx[ k1 ];
		int ny1 = y1 + dy[ k1 ];
		if( valid( nx1 , ny1 ) ){
			REP( k2 , 2 ){
				int nx2 = x2 + dx[ k2 ];
				int ny2 = y2 + dy[ k2 ];
				if( valid( n - 1 - nx2 , m - 1 - ny2 )
					&& nx1 <= n - 1 - nx2 && ny1 <= m - 1 - ny2
					&& S[ nx1 ][ ny1 ] == S[ n - 1 - nx2 ][ m - 1 - ny2 ] ){
					dev += dp( nx1 , ny1 , nx2 , ny2 );
					if( dev >= MOD ) dev -= MOD;
				}
			}
		}
	}
	return dev;
}
*/
int main(){
	while( sc( n ) == 1 ){
		sc( m );
		REP( i , n ) scanf( "%s" , S[ i ] );
		if( S[ 0 ][ 0 ] != S[ n - 1 ][ m - 1 ] ){
			puts( "0" );
			continue;
		}
		for( int x1 = n - 1 ; x1 >= 0 ; --x1 )
			for( int y1 = m - 1 ; y1 >= 0 ; --y1 )
				for( int x2 = n - 1 ; x2 >= 0 ; --x2 ){
					int y2 = x1 + y1 - x2;
					if( x1 == n - 1 - x2 && y1 == m - 1 - y2 ){
						DP[ x1 & 1 ][ y1 ][ x2 ] = 1;
						continue;
					}
					if( x1 == n - 1 - x2 && y1 == m - 1 - y2 - 1 ){
						DP[ x1 & 1 ][ y1 ][ x2 ] = S[ x1 ][ y1 ] == S[ n - 1 - x2 ][ m - 1 - y2 - 1 ];
						continue;
					}
					if( x1 == n - 1 - x2 - 1 && y1 == m - 1 - y2 ){
						DP[ x1 & 1 ][ y1 ][ x2 ] = S[ x1 ][ y1 ] == S[ n - 1 - x2 - 1 ][ m - 1 - y2 ];
						continue;
					}
					DP[ x1 & 1 ][ y1 ][ x2 ] = 0;
					REP( k1 , 2 ){
						int nx1 = x1 + dx[ k1 ];
						int ny1 = y1 + dy[ k1 ];
						if( valid( nx1 , ny1 ) ){
							REP( k2 , 2 ){
								int nx2 = x2 + dx[ k2 ];
								int ny2 = y2 + dy[ k2 ];
								if( valid( n - 1 - nx2 , m - 1 - ny2 )
									&& nx1 <= n - 1 - nx2 && ny1 <= m - 1 - ny2
									&& S[ nx1 ][ ny1 ] == S[ n - 1 - nx2 ][ m - 1 - ny2 ] ){
									DP[ x1 & 1 ][ y1 ][ x2 ] += DP[ nx1 & 1 ][ ny1 ][ nx2 ];
									if( DP[ x1 & 1 ][ y1 ][ x2 ] >= MOD ) DP[ x1 & 1 ][ y1 ][ x2 ] -= MOD;
								}
							}
						}
					}
				}
		printf( "%d\n" , DP[ 0 ][ 0 ][ 0 ] );
	}
}


