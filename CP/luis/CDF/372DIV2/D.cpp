#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0 ; i < n ; ++i)
#define clr(T,val) memset(T,val,sizeof(T))

#define SZ(v) ((int)v.size())
#define pb push_back
#define all(v) v.begin(),v.end()

#define fi first
#define se second
#define mp make_pair

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

const int N = 1e3;
const int M = 1e4;
const ll INF = 1e15;
int orig[M+5],dest[M+5];
ll peso[M+5];
int id[N + 5];
int Find(int x){ return id[ x ] == x ? x : Find(id[x]);}
void Union(int p , int q){
	p = Find(p) , q = Find(q);
	id[p] = q;
}
void initUF(int n){
	REP(i,n) id[i] = i;
}
vi G[ N + 5 ] ;
vll C[ N + 5 ];
void add( int u , int v , ll w ){
	G[ u ].pb( v );
	C[ u ].pb( w );
}
struct Node{
    int id ;
    ll dist;
    Node( int id , ll dist ) : id( id ) , dist( dist ) {}
};
bool operator < ( const Node &a , const Node &b ){ return a.dist > b.dist; }

void initDijkstra(int n){
	REP(i,n) G[i].clear(),C[i].clear();
}
vll dijkstra(int n , int m , int s){
	vll dist( n , INF );
	vi vis( n );
	priority_queue< Node > Q;
	dist[ s ] = 0;
    Q.push( Node( s , 0 ) );
    while( !Q.empty() ){
        Node U = Q.top() ; Q.pop();
        int u = U.id ;
        if( vis[ u ] ) continue;
        REP( i , SZ( G[ u ] ) ){
            int v = G[ u ][ i ];
            ll w = C[ u ][ i ];
            if( !vis[ v ] && dist[ u ] + w < dist[ v ] ){
                dist[ v ] = dist[ u ] + w;
                Q.push( Node( v , dist[ v ] ) );
            }
        }
    }
	return dist;
}
void fillDijkstra(int m){
	REP(i,m){
		add(orig[i],dest[i],peso[i]);
		add(dest[i],orig[i],peso[i]);
	}
}
int main(){
	int n , m , s , t , L;
	while(scanf("%d%d%d%d%d",&n,&m,&L,&s,&t) == 5){
		initUF(n);
		vi ind;
		REP(i,m){
			int w;
			scanf("%d%d%d",&orig[i],&dest[i],&w);
			peso[i] = w;
			if(peso[i] == 0){
				ind.pb(i);
				peso[i] = INF;
			}else{
				Union(orig[i],dest[i]);
			}
		}
		REP(i , SZ(ind)){
			int u = orig[ind[i]] , v = dest[ind[i]];
			if(Find(u) != Find(s)) swap(u , v);
			Union(u,v);
			if(Find(s) != Find(t)){
				peso[ind[i]] = 1;
			}else{
				initDijkstra(n);
				fillDijkstra(m);
				vll dS = dijkstra(n,m,s);
				vll dT = dijkstra(n,m,t);
				
				ll x = L - dS[u] - dT[v];
				peso[ind[i]] = max(x , 1LL);
				break;
			}
		}
		initDijkstra(n);
		fillDijkstra(m);
		vll dS = dijkstra(n,m,s);
		//vll dT = dijkstra(n,m,t);
		
		if(dS[t] != L){
			puts("NO");
			//REP(i,m)printf("%d %d% lld\n",orig[i],dest[i],peso[i]);
			continue;
		}
		puts("YES");
		REP(i,m)printf("%d %d %lld\n",orig[i],dest[i],peso[i]);
	}
}


