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

#define N 16
#define cte 100000
#define M 3600

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

const int INF = INT_MAX/2;

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n , target;
		sc( n ) , sc( target );
		vi A( n );
		REP( i , n ) sc( A[ i ] );
		
		int s = 0;
		vi dist( M + 5 , INF );
		queue< int > Q;
		Q.push( s );
		dist[ s ] = 0;
		while( !Q.empty() ){
			int u = Q.front(); Q.pop();
			REP( k , n ){
				int v = u + A[ k ];
				if( v < 0 ) v = 0;
				if( v > M ) v = M;
				if( dist[ v ] == INF ){
					dist[ v ] = dist[ u ] + 1;
					Q.push( v );
				}
			}
		}
		
		pii ans( INT_MAX , INT_MAX );
		for( int k = target ; k <= 3600 ; ++k ){
			if( k == 0 ){
				ans = mp( 0 , 0 );
				break;
			}else{
				if( dist[ k ] == INF ) continue;
				ans = mp( dist[ k ] , k - target );
				break;
			}
		}
		printf( "%d %d\n" , ans.fi , ans.se );
	}
}



