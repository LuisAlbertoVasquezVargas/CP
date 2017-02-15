#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef vector< int > vi;
typedef pair< int , int > pii;

#define MAXV 1000000
#define MAXE 1000000
#define INF (1<<20)

typedef long long ll;

int T[ 400 ][ 400 ];

int n , s , t , E;
int to[ 2 *MAXE + 5 ] , cap[ 2*MAXE + 5 ] , NEXT[ 2 * MAXE + 5 ] , from[ 2 * MAXE + 5 ];
int last[ MAXV + 5 ] , now[ MAXV + 5 ] , dist[ MAXV + 5 ];
void add_edge( int u , int v , int uv , int vu = 0 ){
	from[ E ] = u ;to[ E ] = v ; cap[ E ] = uv ; NEXT[ E ] = last[ u ] ; last[ u ] = E ++;
	from[ E ] = v ;to[ E ] = u ; cap[ E ] = vu ; NEXT[ E ] = last[ v ] ; last[ v ] = E ++;
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
int nodes;
int dfs( int u , int f ){
	if( u == t ) return f;
	for( int &e = now[ u ] ; e != -1 ; e = NEXT[ e ] ){
		int v = to[ e ];
		if( cap[ e ] && dist[ u ] == dist[ v ] + 1 ){
			int ret = dfs( v  , min( f , cap[ e ] ) );
			if( ret ){
				if( !(u == s || u == t || v == s || v == t) ){
					if( u < nodes ){
						T[ u ][ v - nodes ] += ret;
						T[ v - nodes ][ u ] -= ret;
					}else{
						T[ u - nodes ][ v ] += ret;
						T[ v ][ u - nodes ] -= ret;
					}
				}
				cap[ e ] -= ret;
				cap[ e ^ 1 ] += ret;
				return ret;
			}
		}
	}
	return 0;
}
int maxFlow(){
	int flow = 0;
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

void clear(){
	E = 0;
	REP( i , n ) last[ i ] = -1;
}

int main(){
	int edges;
	while( sc( nodes ) == 1 ){
		sc( edges );
		n = 2 * nodes + 2 , s = n - 1 , t = n - 2;
		clear();
		int A = 0 , B = 0;
		clr( T , 0 );
		vi P , Q;
		REP( i , nodes ){
			int x;
			sc( x );
			A += x;
			P.pb( x );
		}
		REP( i , nodes ){
			int x;
			sc( x );
			B += x;
			Q.pb( x );
		}

		REP( i , edges ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			add_edge( u , nodes + v , INF );
			add_edge( v , nodes + u , INF );
		}
		int e = E;
		REP( i , nodes ) add_edge( i , nodes + i , INF );
		REP( i , nodes ) add_edge( s , i , P[ i ] );
		REP( i , nodes ) add_edge( nodes + i , t , Q[ i ] );
		
		int f = maxFlow();
		if( A == B && f == A ){
			puts( "YES" );
			
			REP( i , nodes ) REP( j , nodes ) T[ i ][ j ] = max( 0 , T[ i ][ j ] );
			
			REP( i , nodes ){
				T[ i ][ i ] = 0;
				int S = 0;
				REP( j , nodes ) S += T[ i ][ j ];
				T[ i ][ i ] = P[ i ] - S;
			}
			
			REP( i , nodes ) REP( j , nodes ) printf( "%d%c" , T[ i ][ j ] , (j + 1 == nodes) ? 10 : 32 );
			
			continue;
		}
		puts( "NO" );
	}
}


