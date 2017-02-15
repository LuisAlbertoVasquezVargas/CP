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

#define N 100000
#define M 100000
typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef vector< vi > vvi;

const int INF = INT_MAX/2;

#define VIZ(e,x) (orig[e] == x? dest[e] : orig[e])
int n,m,fin;
int orig[M + 1], dest[M + 1], peso[M + 1],pila[M + 1], top = 0;
vi E[N + 1];
int low[N + 1], dfsn[N + 1], part[N + 1], timer;
int ponte[M + 1], bicomp[M + 1] , nbicomp;

int dfsbcc (int u, int p = -1){
	low[u] = dfsn[u] = ++timer;
	int ch = 0;
	for( auto e : E[ u ] ){
		int v = VIZ (e, u);
		if (dfsn[v] == 0){
			pila[top++] = e;
			dfsbcc (v, u);
			low[u] = min (low[u], low[v]);
			ch++;
			if (low[v] >= dfsn[u]){
				part[u] = 1;
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
	return ch;
}

void bcc (){
	REP( i , n ) part[ i ] = dfsn[ i ] = 0;
	REP( i , m ) ponte[ i ] = 0;
	nbicomp = timer = 0;
	REP( i , n ) if (dfsn[ i ] == 0) part[ i ] = dfsbcc( i ) >= 2;
}
vi G[ N + 5 ] , C[ N + 5 ];

void bfs( int &s , int &d ){
	vi dist( n , INF );
	deque< int > Q;
	Q.push_front( s );
	dist[ s ] = 0;
	int u = s;
	while( !Q.empty() ){
		u = Q.front();Q.pop_front();
		REP( i , SZ( G[ u ] ) ){
			int v = G[ u ][ i ] , w = C[ u ][ i ];
			if( dist[ u ] + w < dist[ v ] ){
				if( w == 0 ) Q.push_front( v );
				else Q.push_back( v );
				dist[ v ] = dist[ u ] + w;
			}
		}
	}
	s = u;
	d = dist[ u ];
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		sc( n ) , sc( m );
		REP( i , n ) E[ i ].clear();
		REP( i , m ){
			int u , v;
			sc( u ) , sc( v );
			u-- ,  v--;
			orig[ i ] = u;
			dest[ i ] = v;
			E[ u ].pb( i );
			E[ v ].pb( i );
		}
		bcc();
		REP( i , n ) G[ i ].clear() , C[ i ].clear();
		int puentes = 0;
		REP( i , m ){
			int u = orig[ i ] , v = dest[ i ];
			int w = ponte[ i ];
			puentes += w;
			G[ u ].pb( v );
			C[ u ].pb( w );
			
			G[ v ].pb( u );
			C[ v ].pb( w );
		}
		int s = 0 , d = 0;
		bfs( s , d );
		bfs( s , d );
		printf( "%d\n" , puentes - d );
	}
}


