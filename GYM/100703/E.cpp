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

#define test() cout << "hola q hace" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 200000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

#define VIZ(e,x) (orig[e] == x? dest[e] : orig[e])
int n,m,fin;
int orig[N], dest[N], pila[N], top = 0;
vi E[N];
int low[N], dfsn[N], part[N], timer;
int ponte[N], bicomp[N], nbicomp;
vi G[ N + 5 ];
int dfsbcc (int u, int p = -1){
	low[u] = dfsn[u] = ++timer;
	int ch = 0;
	for( auto e : E[ u ] ){
		int v = VIZ (e, u);
		if (dfsn[v] == 0){
			pila[top++] = e;
			G[ u ].pb( v );
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
	REP(i,n) part[i] = dfsn[i] = 0;
	REP(i,m) ponte[i] = 0;
	nbicomp = timer = 0;
	REP(i,n) if (dfsn[i] == 0) part[i] = dfsbcc (i) >= 2;
}

int DP[ N + 5 ];
int MAXI[ N + 5 ];
int dfs( int u , int p = -1 ){
	DP[ u ] = 1;
	for( int v : G[ u ] ) {
		if( v == p ) continue;
		dfs( v , u );
		DP[ u ] += DP[ v ];
		MAXI[ u ] = max( MAXI[ u ] , DP[ v ] );
	}
}
int main(){
	while( sc( n ) == 1 ){
		sc( m );
		REP( i , N ) E[ i ].clear() , G[ i ].clear();	
		REP( i , m ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			orig[ i ] = u;
			dest[ i ] = v;
			E[ u ].pb( i );
			E[ v ].pb( i );
		}
		clr( MAXI , 0 );
		bcc();
		dfs( 0 , -1 );
		int ans = 1 << 30 , ind = -1;
		REP( i , n )
			if( part[ i ] ){
				int cur = max( MAXI[ i ] , max( n - DP[ i ] , 1 ) );
				if( cur < ans ) ans = cur , ind = i;
			}
		if( ind == -1 ) ind = 0;
		printf( "%d\n" , ind + 1 );
	}
}


