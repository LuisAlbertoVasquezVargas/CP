#include<bits/stdc++.h>

using namespace std;

#define FOR(i,x,y) for(int i=x;i<y;i++)
#define oo (1<<28)

int N,A[250][250];
int dis[250][250];

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int caso=0;

int main(){
	while(scanf("%d",&N)==1){
		if(N==0)break;
		FOR(i,0,N)
			FOR(j,0,N){
				scanf("%d",&A[i][j]);
				dis[i][j]=oo;	
			}
		priority_queue<pair<int,pair<int,int> > >Q;
		dis[0][0]=A[0][0];
		Q.push(make_pair(-A[0][0],make_pair(0,0)));
		while(!Q.empty()){
			pair<int,pair<int,int> >q=Q.top();
			pair<int,int>act=q.second;
			Q.pop();
			int x=act.first,y=act.second;
			FOR(i,0,4){
				int u=act.first+dx[i],v=act.second+dy[i];
				if(u>=0&&v>=0&&u<N&&v<N){
					if(dis[u][v]>dis[x][y]+A[u][v]){
						dis[u][v]=dis[x][y]+A[u][v];
						Q.push(make_pair(-dis[u][v],make_pair(u,v)));
					}
				}
			}
		}
		printf("Problem %d: %d\n",++caso,dis[N-1][N-1]);
		
	}
}
