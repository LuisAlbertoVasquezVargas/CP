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

#define N 200000
#define INF (1LL<<60)

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;

#define VIZ(e,x) (orig[e] == x? dest[e] : orig[e])
int n,m,fin;
int orig[N + 1], dest[N + 1], peso[N + 1],pila[N + 1], top = 0;
vi E[N + 1];
int low[N + 1], dfsn[N + 1], part[N + 1], timer;
int ponte[N + 1], bicomp[N + 1] , nbicomp;

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
				nbicomp++;
				do{
					fin = pila[--top];
					bicomp[fin] = nbicomp;
				}while (fin != e);
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

vi G[ N + 5 ];
vll C[ N + 5 ];
struct Node{
    int id ;
    ll dist;
    Node( int id , ll dist ) : id( id ) , dist( dist ) {}
};
bool operator < ( const Node &a , const Node &b ){ return a.dist > b.dist; }

void bfs( int s , int &t , vll &dist ){
	dist = vll( n , INF );
	priority_queue< Node > Q;
	dist[ s ] = 0;
    Q.push( Node( s , 0 ) );
    int u;
    while( !Q.empty() ){
        Node U = Q.top() ; Q.pop();
        u = U.id ;
        REP( i , SZ( G[ u ] ) ){
            int v = G[ u ][ i ];
            ll w = C[ u ][ i ];
            if( dist[ u ] + w < dist[ v ] ){
                dist[ v ] = dist[ u ] + w;
                Q.push( Node( v , dist[ v ] ) );
            }
        }
    }
    t = u;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		sc( n ) , sc( m );
		REP( i , n ) {
			E[ i ].clear();
			G[ i ].clear();
			C[ i ].clear();
		}
		REP( i , m ){
			int u , v , w;
			sc( u ) , sc( v ) , sc( w );
			u -- , v --;
			orig[ i ] = u;
			dest[ i ] = v;
			peso[ i ] = w;
			E[ u ].pb( i );
			E[ v ].pb( i );
		}
		bcc();
		REP( i , m ){
			int u = orig[ i ] , v = dest[ i ] , w = peso[ i ];
			if( !ponte[ i ] ) w = 0;
				
			G[ u ].pb( v );
			C[ u ].pb( w );
				
			G[ v ].pb( u );
			C[ v ].pb( w );
		}
		int s = 0 , t , temp;
		vll dist , distS , distT;
		bfs( s , t , dist );
		bfs( t , s , distT );
		bfs( s , temp , distS );
		ll best = INF , city = -1;
		REP( u , n ){
			ll d = max( distS[ u ] , distT[ u ] );
			if( d < best ){
				best = d;
				city = u;
			}
		}
		assert( city != -1 );
		cout << city + 1 << " " << best << '\n';
	}
}


