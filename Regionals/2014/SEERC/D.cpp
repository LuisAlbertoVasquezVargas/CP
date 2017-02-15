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
 
typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

bool solve2( int x , int y , int n ){
	if( n == 1 ) return 1;
	if( x % n == 0 && (y - 1) % n == 0 && (x - 1) % n == 0 && (y - 2) % n == 0 ) return 1;
	if( x % n == 0 && (y - 1) % n == 0 && (x - 2) % n == 0 ) return 1;
	if( x % n == 0 && (y - 2) % n == 0 ) return 1;
	if( (x - 1) % n == 0 && (y) % n == 0 && (y - 2) % n == 0 ) return 1;
	if( (x - 1) % n == 0 && (y) % n == 0 && (x - 2) % n == 0 && (y - 1) % n == 0 ) return 1;
	if( (x - 1) % n == 0 && (y - 1) % n == 0 ) return 1;
	return 0;
}
bool solve( int X , int Y , int n ){
	return solve2( X , Y , n ) || solve2( Y , X , n );	
}

int main(){
	int X , Y;
	while( sc( X ) == 1 ){
		sc( Y );
		int Q;
		sc( Q );
		REP( it , Q ){
			int n;
			sc( n );
			puts( solve( X , Y , n ) ? "YES" : "NO" );
		}
	}
}



