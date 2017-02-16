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
#define DEBUG3( x , y , z ) cerr << #x << "=" << x << " " << #y << "=" << y << " " <<#z << "=" << z<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector<pii> vpii;
typedef vector< int > vi;

const int MAX_N=(int)1e5;
vi G[MAX_N];
int vis[MAX_N];
int DP[MAX_N];
void initGraph(int n){
	REP(i,n)G[i].clear();
	REP(i,n)vis[i]=0;
}
void add(int u,int v){
	G[u].pb(v);
	G[v].pb(u);
}
vpii myList;
void dfs(int u,int p=-1){
	vis[u]=1;
	DP[u]=1;
	for(auto v:G[u]){
		if(v==p)continue;
		if(!vis[v]){
			dfs(v,u);
			DP[u]+=DP[v];
			//myList.pb(mp(u,v));
		}
	}
	
}
void dfs2(int u,int p=-1){
	vis[u]=1;
	for(auto v:G[u]){
		if(v==p)continue;
		if(!vis[v]){
			dfs2(v,u);
			if(DP[v]&1)
				myList.pb(mp(u,v));
		}
	}
}
void impr(vpii &v){
	printf("%d\n",SZ(v));
	for(auto p:v)
		printf("%d %d\n",p.fi+1,p.se+1);
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		initGraph(n);
		REP(i,m){
			int u,v;
			scanf("%d%d",&u,&v);
			u--,v--;
			add(u,v);
		}
		bool ok=1;
		
		REP(i,n)
			if(!vis[i]){
				dfs(i);
				if(DP[i]&1){
					ok=0;
					break;
				}
			}
		
		if(!ok){
			puts("-1");
			continue;
		}
		REP(i,n)vis[i]=0;
		myList.clear();
		REP(i,n)
			if(!vis[i]){
				dfs2(i,-1);
			}
		impr(myList);
	}
}


