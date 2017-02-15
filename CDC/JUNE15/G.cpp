#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
 
#define sc(x) scanf( "%d" , &x )
#define REP(i , n) for( int i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )
 
#define pb push_back
#define all(v) v.begin() , v.end()
#define SZ(v) ((int)(v).size())
 
#define mp make_pair
#define fi first
#define se second

#define N 20
#define MOD 99991

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;

int n , K;
int A[ N + 5 ];
bool used[ N + 5 ][ N + 5 ][ MOD + 5 ];
int memo[ N + 5 ][ N + 5 ][ MOD + 5 ];
int F[ MOD + 5 ];
int pisano = 33330;
int dp( int pos , int cur , int mod ){
	if( pos == n ) return ( (cur == K) ? F[ mod ] : 0);
	if( used[ pos ][ cur ][ mod ] ) return memo[ pos ][ cur ][ mod ];
	used[ pos ][ cur ][ mod ] = 1;
	int &dev = memo[ pos ][ cur ][ mod ] = dp( pos + 1 , cur , mod );
	dev = ( dev + dp( pos + 1 , cur + 1 , (A[ pos ] + mod)%pisano ) );
	if( dev >= MOD ) dev -= MOD;
	return dev;
}

int main(){
	F[ 1 ] = F[ 2 ] = 1;
	for( int i = 3 ; i <= MOD ; ++i ){
		F[ i ] = F[ i - 1 ] + F[ i - 2 ];
		if( F[ i ] >= MOD ) F[ i ] -= MOD;
	}
	sc( n ) , sc( K );
	REP( i , n ) sc( A[ i ] );
	printf( "%d\n" , (int)dp( 0 , 0 , 0 ) );
}


