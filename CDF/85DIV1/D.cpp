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

#define N 5000

typedef long long ll;
typedef long double ld;
typedef pair< int , int > pii;
typedef vector< int > vi;

int DP[ N + 5 ][ N + 5 ];
int DP2[ N + 5 ][ N + 5 ];
int main(){
	int n;
	while( sc( n ) == 1 ){
		vi A( n );
		REP( i , n ) sc( A[ i ] );
		clr( DP , 0 );
		clr( DP2 , 0 );
		REP( x , n ){
			for( int i = n - 1 ; i >= 0 ; --i ){
				DP[ x ][ i ] = DP[ x ][ i + 1 ] + (A[ i ] < x);
				DP2[ x ][ i ] = DP2[ x ][ i + 1 ] + (A[ i ] > x);
			}
		}
		int op = 0;
		REP( i , n ) op += DP[ A[ i ] ][ i ];
		int ans = INT_MAX;
		int cnt = 0;
		for( int i = 0 ; i < n ; ++i ){
			for( int j = i + 1 ; j < n ; ++j ){
				int temp = 0;
				int x = A[ i ] , y = A[ j ];
				temp -= (DP[ x ][ i + 1 ] - DP[ x ][ j ]);
				temp -= (DP2[ y ][ i + 1 ] - DP2[ y ][ j ]);
				temp -= (x > y);
				swap( x , y );
				temp += (DP[ x ][ i + 1 ] - DP[ x ][ j ]);
				temp += (DP2[ y ][ i + 1 ] - DP2[ y ][ j ]);
				temp += (x > y);
				if( temp < ans ){
					ans = temp;
					cnt = 1;
				}else if( temp == ans ){
					cnt ++;
				}
			}
		}
		printf( "%d %d\n" , op + ans , cnt );
	}
}


