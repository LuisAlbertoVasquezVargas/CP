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

#define INF (1<<30)

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
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
		//DEBUG2( u , v );
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
int main(){
	int m , na , nb , T ;
	while( sc( m ) == 1 ){
		sc( na ) , sc( nb ) , sc( T );
		vi A( na ) , B( nb );
		REP( i , na ) sc( A[ i ] );
		REP( i , nb ) sc( B[ i ] );
		sort( all( A ) );
		sort( all( B ) );
		bool ok = 0;
		REP( it , 2 ){
			if( it ){
				swap( A , B );
				swap( na , nb );
			}
			int s = 2 * (na + nb) , t = s + 1;
			//REP( i , na ) DEBUG( A[ i ] );
			//REP( i , nb ) DEBUG( B[ i ] );
			flowGraph G( 2 * (na + nb) + 2 , 2 * na * nb + na + nb + 2 * m , s , t );
			REP( i , na ){
				int u = i;
				int inU = (u<<1) , outU = inU + 1;
				G.add( inU , outU , 1 );
			}
			REP( j , nb ){
				int v = na + j;
				int inV = (v<<1) , outV = inV + 1;
				G.add( inV , outV , 1 );
			}
			REP( i , na ) REP( j , nb ){
				if( abs( A[ i ] - B[ j ] ) < T ){
					int u = i , v = na + j;
					int inU = (u<<1) , outU = inU + 1;
					int inV = (v<<1) , outV = inV + 1;
					G.add( outU , inV , 1 );
					G.add( outV , inU , 1 );
				}
			}
			for( int j = 0 ; j < m ; ++j ){
				int v = na + j;
				int inV = (v<<1) , outV = inV + 1;
				G.add( outV , t , 1 );
			}
			REP( k , m ){
				int i = na - 1 - k;
				//DEBUG( i );
				int u = i;
				int inU = (u<<1) , outU = inU + 1;
				G.add( s , inU , 1 );
			}
			int f = G.maxFlow();
			if( f == m ){
				ok = 1;
				break;
			}
		}
		puts( ok ? "S" : "N" );
	}
}


