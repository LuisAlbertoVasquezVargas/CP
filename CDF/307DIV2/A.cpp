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

#define N 100000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;

int main(){
	int n;
	while( sc( n ) == 1 ){
		vi x( n ) , y( n );
		REP( i , n ) sc( x[ i ] );
		REP( i , n ) REP( j , n )
			if( x[ j ] > x[ i ] ) y[ i ] ++;
		REP( i , n ) printf( "%d%c" , y[ i ] + 1 , (i + 1 == n) ? 10 : 32 );
	}
}


