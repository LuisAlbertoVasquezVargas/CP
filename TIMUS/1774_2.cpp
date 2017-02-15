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
typedef vector< vi > vvi;

const int INF = INT_MAX/2;

struct flowGraph{
	int n , m , s , t , E;
	vi to , cap , NEXT;//maxe * 2
	vi last , now , dist;// maxv
	flowGraph(){}
	flowGraph( int n , int m , int s , int t ) : n( n ) , m( m ) , s( s ) , t( t ) {
		to = cap = NEXT = vi( 2 * m + 5 );
		last = now = dist = vi( n + 5 );
		E = 0;
		last = vi( n + 5 , -1 );
	}
	void add( int u , int v , int uv , int vu = 0 ){
		to[ E ] = v ; cap[ E ] = uv ; NEXT[ E ] = last[ u ] ; last[ u ] = E ++;
		to[ E ] = u ; cap[ E ] = vu ; NEXT[ E ] = last[ v ] ; last[ v ] = E ++;
	}
	bool bfs(){
		REP( i , n ) dist[ i ] = INF;
		queue< int > Q;
		dist[ t ] = 0;
		Q.push( t );
		while( !Q.empty() ){
			int u = Q.front() ; Q.pop();
			for( int e = last[ u ] ; e != -1 ; e = NEXT[ e ] ){
				int v = to[ e ];
				if( cap[ e ^ 1 ] && dist[ v ] >= INF ){
					dist[ v ] = dist[ u ] + 1;
					Q.push( v );
				}
			}
		}
		return dist[ s ] < INF;
	}
	int dfs( int u , int f ){
		if( u == t ) return f;
		for( int &e = now[ u ] ; e != -1 ; e = NEXT[ e ] ){
			int v = to[ e ];
			if( cap[ e ] && dist[ u ] == dist[ v ] + 1 ){
				int ret = dfs( v  , min( f , cap[ e ] ) );
				if( ret ){
					cap[ e ] -= ret;
					cap[ e ^ 1 ] += ret;
					return ret;
				}
			}
		}
		return 0;
	}
	ll maxFlow(){
		ll flow = 0;
		while( bfs() ){
		
			REP( i , n ) now[ i ] = last[ i ];
			while( 1 ){
				int f = dfs( s , INF );
				if( !f ) break;
				flow += f;
			}
		}
		return flow;
	}
};

const int N = 2006;
int main(){
	int n , K;
	while( sc( n ) == 1 ){
		sc( K );
		vi A , B;
		REP( i , n ){
			int x , y;
			sc( x ) , sc( y );
			A.pb( x ) , B.pb( x + y - 1 );
		}
		int nodes = N + n + 2 , s = nodes - 1 , t = s - 1;
		int edges = 2006*100 + N + n;
		flowGraph G( nodes , edges , s , t  );
		REP( timer , N ){
			REP( i , n ){
				if( A[ i ] <= timer && timer <= B[ i ] ){
					G.add( timer , N + i , 1 );
				}
			}
		}
		REP( timer , N )
			G.add( s , timer , K );
		REP( i , n )
			G.add( N + i , t , 2 );
		int f = G.maxFlow();
		if( f != 2 * n ){
			puts( "No" );
			continue;
		}
		puts( "Yes" );
		int cur = 0;
		vvi T( n );
		REP( timer , N ){
			REP( i , n ){
				if( A[ i ] <= timer && timer <= B[ i ] ){
					if( G.cap[ cur ] == 0 ){
						T[ i ].pb( timer );
						//DEBUG2( i , timer );
					}
					cur += 2;
				}
			}
		}
		REP( i , SZ( T ) ) printf( "%d %d\n" , T[ i ][ 0 ] , T[ i ][ 1 ] );
	}
}



