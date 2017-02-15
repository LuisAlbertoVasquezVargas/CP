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

int main(){
	int n;
	while( sc( n ) == 1 ){
		vi v( n ) , w( n );
		REP( i , n ) sc( v[ i ] );
		REP( i , n ) w[ i ] = i;
		int t = (n - v[ 0 ])%n;
		REP( i , n ) 
			if( i & 1 ) v[ i ] = (v[ i ] - t + n)%n;
			else v[ i ] = (v[ i ] + t)%n;
		puts( v == w ? "Yes" : "No" );
	}
}


