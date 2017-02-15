#include<bits/stdc++.h>

#define MAXN 100110
using namespace std;

#define FOR(i,x,y) for(int i=x;i<y;i++)

typedef unsigned long long ull;

int T,N,K;
int a,b,c,caso=0;
char ch;
vector<int>adj[MAXN];

int dis[MAXN],dp2[MAXN];
bool vis[MAXN];
bool done[MAXN];



int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&K);
		FOR(i,0,N+5)adj[i].clear();
		FOR(i,0,K){
			cin>>ch;
			scanf("%d%d%d",&a,&b,&c);
			a--;b--;c--;
			if(ch=='F'){
				adj[a].push_back(b);
				adj[a].push_back(c);
			}
			else{
				adj[a].push_back(c);
				adj[b].push_back(c);
			}
		}
		
		memset(dis,-1,sizeof(dis));
		queue<int>Q;
		Q.push(0);
		dis[0]=1;
		int k=MAXN;
		while(!Q.empty()){
			int q=Q.front();
			Q.pop();
			FOR(i,0,adj[q].size()){
				int u=adj[q][i];
				if(dis[u]==-1){
					dis[u]=dis[q];
					
					Q.push(u);
				}
				else{
					dis[u]++;
				}
			}
		}
		
		sort(dis,dis+N);
		int ans=0,loc=0;
		FOR(i,1,N){
			if(dis[i]==dis[i-1]){
				loc++;
			}
			else{
				ans=max(ans,loc);
				loc=0;
			}
		}
		printf("Case #%d: ",++caso);
		cout<<ans<<endl;
		
	}
}
