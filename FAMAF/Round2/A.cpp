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
		vi A( n );
		REP( i , n ) sc( A[ i ] );
		int ans = 0;
		REP( i , n ){
			if( A[ i ] == 1 ) continue;
			if( i && abs( (A[ i ] - 1) - A[ i - 1 ] ) > 1 ) continue;
			if( i + 1 < n && abs( (A[ i ] - 1) - A[ i + 1 ] ) > 1 ) continue;
			ans ++;
		}
		printf( "%d\n", ans );
	}
}



