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
#define DEBUG3( x , y , z ) cerr << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef long double ld;
typedef vector< ld > vld;

int main(){
	int n;
	while( sc( n ) == 1 ){
		vi v( n );
		REP( i , n ) sc( v[ i ] );
		sort( all( v ) );
		map< int , int > mapa;
		int maxi = 0 , F;
		REP( i , n - 1 ){
			mapa[ v[ i + 1 ] - v[ i ] ] ++;
			maxi = max( maxi , mapa[ v[ i + 1 ] - v[ i ] ] );
		}
		REP( i , n - 1 ){
			if( maxi == mapa[ v[ i + 1 ] - v[ i ] ] ){
				F = v[ i + 1 ] - v[ i ];
			}
		}	
		for( int i = 0 ; i < n ; ++i ){
			int cur = v[ 0 ] + i * F;
			if( binary_search( all( v ) , cur ) ) continue;
			printf( "%d\n" , cur );
			break;
		}
	}
}
