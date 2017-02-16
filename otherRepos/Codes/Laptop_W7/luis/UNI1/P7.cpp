#include <bits/stdc++.h>
using namespace std;

#define MAXN 20005

int N,M;
vector<int>adj[MAXN][2];

int x;

int main()
{
	while(scanf("%d%d",&N,&M)==2){
		printf("%d %d\n",N,M);
		if(N==0&&M==0)break;
		for(int i=0;i<MAXN;i++){
			adj[i][0].clear(),adj[i][1].clear();
		}
		for(int i=0;i<N;i++){
			scanf("%d",&x);
			int idx=x%M+10000;
			adj[idx][abs(x%2)].push_back(x);
		}
		
		for(int i=0;i<MAXN;i++){
			sort(adj[i][0].begin(),adj[i][0].end());
			sort(adj[i][1].rbegin(),adj[i][1].rend());	
		}
		for(int i=0;i<MAXN;i++){
			for(int j=0;j<adj[i][1].size();j++){
				cout<<adj[i][1][j]<<"\n";
			}
			for(int j=0;j<adj[i][0].size();j++)
				cout<<adj[i][0][j]<<"\n";
		}
	}
}



