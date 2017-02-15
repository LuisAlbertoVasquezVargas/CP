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

#define test() cerr<<"hola que hace ?"<<endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define DEBUG3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;

#define v1 ( (node<<1) + 1 )
#define v2 v1 + 1
#define med ( ( a + b )>>1 )
#define LEFT v1 , a , med
#define RIGHT v2 , med + 1 , b
#define JOIN T[ node ] = max( T[ v1 ] , T[ v2 ] )

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
const int MAX_N=(int)1e4;
const int LOGN=15;

struct stripe {
	vi T;
	int len;
	stripe() {}
	stripe( vi &a ) : len( a.size() ) {
		int off = 1;
		for (; off < len; off<<=1);
		T = vi(off<<1,INT_MIN);
		build_tree(0,0,len-1,a);
	}
	void build_tree(int node,int a,int b,vi &A){
		if(a==b){
			T[node]=A[a];
			return;
		}
		build_tree(LEFT,A);
		build_tree(RIGHT,A);
		JOIN;
	}
	void update( int pos , int val ) { update( pos , val , 0 , 0 , len - 1 ); }
	void update( int pos , int val , int node , int a , int b ) {
		if ( pos > b || a > pos ) return;
		if ( a == b ) {
			T[ node ] = val;
			return;
		}
		update( pos , val , LEFT );
		update( pos , val , RIGHT );
		JOIN;
	}
	int get2( int lo , int hi ) { return get2( lo , hi , 0 , 0 , len - 1 ); }
	int get2( int lo , int hi , int node , int a , int b ) {
		if( lo > b || a > hi ) return INT_MIN;
		if( a >= lo && b <= hi ) return T[ node ];
		return max( get2( lo , hi , LEFT ) ,  get2( lo , hi , RIGHT ) );
	}

} st[MAX_N];
int chain[MAX_N],tam[MAX_N],h[MAX_N],p[MAX_N];
int csz , cola[MAX_N],values[MAX_N];
vi G[MAX_N],C[MAX_N];

int queryNodos( int u , int v ) {
	//DEBUG2(u,v);
	int maxi = INT_MIN;
	while( chain[ u ] != chain[ v ] ) {
		if( h[ chain[ u ]]  < h[ chain[ v ] ]) swap( u , v );
		int c = chain[ u ] , len = st[ c ].len;
		maxi = max( maxi , st[ c ].get2( 0 , h[ u ] - h[ c ] ) );
		u = p[ chain[ u ] ];
	}
	//DEBUG3(maxi,chain[u],chain[v]);
	if( h[ u ] < h[ v ] ) swap( u , v );
	int c = chain[ u ] , len = st[ c ].len;
	/*
	DEBUG(h[ v ] - h[ c ]);
	REP(k,3)DEBUG(st[c].get2(k,k));
	DEBUG("");
	*/
	maxi = max( maxi , st[ c ].get2( h[ v ] - h[ c ] , h[ u ] - h[ c ] ) );
	return maxi;
}
void initGraph(int n){
	REP(i,n)G[i].clear(),C[i].clear();
}
int rmq[LOGN + 1][MAX_N + 5];

void initHLD(int n){
	clr( rmq , -1 );
	
	clr( p , -1 );
	csz = 0;
	cola[ csz++ ] = 0;
	p[ 0 ] = 0;
	h[ 0 ] = 0;
	values[0]=-1;
	REP( i , csz ) {
		int u = cola[ i ];
		REP(i,SZ(G[u])){
			int v=G[u][i];
			int w=C[u][i];
			if(~p[ v ]) continue;
			cola[ csz++ ] = v;
			p[ v ] = u;
			values[v]=w;
			rmq[ 0 ][ v ] = u;
			h[ v ] = h[ u ] + 1;
		}
	}
	
	for( int k = 1 ; k <= LOGN ; ++k )
			REP( i , n ) if( rmq[ k - 1 ][ i ] != -1 ) rmq[ k ][ i ] = rmq[ k - 1 ][ rmq[ k - 1 ][ i ] ];
			
	for( int i = csz - 1 ; i >= 0 ; --i ) {
		int u = cola[ i ];
		tam[ u ] = 1;
		REP(i,SZ(G[u])){
			int v=G[u][i];
			if( p[ u ] == v ) continue;
			tam[ u ] += tam[ v ];
		}
	}
	clr( chain , -1 );
	REP( i , csz ) {
		int u = cola[ i ];
		if ( ~chain[ u ] ) continue;
		chain[ u ] = u;
		int v = u;
		while( 1 ) { 
			int next = -1;
			REP(i,SZ(G[u])) {
				int v=G[u][i];
				if( p[ v ] == u )if ( next ==-1 || tam[ next ] < tam[ v ] ) next = v;
			}
			if( next == -1 ) break;
			chain[ next ] = chain[ u ];
			u = next;
		}
		int len = h[ u ] - h[ v ] + 1;
		vi a( len );
		REP( i , len ) {
			a[ i ] = values[u];
			u = p[ u ];
		}
		reverse( all( a ) );
		st[ v ] = stripe(a);
	}
}
int get(int dif,int x){
	for( int i = 0 ; i <= LOGN ; ++i ) 
		if(dif&(1<<i)) x=rmq[i][x];
	return x;
}
int LCA( int a , int b , int &ra,int &rb){
	if( h[ a ] > h[ b ] )
		return LCA(b,a,rb,ra);
	int or_b=b;
	int dif = h[ b ] - h[ a ];
	for( int i = 0 ; i <= LOGN ; ++i ) if( dif & (1<<i) ) b = rmq[ i ][ b ];
	ra=a,rb=b;
	if( a == b ){
		rb=get(dif-1,or_b);
		return a;
	}
	for( int k = LOGN ; k >= 0 ; --k )
		if( rmq[ k ][ a ] != rmq[ k ][ b ] ) a = rmq[ k ][ a ] , b = rmq[ k ][ b ];
	ra=a,rb=b;
	return rmq[ 0 ][ a ];
}
int solvePath(int a,int b){
	return queryNodos(a,b);
}
int solve(int a,int b){
	if(a==b)assert(0);
	int ra=-1,rb=-1;
	int lca=LCA(a,b,ra,rb);
	/*
	DEBUG3(a,b,lca);
	DEBUG2(ra,rb);
	*/
	if(a==lca){
		//DEBUG((a==lca));
		return solvePath(rb,b);
	}
	if(b==lca){
		return solvePath(ra,a);
	}
	return max(solvePath(rb,b),solvePath(ra,a));
}
int main(){
	int cases;
	scanf("%d",&cases);
	REP(tc,cases){
		int n;
		scanf("%d",&n);
		initGraph(n);
		vi orig,dest,peso;
		REP(i,n-1){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			u--,v--;
			orig.pb(u);
			dest.pb(v);
			peso.pb(w);
			
			G[u].pb(v);
			C[u].pb(w);
			G[v].pb(u);
			C[v].pb(w);
		}
		initHLD(n);
		//REP(i,n)DEBUG(values[i]);
		char op[10];
		while(1){
			scanf("%s",op);
			if(op[0]=='C'){
				//Change
				int e,w;
				scanf("%d%d",&e,&w);
				e--;
				if(p[orig[e]]==dest[e]){
					int u=orig[e];
					int c = chain[ u ] , len = st[ c ].len;
					st[ c ].update( h[ u ] - h[ c ] , w );
				}else{
					int u=dest[e];
					int c = chain[ u ] , len = st[ c ].len;
					st[ c ].update( h[ u ] - h[ c ] , w );
				}
			}else if(op[0]=='Q'){
				int u,v;
				scanf("%d%d",&u,&v);
				u--,v--;
				printf("%d\n",solve(u,v));
			}else{
				break;
			}
		}
	}
}



