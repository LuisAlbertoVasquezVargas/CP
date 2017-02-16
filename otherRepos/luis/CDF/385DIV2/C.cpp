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
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

const int MAX_N=(int)1e3;
vi G[MAX_N];
int counter=0;
int vis[MAX_N];
void init(int n){
	REP(i,n)vis[i]=0;
	REP(i,n)G[i].clear();
}
void add(int u,int v){
	G[u].pb(v);
	G[v].pb(u);
}
void dfs(int u){
	counter++;
	vis[u]=1;
	for(auto v:G[u])
		if(!vis[v])dfs(v);
}
int main(){
	int n,m,K;
	while(scanf("%d%d%d",&n,&m,&K)==3){
		init(n);
		vi countries(K);
		REP(i,K)scanf("%d",&countries[i]),countries[i]--;
		REP(i,m){
			int u,v;
			scanf("%d%d",&u,&v);
			u--,v--;
			add(u,v);
		}
		int cur=n,best=0;
		vi vec;
		for(auto p:countries){
			counter=0;
			dfs(p);
			vec.pb(counter);
			cur-=counter;
		}
		sort(all(vec));
		reverse(all(vec));
		vec[0]+=cur;	
		int ans=0;
		for(auto x:vec){
			ans+=((x*(x-1))>>1);
		}
		ans-=m;
		printf("%d\n",ans);
	}
}


