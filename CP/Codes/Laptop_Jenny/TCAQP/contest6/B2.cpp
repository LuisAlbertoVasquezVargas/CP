#include<bits/stdc++.h>

using namespace std;


#define MAXN 550

int c,d,v,x,y,T;
vector<int>adj[MAXN];
int E[MAXN][MAXN];
vector<pair<int,pair<int,int> > >VE;
char ch,ch2;
bool on[MAXN],off[MAXN];

int f(int nodo,bool b){
	vis[nodo]=1;
	for(int i=0;i<adj[nodo].size();i++){
		int to=adj[nodo][i];
		if(vis[nodo])return;
	}
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&c,&d,&v);
		memset(E,0,sizeof(E));
		
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
				if(E[i][j])VE.push_back(make_pair(E[i][j],make_pair(i,j)));
		for(int i=0;i<c;i++)
			for(int j=c;j<c+d;j++)
				if(E[j][i])VE.push_back(make_pair(E[j][i],make_pair(j,i)));
		
		for(int i=0;i<c+d;i++){
			
		}
	}
}
