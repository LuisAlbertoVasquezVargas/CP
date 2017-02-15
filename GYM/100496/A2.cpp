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

#define test() cout << "hola que hace ?" << endl;
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 10000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;

void doit( int n ){
	vi P( n );
	REP( i , n ) P[ i ] = i;
	DEBUG( n );
	do{
		bool ok = 1;
		REP( i , n ) for( int j = i + 1 ; j < n ; ++j ){
			if( (P[ i ] - P[ j ] + n)%n == j - i ) ok = 0;
			if( (P[ j ] - P[ i ] + n)%n == j - i ) ok = 0;
		}
		if( ok ){
			for( auto x : P ) cout << x << " ";
			cout << endl;
			return;
		}
	}while( next_permutation( all( P ) ) );
	test();
}
int P[ N + 5 ];
void sieve(){
	clr( P , -1 );
	P[ 0 ] = P[ 1 ] = 0;
	for( int i = 2 ; i * i <= N ; ++i )
		if( P[ i ] == -1 )
			for( int j = i * i ; j <= N ; j += i ) P[ j ] = i;
}
int main(){
	sieve();
	/*
	freopen("avangard.in", "r", stdin);
	freopen("avangard.out", "w", stdout);
	*/
	int n;
	while( sc( n ) == 1 ){
		DEBUG( n );
		if( n == 1 ){
			puts( "Yes" );
			puts( "1" );
			continue;
		}
		if( n <= 4 ){
			puts( "No" );
			continue;
		}
		if( !(n & 1) ){
			puts( "No" );
			continue;
		}
		if( P[ (n - 1) >> 1 ] != -1 ){
			puts( "No" );
			continue;
		}
		vvi T( n , vi( n ) );
		REP( k , n ){
			for( int i = k , it = 0 ; it < n ; ++it , i = (i + 2)%n )
				T[ it ][ i ] = k + 1;
		}
		
		puts( "Yes" );
		REP( i , n ){
			REP( j , n ) printf( "%d%c" , T[ i ][ j ] , (j + 1 == n) ? 10 : 32 );
		}
	}
}


