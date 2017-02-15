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

#define test() cerr << "hola q hace" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 1000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef vector< vvpii > vvvpii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;


bool used[ N + 5 ][ N + 5 ];
int memo[ N + 5 ][ N + 5 ];
int C[ N + 5 ];
int n , K;
int dx[] = { 1 , -1 };
int dp( int pos , int cur ){
	if( pos == n ) return 0;
	if( used[ pos ][ cur ] ) return memo[ pos ][ cur ];
	used[ pos ][ cur ] = 1;
	int &dev = memo[ pos ][ cur ] = 0;
	REP( k , 2 ){
		int ncur = cur + dx[ k ] * C[ pos ];
		if( ncur >= 0 && ncur <= K )
			dev = max( dev , 1 + dp( pos + 1 , ncur ) );
	}
	return dev;
}
string cad , S = "+-";
void rec( int pos , int cur ){
	if( pos == n ) return;
	int dev = dp( pos , cur );
	REP( k , 2 ){
		int ncur = cur + dx[ k ] * C[ pos ];
		if( ncur >= 0 && ncur <= K )
			if( dev == 1 + dp( pos + 1 , ncur ) ){
				cad.pb( S[ k ] );
				rec( pos + 1 , ncur );
				return;
			}
	}
}
int main(){
	while( sc( n ) == 1 ){
		sc( K );
		REP( i , n ) sc( C[ i ] );
		clr( used , 0 );
		printf( "%d\n" , dp( 0 , 0 ) );
		cad.clear();
		rec( 0 , 0 );
		printf( "%s\n" , cad.c_str() );
	}		
}


