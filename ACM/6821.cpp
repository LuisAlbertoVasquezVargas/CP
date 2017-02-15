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
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef vector< vi > vvi;

int T[ 2 ][ 5 ];

int main(){	
	while( sc( T[ 0 ][ 0 ] ) == 1 ){
		REP( i , 2 ){
			REP( j , 5 ){
				if( !(i == 0 && j == 0) ) sc( T[ i ][ j ] );
			}
		}
		int mask = (1 << 5) - 1;
		REP( i , 5 ) 
			if( T[ 0 ][ i ] ^ T[ 1 ][ i ] ) mask ^= (1 << i);
		puts( !mask ? "Y" : "N" );
	}
}


