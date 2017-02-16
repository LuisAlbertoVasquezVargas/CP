#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAX_K=3;
const int MAX_N=100;
char S[MAX_K*MAX_N+2][MAX_K*MAX_N+2];

void fix(int &x,int n){
	if(x==-1){
		x=n-1;
		return;
	}
	if(x==n){
		x=0;
		return;
	}
	if(x>=0&&x<n)return;
	x%=n;
	if(x<0)x+=n;
}

vi dx={0,0,1,-1};
vi dy={1,-1,0,0};
vvi bfs(int sx,int sy,int n,int m){
	vvi vis(n,vi(m));
	queue<int>Q;
	vis[sx][sy]=1;
	Q.push(sx);
	Q.push(sy);
	while(!Q.empty()){
		int x,y;
		x=Q.front();
		Q.pop();
		y=Q.front();
		Q.pop();
		REP(k,4){
			int nx=x+dx[k];
			int ny=y+dy[k];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&S[nx][ny]!='#'&&!vis[nx][ny]){
				vis[nx][ny]=1;
				Q.push(nx);
				Q.push(ny);
			}
		}
	}
	return vis;
}
void impr(vvi &T){
	for(auto v:T){
		for(auto x:v)cout<<x;
		cout<<'\n';
	}
	cout<<'\n';
}
vvi get(int x,int y,int lenX,int lenY,vvi &T){
	vvi ans;
	REP(i,lenX){
		vi vec;
		REP(j,lenY) vec.pb(T[x+i][y+j]);
		ans.pb(vec);
	}
	return ans;
}
bool solveX(vvi &T,int n,int m){
	vvi flag;
	REP(k,MAX_K){
		vvi temp=get(k*n,0,n,MAX_K*m,T);
		//DEBUG("myflag");
		//impr(temp);
		if(!k)flag=temp;
		else{
			if(flag!=temp) return 0;
		}
	}
	return 1;
}
bool solveY(vvi &T,int n,int m){
	vvi flag;
	REP(k,MAX_K){
		vvi temp=get(0,k*m,MAX_K*n,m,T);
		//DEBUG("myflag");
		//impr(temp);
		if(!k)flag=temp;
		else{
			if(flag!=temp) return 0;
		}
	}
	return 1;
}
void solveQuery(int x,int y,int n,int m,bool okX,bool okY,vvi &T){
	if(okX && okY){
		//DEBUG("infiniteXY");
		fix(x,n);
		fix(y,m);
		puts(T[x][y]?"yes":"no");
		return;
	}
	if(!okX && !okY){
		//DEBUG("finite");
		x+=n;
		y+=m;
		//DEBUG2(x,y);
		if(x>=0&&x<MAX_K*n&&y>=0&&y<MAX_K*m&&T[x][y])puts("yes");
		else puts("no");
		return;
	}
	if(okX){
		//DEBUG("HAHA");
		x+=n;
		y+=m;
		fix(x,n);
		if(y>=0&&y<MAX_K*m&&T[x][y])puts("yes");
		else puts("no");
		return;
	}
	if(okY){
		x+=n;
		y+=m;
		fix(y,m);
		if(x>=0&&x<MAX_K*n&&T[x][y])puts("yes");
		else puts("no");
		return;
	}
	assert(0);
	puts(":P");
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		REP(i,n)scanf("%s",S[i]);
		REP(i,MAX_K*n)REP(j,MAX_K*m)S[i][j]=S[i%n][j%m];

		vvi T=bfs(n,m,MAX_K*n,MAX_K*m);
		bool okX=solveX(T,n,m);
		bool okY=solveY(T,n,m);
		//impr(T);
		//DEBUG2(okX,okY);
		//REP(i,MAX_K*n)cout << S[i]<<'\n';
		int Q;
		scanf("%d",&Q);
		REP(it,Q){
			int x,y;
			scanf("%d%d",&x,&y);
			solveQuery(x,y,n,m,okX,okY,T);
		}
	}
}
