#include<cstdio>
#include<cstring>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define N 200
#define M 400

typedef long long ll;

int nS , nT , nR;
char S[ M + 5 ] , T[ M + 5 ] , R[ M + 5 ];
bool used[ N + 5 ][ N + 5 ];
int memo[ N + 5 ][ N + 5 ];
int dp( int a , int b ){
	int r = a + b;
	if( r == nR ) return 1;
	if( used[ a ][ b ] ) return memo[ a ][ b ];
	used[ a ][ b ] = 1;
	int &dev = memo[ a ][ b ] = 0;
	if( R[ r ] == S[ a ] ) dev |= dp( a + 1 , b );
	if( R[ r ] == T[ b ] ) dev |= dp( a , b + 1 );
	return dev;
}

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		scanf( "%s %s %s" , S , T , R );
		nS = strlen( S );
		nT = strlen( T );
		nR = strlen( R );
		clr( used , 0 );
		printf( "Data set %d: %s\n" , tc + 1 , dp( 0 , 0 ) ? "yes" : "no" );
	}
}

