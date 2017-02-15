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

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

const int MAX_N=200000;
const int MAX_LOG=18;

int rmq[MAX_LOG+1][MAX_N];
vi G[MAX_N],C[MAX_N];
void initGraph(int n){
	REP(i,n)G[i].clear(),C[i].clear();
}
void add(int u,int v,int w){
	G[u].pb(v);
	C[u].pb(w);
}
void fillRmq(int n){
	for(int k=1;k<=MAX_LOG;++k)
		REP(i,n) if(rmq[k-1][i]!=-1)rmq[k][i]=rmq[k-1][rmq[k-1][i]];
}
int goUp(int u,int steps){
	REP(k,MAX_LOG+1)
		if(steps&(1<<k))
			u=rmq[k][u];
	assert(u!=-1);
	return u;
}
int level[MAX_N];
ll dist[MAX_N];
int in[MAX_N],out[MAX_N];
int timer;
void dfs(int u,int p=-1,int h=0,ll d=0){
	level[u]=h;
	dist[u]=d;
	in[u]=timer++;
	REP(i,SZ(G[u])){
		int v=G[u][i];
		if(p==v)continue;
		int w=C[u][i];
		dfs(v,u,h+1,d+w);
	}
	out[u]=timer++;
}
ll f(int u, int v){
	return dist[v]-dist[u];
}
int binarySearch(int v,ll target){
	int d=level[v];
	for(int k=MAX_LOG;k>=0;--k)
		if(d>=(1<<k)){
			ll cost=f(rmq[k][v],v);
			if(cost<=target)
				target-=cost,v=rmq[k][v],d-=(1<<k);
		}
	return v;
}
/*
int binarySearch(int v,ll target){
	int lo=0,hi=level[v];
	//DEBUG2(lo,hi);
	if(f(0,v)<=target)return 0;
	while(hi-lo>1){
		int med=(hi-lo)>>1;
		int u=goUp(v,med);
		if(f(u,v)<=target)lo=med;
		else hi=med;
	}
	return goUp(v,lo);
}
*/
const int MAX_VAL=2*MAX_N;
int bit[MAX_VAL+2];
void upd(int pos,int val){
	while(pos<=MAX_VAL){
		bit[pos]+=val;
		pos+=(pos&-pos); 
	}
}
void update(int pos,int val){//to 1-based
	upd(pos+1,val);
}
void update(int lo,int hi,int val){//0-based safe
	update(lo ,val);
	update(hi + 1,-val);
}
int qry(int pos){
	int sum=0;
	while(pos){
		sum+=bit[pos];
		pos-=(pos&-pos);
	}
	return sum;
}
int Query(int pos){ return qry(pos+1); }

int main(){
	int n;
	while(scanf("%d",&n)==1){
		vi A(n);
		REP(i,n)scanf("%d",&A[i]);
		clr(rmq,-1);
		initGraph(n);
		REP(i,n-1){
			int u,w,v=i+1;
			scanf("%d%d",&u,&w);
			u--;
			rmq[0][v]=u;
			add(u,v,w);
		}
		fillRmq(n);
		//test();
		timer=0;
		dfs(0);
		//test();
		clr(bit,0);
		REP(v,n){
			int u=binarySearch(v,A[v]);
			if(u==v)continue;
			//DEBUG3(u+1,v+1,A[v]);
			int lo=u,hi=rmq[0][v];
			update(in[lo],in[hi],+1);
			//DEBUG2(f(u,v),f(0,v));
		}
		REP(u,n){
			int ans=0;
			ans+=Query(in[u]);
			ans-=Query(out[u]);
			printf("%d%c",ans,u+1==n?10:32);
		}
	}
}



