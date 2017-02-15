#include <bits/stdc++.h>
#define N 500
#define INF 100000000
#define pb push_back
using namespace std;

char M[N+5][N+5],MT[N+5][N+5];
int D[N+5][N+5],n,m;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

struct nodo{
	int x,y;
	nodo(int a,int b){
		x=a,y=b;
	}
};

int bfs1(){
	deque<nodo>Q;
	D[0][0]=0;
	Q.pb(nodo(0,0));
	while(!Q.empty()){
		nodo p=Q.front();
		Q.pop_front();
		for(int i=0;i<4;++i){
			int nx=p.x+dx[i],ny=p.y+dy[i];
			if(nx>=0 && nx<n && ny>=0 && ny<m && D[nx][ny]==-1 && M[nx][ny]=='.' && MT[nx][ny]=='.'){
				Q.pb(nodo(nx,ny));
				D[nx][ny]=D[p.x][p.y]+1;
			}
		}
	}
	return D[n-1][m-1];
}

int bfs2(){
	deque<nodo>Q;
	//puts("entra");
	//cout<<n<<" "<<m<<endl;
	D[0][0]=0;
	Q.pb(nodo(0,0));
	while(!Q.empty()){
		nodo p=Q.front();
		Q.pop_front();
		for(int i=0;i<4;++i){
			int nx=p.x+dx[i],ny=p.y+dy[i];
			if(nx>=0 && nx<n && ny>=0 && ny<m && D[nx][ny]==-1 && M[nx][ny]=='.'){
				//cout<<p.x<<" "<<p.y<<" "<<nx<<" "<<ny<<endl;
				Q.pb(nodo(nx,ny));
				D[nx][ny]=D[p.x][p.y]+1;
			}
		}
	}
	return D[n-1][m-1];
}

int bfs3(){
	deque<nodo>Q;
	D[0][0]=0;
	Q.pb(nodo(0,0));
	while(!Q.empty()){
		nodo p=Q.front();
		Q.pop_front();
		for(int i=0;i<4;++i){
			int nx=p.x+dx[i],ny=p.y+dy[i];
			if(nx>=0 && nx<n && ny>=0 && ny<m && D[nx][ny]==-1 && MT[nx][ny]=='.'){
				Q.pb(nodo(nx,ny));
				D[nx][ny]=D[p.x][p.y]+1;
			}
		}
	}
	return D[n-1][m-1];
}
int main(){
	cin>>n>>m;

	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>M[i][j];
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>MT[i][j];
		}
	}
	memset(D,-1,sizeof(D));
	int x=bfs1();
	//cout<<"doble: "<<x<<endl;
	if(x==-1){
		puts("NO");
		return 0;
	}
	memset(D,-1,sizeof(D));
	int y=bfs2();
	memset(D,-1,sizeof(D));
	int z=bfs3();
	//cout<<y<<" <--> "<<z<<endl;
	if(y==x && z==x)puts("YES");
	else puts("NO");
	
}


