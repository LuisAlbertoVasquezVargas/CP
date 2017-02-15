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
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 100000
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< pii > vpii;

int P[ N + 5 ];
void sieve(){
	clr( P , -1 );
	P[ 1 ] = 0;
	for( int i = 2 ; i * i <= N ; ++i )
		if( P[ i ] == -1 )
			for( int j = i * i ; j <= N ; j += i ) P[ j ] = i;
}
set< int > SET;
void primefact( int n , int &b ){
	b = 0;
	while( 1 ){
		int p = P[ n ];
		if( n == 1 ){
			return;
		}
		if( p == -1 ){
			b ++;
			break;
		}
		int exp = 0 ;
		while( n % p == 0 ) {
			exp ++;
			n /= p;
		}
		b += exp;
	}
}
int AC[ 2 ][ N + 5 ];

int main(){
	sieve();
	for( int i = 1 ; i <= N ; ++i ){
		AC[ 0 ][ i + 1 ] = AC[ 0 ][ i ] + (P[ i ] == -1);
		int cur;
		primefact( i , cur );
		AC[ 1 ][ i + 1 ] = AC[ 1 ][ i ] + cur;
	}
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n , a , b;
		sc( n );
		printf( "%d %d\n" , AC[ 0 ][ n + 1 ] , AC[ 1 ][ n + 1 ] );
	}
}


