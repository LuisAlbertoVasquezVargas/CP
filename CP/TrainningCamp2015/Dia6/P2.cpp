#include<bits/stdc++.h>

using namespace std;

#define MAXN 5050
#define oo (1LL<<40)

long long dis[5050][3];
int H[3];
vector<pair<long long,int > >adj[MAXN];

int J,B,C,N,S;
int a,b,c;

void dijkstra(int n){
	for(int i=1;i<=J;i++)dis[i][n]=oo;
	dis[H[n]][n]=0;
	priority_queue<pair<long long,int > > Q;
	Q.push(make_pair(0,H[n]));
	while(!Q.empty()){
		pair<long long,int>q = Q.top();
		Q.pop();
		int x=q.second;
		
		for(int i=0;i<adj[x].size();i++){
			int to=adj[x][i].second;
			if(dis[to][n]>1LL*dis[x][n]+1LL*adj[x][i].first){				
				dis[to][n]=dis[x][n]+adj[x][i].first;
				Q.push(make_pair(-dis[to][n],to));
			}
		}
	}
}

int main(){
	while(scanf("%d%d%d%d%d",&J,&B,&C,&N,&S)==5){
		if(J==-1)break;
		for(int i=1;i<=J;i++)adj[i].clear();
		for(int i=0;i<S;i++){
			scanf("%d%d%d",&a,&b,&c);
			adj[a].push_back(make_pair(c,b));
			adj[b].push_back(make_pair(c,a));
		}
		H[0]=B,H[1]=C,H[2]=N;
		dijkstra(0);dijkstra(1);dijkstra(2);
		
		long long d1=dis[C][0],d2=dis[N][0],maxi=0LL,ans1=d1,ans2=d2;
		for(int i=1;i<=J;i++){
			
			if(dis[i][1]+dis[i][0]<=d1&&dis[i][2]+dis[i][0]<=d2){
				if(dis[i][0]>maxi){
					maxi=dis[i][0];
					ans1=dis[i][1];
					ans2=dis[i][2];
				}
			}
		}
		cout<<maxi<<" "<<ans1<<" "<<ans2<<endl;
	}
}
