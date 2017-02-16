#include<cstdio>
#include<vector>
#include<iostream>
#define pb push_back
#define N 300
using namespace std;
vector<int>adj[N+5];
int color[N+5];
bool ok;

void dfs(int x, int col){
	color[x]=col;
	for(int i=0;i<adj[x].size();++i){
		int vec=adj[x][i];
		if(color[vec]==-1)dfs(vec,1-col);
		else{
			if(color[x]==color[vec])ok=0;
		}
	}

}


int main(){
	int v,a,b;
	while(scanf("%d",&v)==1){
		//cout<<"v: "<<v<<endl;
		if(v==0)break;
		for(int i=0;i<v;++i){
			adj[i].clear();
			color[i]=-1;
		}
		while(scanf("%d %d",&a,&b)==2){
			//cout<<a<<" "<<b<<endl;
			if(a==0 && b==0)break;
			a--,b--;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		ok=1;
		for(int i=0;i<v;++i){
			if(color[i]==-1)dfs(i,0);
		}
		if(ok)puts("YES");
		else puts("NO");
	}
}
