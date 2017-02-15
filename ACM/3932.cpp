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

#define N 300

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< string > vs;

int n;
int v[ N + 5 ];
int solve( int K ){
	int ans = (1 << 20);
	for( int i = 0 , j = -1 , sum = 0 ; i < n ; ++i ){
		while( j + 1 < n && sum < K ){
			sum += v[ j + 1 ];
			j ++;
		}
		if( sum >= K ) ans = min( ans , j - i + 1 );
		sum -= v[ i ];
	}
	return ans;
}
char S[ N + 5 ][ N + 5 ];
int AC[ N + 5 ][ N + 5 ];
int main(){
	int m , K;
	while( sc( n ) == 1 ){
		sc( m ) , sc( K );
		if( !n && !m && !K ) break;
		REP( i , n ) scanf( "%s" , S[ i ] );
		REP( i , n ) REP( j , m ) 
			AC[ i ][ j + 1 ] = AC[ i ][ j ] + (S[ i ][ j ] == '.');
		
		int ans = INT_MAX;
		for( int j1 = 0 ; j1 < m ; ++j1 )
			for( int j2 = j1 ; j2 < m ; ++j2 ){
				REP( i , n ) v[ i ] = AC[ i ][ j2 + 1 ] - AC[ i ][ j1 ];
				ans = min( ans , solve( K ) * (j2 - j1 + 1) );
			}
		printf( "%d\n" , ans );
	}
}



