#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; ++i)
#define SZ(v) ((int)v.size())
#define pb push_back
#define all(v) v.begin(),v.end()

#define mp make_pair
#define fi first
#define se second

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<string> vs;

const int WATER=INT_MAX;
vi dx={0,0,1,-1};
vi dy={1,-1,0,0};
int bfs(vs &S,vvi &vis,int n,int m,int x,int y,int label){
	if(vis[x][y]!=-1)return -1;
	queue<int>Q;
	Q.push(x);
	Q.push(y);
	vis[x][y]=label;
	int cnt=1;
	while(!Q.empty()){
		int x=Q.front();Q.pop();
		int y=Q.front();Q.pop();
		REP(k,4){
			int nx=x+dx[k];
			int ny=y+dy[k];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&S[nx][ny]=='.'&&vis[nx][ny]==-1){
				Q.push(nx);
				Q.push(ny);
				vis[nx][ny]=label;
				cnt++;
			}
		}
	}
	return cnt;
}
int main(){
	int n,m,K;
	while(cin>>n>>m>>K){
		vs S(n);
		REP(i,n)cin>>S[i];
		vvi vis(n,vi(m,-1));
		
		for(auto j:{0,m-1}){
			REP(i,n){
				if(S[i][j]=='.'){
					bfs(S,vis,n,m,i,j,WATER);
				}
			}
		}
		for(auto i:{0,n-1}){
			REP(j,m){
				if(S[i][j]=='.'){
					bfs(S,vis,n,m,i,j,WATER);
				}
			}
		}
		int id=0;
		vpii vec;
		REP(i,n)REP(j,m){
			if(S[i][j]=='*')continue;
			if(vis[i][j]!=-1)continue;
			int cnt=bfs(S,vis,n,m,i,j,id);
			vec.pb(mp(cnt,id));
			//DEBUG2(cnt,id);
			id++;
		}
		sort(all(vec));
		int needed=SZ(vec)-K;
		vi table(SZ(vec));
		REP(k,needed) table[vec[k].se]=1;
		int ans=0;
		REP(i,n)REP(j,m){
			if(S[i][j]=='*')continue;
			if(vis[i][j]==WATER)continue;
			if(table[vis[i][j]]){
				S[i][j]='*';
				ans++;
			}
		}
		cout<<ans<<'\n';
		REP(i,n)cout<<S[i]<<'\n';
		/*
		REP(i,n){
			REP(j,m)cout<<vis[i][j]<<" ";
			cout<<endl;
		}
		*/
	}
}

