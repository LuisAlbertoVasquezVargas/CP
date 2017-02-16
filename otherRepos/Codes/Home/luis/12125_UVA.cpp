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

#define INF (1<<30)
#define N 100
#define MAXV 201
#define MAXE 40803

typedef vector< int > vi;

int n , m , s , t , E;

int last[ MAXV + 5 ] , now[ MAXV + 5 ] , dist[ MAXV + 5 ];
int to[ 2*MAXE + 5 ] , cap[ 2*MAXE + 5 ] , next[ 2*MAXE + 5 ];
void add_edge( int u , int v , int uv , int vu = 0 ){
	to[ E ] = v ; cap[ E ] = uv ; next[ E ] = last[ u ]; last[ u ] = E++;
	to[ E ] = u ; cap[ E ] = vu ; next[ E ] = last[ v ]; last[ v ] = E++;
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

double X[ N + 5 ] , Y[ N + 5 ];
int A[ N + 5 ] , B[ N + 5 ];
//bool M[ N + 5 ][ N + 5 ];
int edges;
int getU[ N * N + 5 ] , getV[ N * N + 5 ];
int main()
{
	int cases , pinguins , ni , mi;
	double d , x , y;
	sc( cases );
	while( cases -- ){
		scanf( "%d%lf" , &pinguins , &d );
		int target = 0;
		REP( i , pinguins ){
			scanf( "%lf%lf%d%d" , &x , &y , &ni , &mi );
			X[ i ] = x , Y[ i ] = y;
			A[ i ] = ni , B[ i ] = mi;
			target += ni;
		}
		edges = 0;
		for( int i = 0 ; i < pinguins ; ++i )
			for( int j = i + 1 ; j < pinguins ; ++j ){
				double dx = X[ j ] - X[ i ] , dy = Y[ j ] - Y[ i ];
				if( dx * dx + dy * dy <= d * d ) {
					getU[ edges ] = i , getV[ edges ] = j;
					edges ++;
					getU[ edges ] = j , getV[ edges ] = i;
					edges ++;
				}
			}
		/*REP( i , pinguins ) REP( j , pinguins ){
			bool val = 0;
			double dx = X[ j ] - X[ i ] , dy = Y[ j ] - Y[ i ];
			if( dx * dx + dy * dy <= d * d ) val = 1;
			M[ i ][ j ] = val;
		}*/
		vi v;
		REP( k , pinguins ){
			n = (pinguins<<1) + 1;
			m = n * n + (n<<1);
			s = n - 1;
			t = (k<<1);
			E = 0;
			REP( i , n ) last[ i ] = -1;
			REP( i , pinguins ) add_edge( s , (i<<1) , A[ i ] );
			REP( i , pinguins ) add_edge( (i<<1) , (i<<1) + 1 , B[ i ] );
			/*REP( i , pinguins ) REP( j , pinguins )
				if( i != j && M[ i ][ j ] )add_edge( 2*i + 1 , 2*j , INF , 0 );*/
			REP( e , edges ){
				int i = getU[ e ] , j = getV[ e ];
				add_edge( (i<<1) + 1 , (j<<1) , INF , 0 );
			}
			int mf = maxFlow();
			if( mf == target )
				v.pb( k );
		}
		int nv = v.size();
		if( !nv ) {
			puts( "-1" );
			continue;
		}
		REP( i , nv ) printf( "%d%c" , v[ i ] , i + 1 == nv ? 10 : 32 );
	}
}
