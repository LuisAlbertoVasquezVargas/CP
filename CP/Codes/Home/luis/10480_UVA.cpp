#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define MAXV 50
#define MAXE 500
#define INF (1<<30)

typedef long long ll;

int n , m , s , t , E;
int last[ MAXV + 5 ] , now[ MAXV + 5 ] , dist[ MAXV + 5 ];
int to[ 2*MAXE + 5 ] , cap[ 2*MAXE + 5 ] , next[ 2*MAXE + 5 ];
void add_edge( int u , int v , int uv , int vu = 0 ){
	to[ E ] = v ; cap[ E ] = uv ; next[ E ] = last[ u ]; last[ u ] = E ++;
	to[ E ] = u ; cap[ E ] = vu ; next[ E ] = last[ v ]; last[ v ] = E ++;
}
bool bfs(){
	REP( i , n ) dist[ i ] = INF;
	queue< int > Q;
	dist[ t ] = 0;
	Q.push( t );
	while( !Q.empty() ){
		int u = Q.front() ; Q.pop();
		for( int e = last[ u ] ; e != -1 ; e = next[ e ] ){
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
	for( int &e = now[ u ] ; e != -1 ; e = next[ e ] ){
		int v = to[ e ];
		if( cap[ e ] && dist[ u ] == dist[ v ] + 1 ){
			int ret = dfs( v , min( f , cap[ e ] ) );
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
int vis[ MAXV + 5 ];
void dfs( int u ){
	vis[ u ] = 1;
	for( int e = last[ u ] ; e != -1 ; e = next[ e ] ){
		int v = to[ e ];
		if( cap[ e ] && !vis[ v ] ) dfs( v );
	}
}
int main(){
	int u , v , w;
	while( sc( n ) == 1 ){
		sc( m );
		if( n == 0 && m == 0 ) break;
		s = 0 , t = 1;
		E = 0 ;
		REP( i , n ) last[ i ] = -1;
		REP( i , m ){
			sc( u ) , sc( v ) , sc( w );
			u -- , v--;
			add_edge( u , v , w , w );
		}
		maxFlow();
		REP( i , n ) vis[ i ] = 0;
		dfs( s );
		for( int e = 0 ; e < E ; e ++ ){
			v = to[ e ] , u = to[ e ^ 1 ];
			if( u < v && vis[ u ] ^ vis[ v ] ) printf( "%d %d\n" , u + 1 , v + 1 );
		}
		puts( "" );
	}
}


