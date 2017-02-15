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

#define N 1000000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int main(){
	int n;
	while( sc( n ) == 1 ){
		vi F( N + 5 ) , lo( N + 5 , INT_MAX ) , hi( N + 5 , INT_MIN );
		REP( i , n ){
			int x;
			sc( x );
			F[ x ] ++;
			lo[ x ] = min( lo[ x ] , i );
			hi[ x ] = max( hi[ x ] , i );
		}
		int ind = -1 , best = -1;
		for( int i = 0 ; i <= N ; ++i )
			if( F[ i ] > 0 && F[ i ] > best ){
				best = F[ i ];
				ind = i;
			}else if( F[ i ] > 0 && F[ i ] == best ){
				int curL = hi[ ind ] - lo[ ind ] + 1;
				int cur = hi[ i ] - lo[ i ] + 1;
				if( cur < curL ){
					ind = i;
				}
			}
		printf( "%d %d\n" , lo[ ind ] + 1 , hi[ ind ] + 1 );
	}
}

