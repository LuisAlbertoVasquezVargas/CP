#include<bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i=x;i<y;i++)
#define MAXN 20110

vector<int>adj[MAXN];
int T,N,a,b,hijos[MAXN],ans;
bool vis[MAXN];
int caso=0;

void dfs(int u,int p){
	vis[u]=1;
	int sum=0;
	
	FOR(i,0,adj[u].size()){
		int v=adj[u][i];
		if(v==p)continue;
		if(!vis[v]){
			dfs(v,u);
			hijos[u]+=hijos[v];
		}
	}
	hijos[u]++;
	
		
}

void f(int u,int p){
	if(vis[u])return;
	vis[u]=1;
	vector<int>h;
	int ax=0;
	int sum=0;
	FOR(i,0,adj[u].size()){
		int v=adj[u][i];
		if(v==p)continue;
		f(v,u);
		h.push_back(hijos[v]);
		sum+=hijos[v];
	}
	int NN=N-1;
	h.push_back(N-1-sum);
	for(int i=0;i<h.size();i++){
		ax+=(NN-h[i])*h[i];
		NN-=h[i];
	}
	ans=max(ans,ax);
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		ans=0;
		
		FOR(i,0,N)adj[i].clear();
		FOR(i,0,N-1){
			scanf("%d%d",&a,&b);
			a--;b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		memset(hijos,0,sizeof(hijos));
		memset(vis,0,sizeof(vis));
		dfs(0,-1);
		memset(vis,0,sizeof(vis));
		f(0,-1);
		printf("Case #%d: %d\n",++caso,ans);
		
	}
}
