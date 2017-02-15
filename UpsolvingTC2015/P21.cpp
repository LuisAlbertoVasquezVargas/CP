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

#define N 200
#define M 100000
#define MOD 1000000007

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int n , s1 , s2;
int A[ N + 5 ] , AC[ N + 5 ];

int DP[ 2 ][ M + 5 ];
void fix( int &x ){
	if( x >= MOD ) x -= MOD;
}
int main(){
	while( sc( s1 ) == 1 ){
		sc( s2 );
		sc( n );
		REP( i , n ) sc( A[ i ] );
		REP( i , n ) AC[ i + 1 ] = AC[ i ] + A[ i ];
		
		for( int c1 = 0 ; c1 <= s1 ; ++c1 ) DP[ n & 1 ][ c1 ] = 1;
		
		for( int pos = n - 1 ; pos >= 0 ; --pos ){		
			for( int c1 = 0 ; c1 <= s1 ; ++c1 ){
				int c2 = AC[ pos ] - c1;
				DP[ pos & 1 ][ c1 ] = 0;
				if( c1 + A[ pos ] <= s1 ){
					DP[ pos & 1 ][ c1 ] += DP[ (pos + 1)&1 ][ c1 + A[ pos ] ];
					fix( DP[ pos & 1 ][ c1 ] );
				}
				if( c2 + A[ pos ] <= s2 ){
					DP[ pos & 1 ][ c1 ] += DP[ (pos + 1)&1 ][ c1 ];
					fix( DP[ pos & 1 ][ c1 ] );
				}
				if( !(A[ pos ] & 1) && (c1 + (A[pos] >> 1) <= s1) && (c2 + (A[pos] >>1) <= s2) ){
					DP[ pos & 1 ][ c1 ] += DP[ (pos + 1)&1 ][ c1 + (A[pos] >> 1) ];
					fix( DP[ pos & 1 ][ c1 ] );
				}
			}
		}
		printf( "%d\n" , DP[ 0 ][ 0 ] );
		
	}
}



