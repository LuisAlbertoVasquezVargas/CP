#include<bits/stdc++.h>

using namespace std;

#define MAXN 550

int c,d,v,x,y,T;
vector<int>adj[MAXN];
int E[MAXN][MAXN];
vector<pair<int,pair<int,int> > >VE;
char ch,ch2;
bool on[MAXN],off[MAXN];

bool vis[MAXN];

void check(int nodo){
	bool ok=1;
	vis[nodo]=1;
	off[nodo]=1;
	for(int i=0;i<adj[nodo].size();i++){
		if(vis[adj[nodo][i]])continue;
		//check(adj[nodo][i]);
	}
	
}



int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&c,&d,&v);
		memset(E,0,sizeof(E));
		VE.clear();
		for(int i=0;i<c+d;i++)adj[i].clear();
		for(int i=0;i<v;i++){
			cin>>ch>>x>>ch2>>y;
			x--,y--;
			if(ch=='D')x+=c;
			if(ch2=='D')y+=c;
			E[x][y]++;
		}
		for(int i=0;i<c;i++)
			for(int j=c;j<c+d;j++)
				if(E[i][j]){
					VE.push_back(make_pair(E[i][j],make_pair(i,j)));
					adj[i].push_back(j);
				}
		for(int i=0;i<c;i++)
			for(int j=c;j<c+d;j++)
				if(E[j][i]){
					VE.push_back(make_pair(E[j][i],make_pair(j,i)));
					adj[j].push_back(i);
				}
		sort(VE.rbegin(),VE.rend());
		memset(off,0,sizeof(off));
		memset(on,0,sizeof(on));
		
		int ans=0;
		for(int i=0;i<VE.size();i++){
			int PE=VE[i].first,to=VE[i].second.second,fr=VE[i].second.first;
			if(off[fr])continue;
			if(on[to])continue;
			for(int i=0;i<adj[fr].size();i++)
				if(on[adj[fr][i]])continue;
			ans+=PE;
			on[fr]=1;
			memset(vis,0,sizeof(vis));
			for(int j=0;j<adj[fr].size();j++)
				check(adj[fr][j]);
		}
		
		cout<<ans<<endl;
	}
}
