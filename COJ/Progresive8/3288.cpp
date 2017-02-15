#include<bits/stdc++.h>
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

#define DEBUG( x ) cerr << #x << " " << x << endl;

#define MOD 1000007
#define N 1000

typedef long long ll;
typedef pair< ll , ll > pii;
typedef vector< pii > vpii;
typedef vector< vpii > vvpii;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector< ll > vll;
typedef vector< vll > vvll;
typedef vector< vvi > vvvi;

int C[ N + 5 ][ N + 5 ];
int AC[ N + 5 ];
int main(){
	REP( i , N + 1 ) C[ i ][ i ] = C[ i ][ 0 ] = 1;
	for( int i = 2 ; i <= N ; ++i )
		for( int j = 1 ; j < i ; ++j ){
			C[ i ][ j ] = C[ i - 1 ][ j - 1 ] + C[ i - 1 ][ j ];
			if( C[ i ][ j ] >= MOD ) C[ i ][ j ] -= MOD;
		}
	for( int i = 0 ; i <= N ; ++i ){
		int sum = 0;
		for( int j = 0 ; j <= N ; ++j ){
			sum = sum + C[ i ][ j ];
			if( sum >= MOD ) sum -= MOD;
		}
		AC[ i + 1 ] = AC[ i ] + sum;
		if( AC[ i + 1 ] >= MOD ) AC[ i + 1 ] -= MOD;
	}
	int a , b;
	while( sc( a ) == 1 ){
		sc( b );
		if( a == -1 && b == -1 ) break;
		int ans = AC[ b + 1 ] - AC[ a ];
		if( ans < 0 ) ans += MOD;
		printf( "%d\n" , ans );		
	}
}


