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

#define test() cerr<<"hola que hace ?" << endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define DEBUG3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

const int MAX_N=200000;
int id[MAX_N];
void initGraph(int n){
	REP(i,n)id[i]=i;
}
int Find( int x ){ return id[ x ] = (id[ x ] == x ? x : Find( id[ x ] ) );}
void Union(int x, int y) {id[Find(x)] = Find(y);} // Find( x ) != Find( y )

struct Edge{
	int u , v , w,c,ind;
	Edge(){}
	Edge( int u , int v , int w, int c,int ind ) : u( u ) , v( v ) , w( w ) ,c(c),ind(ind){}
};
bool operator < ( const Edge &a , const Edge &b ){ return a.c < b.c ;}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		vi w(m),c(m);
		REP(i,m)scanf("%d",&w[i]);
		REP(i,m)scanf("%d",&c[i]);
		vector<Edge> E,E2;
		REP(i,m){
			int u,v;
			scanf("%d%d",&u,&v);
			u--,v--;
			E.pb(Edge(u,v,w[i],c[i],i));
		}
		initGraph(n);
		sort(all(E));
		int S;
		scanf("%d",&S);
		ll ans=0;
		REP(i,SZ(E)){
			int u=E[i].u,v=E[i].v;
			int cost=E[i].c;
			if(Find(u)!=Find(v)){
				int cur=S/cost;
				E[i].w-=cur;
				ans+=E[i].w;
				S-=cur*cost;
				Union(u,v);
				E2.pb(E[i]);
			}
		}
		cout<<ans<<'\n';
		REP(i,SZ(E2))
			printf("%d %d\n",E2[i].ind+1,E2[i].w);
	}
}


