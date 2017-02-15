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
		vi x( n );
		REP( i , n ) sc( x[ i ] );
		int maxi = INT_MIN;
		vi ans( n );
		for( int i = n - 1 ; i >= 0 ; --i ){
			if( maxi >= x[ i ] ){
				ans[ i ] = maxi + 1 - x[ i ];
			}
			maxi = max( maxi , x[ i ] );
		}
		REP( i , n ) printf( "%d%c" , ans[ i ] , (i + 1 == n) ? 10 : 32 );
	}
}


