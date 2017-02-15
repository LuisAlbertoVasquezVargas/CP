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

#define N 1000
#define M 1000000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;

#define VIZ(e,x) (orig[e] == x? dest[e] : orig[e])
int n,m,fin;
int orig[M + 1], dest[M + 1], peso[M + 1] ,pila[M + 1], top = 0;
vi E[N + 1];
int low[N + 1], dfsn[N + 1], timer;
int ponte[M + 1], bicomp[M + 1] , nbicomp;

void dfsbcc (int u, int p = -1){
	low[u] = dfsn[u] = ++timer;
	for( auto e : E[ u ] ){
		int v = VIZ (e, u);
		if (dfsn[v] == 0){
			pila[top++] = e;
			dfsbcc (v, u);
			low[u] = min (low[u], low[v]);
			if (low[v] >= dfsn[u]){
				do{
					fin = pila[--top];
					bicomp[fin] = nbicomp;
				}while (fin != e);
				nbicomp++;
			}
			if (low[v] == dfsn[v]) ponte[e] = 1;
		}else if (v!=p && dfsn[v] < dfsn[u]){
			pila[top++] = e;
			low[u] = min (low[u], dfsn[v]);
		}
	}
}
void bcc (){
	REP( i , n ) dfsn[ i ] = 0;
	REP( i , m ) ponte[ i ] = 0;
	nbicomp = timer = 0;
	REP( i , n ) if (dfsn[ i ] == 0) dfsbcc( i );
}
int forb[ N + 5 ][ N + 5 ];
void UNIQUE( vi &v ){
	sort( all( v ) );
	v.resize( unique( all( v ) ) - v.begin() );
}
void impr( vi &v ){
	for( auto x : v ) cout << x << " ";
	cout << endl;
}
int main(){
	int S;
	while( sc( n ) == 1 ){
		sc( S );
		if( !n && !S ) break;
		clr( forb , 0 );
		REP( i , S ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			if( u > v ) swap( u , v );
			forb[ u ][ v ] = 1;
		}
		m = 0;
		for( int u = 0 ; u < n ; ++u )
			for( int v = u + 1 ; v < n ; ++v ){
				if( forb[ u ][ v ] ) continue;
				orig[ m ] = u;
				dest[ m ] = v;
				E[ u ].pb ( m );
				E[ v ].pb ( m );
				m ++;
			}
		bcc();
		vvi edges( nbicomp );
		REP( i , m ){
			if( ponte[ i ] ) continue;
			//DEBUG2( bicomp[ i ] , nbicomp );
			edges[ bicomp[ i ] ].pb( i );
		}
		vvi G( n );
		vi used( n ) , col( n , - 1 );
		REP( k , nbicomp ){
			if( !SZ( edges[ k ] ) ) continue;
			vi nodes;
			for( auto id : edges[ k ] ) {
				int u = orig[ id ] , v = dest[ id ];
				nodes.pb( u ) , nodes.pb( v );
				G[ u ].pb( v );
				G[ v ].pb( u );
			}
			UNIQUE( nodes );
			//impr( nodes );
			
			bool bipartite = 1;
			queue< int > Q;
			for( auto s : nodes ){
				if( col[ s ] != -1 ) continue;
				Q.push( s );
				col[ s ] = 0;
			
				while( !Q.empty() ){
					int u = Q.front(); Q.pop();
					for( auto v : G[ u ] ){
						if( col[ v ] == -1 ){
							col[ v ] = col[ u ] ^ 1;
							Q.push( v );
						}else{
							if( col[ v ] == col[ u ] ) bipartite = 0;
						}
					}
				}
			}
			
			if( !bipartite ) {
				for( auto u : nodes ) 
					used[ u ] = 1;
			}
			for( auto u : nodes ) col[ u ] = -1;
			
			for( auto id : edges[ k ] ) {
				int u = orig[ id ] , v = dest[ id ];
				G[ u ].pop_back();
				G[ v ].pop_back();
			}
		}
		printf( "%d\n" , (int)count( all( used ) , 0 ) );
	}
	//f(i,0,m) cout << ponte[i]; cout << endl;
	//f(i,0,m) cout << bicomp[i]; cout << endl;
}



