#include<bits/stdc++.h>

using namespace std;

#define MAXN 528
#define INF (1<<29)

int n,m;
vector<pair<int,int> >V;
char A[MAXN][MAXN];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

pair<pair<int,int > ,int> dp[MAXN][MAXN];

inline int get(char c){
	if(c=='D')return 0;
	if(c=='U')return 2;
	if(c=='R')return 1;
	if(c == 'L')return 3;
	return -1;
}

void init(){
	V.clear();
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			dp[i][j].first = make_pair(-1,-1);
}

pair<pair<int,int>,int> operator + (const pair<pair<int,int>,int> &A, const pair<pair<int,int>,int> &B){
	return make_pair(make_pair(A.first.first+B.first.first,A.first.second+B.first.second),A.second+B.second);
}

pair<int,int>P[MAXN][MAXN];

pair<pair<int,int > ,int> f(int x,int y,int s =0){
	if(x < 0 || y < 0 || x >= n || y >= m){return make_pair(make_pair(x,y),0);}
	if(dp[x][y].first != make_pair(-1,-1))return dp[x][y];
	stack<pair<int,int> >S,S2;
	S.push(make_pair(x,y));
	S2.push(make_pair(x,y));
	int a = x,b = y;
	
	while(!S.empty()){
		x = S.top().first, y =S.top().second;
		S.pop();
		
		if(x < 0 || y < 0 || x >= n || y >= m)break;
		if(A[x][y] == '0' || A[x][y] == '$')break; 
		if(A[x][y] == 'W' || A[x][y] == '#')break;
		if(dp[x][y].first != make_pair(-1,-1))break;
		int u = x + dx[get(A[x][y])], v = y+dy[get(A[x][y])];
		
		S.push(make_pair(u,v));
		S2.push(make_pair(u,v));
	}
	while(!S2.empty()){
		x = S2.top().first, y = S2.top().second;
		S2.pop();
		if(x < 0 || y < 0 || x >= n || y >= m){continue;}
		if(A[x][y] == '0' || A[x][y] == '$'){dp[x][y] = make_pair(make_pair(x,y),0);continue;}
		if(A[x][y] == 'W' || A[x][y] == '#'){dp[x][y] = make_pair(make_pair(x,y),0);continue;}
		int u = x + dx[get(A[x][y])], v = y+dy[get(A[x][y])];
		pair<pair<int,int>,int >ret;
		if(x < 0 || y < 0 || x >= n || y >= m)ret = make_pair(make_pair(u,v),0);
		else ret = dp[u][v];
		dp[x][y] = ret+ make_pair(make_pair(0,0),1);
	}
	return dp[a][b];
}

pair<pair<int,int > ,int> dfs(int x,int y,int s = 0){
	
	if(x < 0 || y < 0 || x >= n || y >= m)return make_pair(make_pair(x,y),0);
	if(A[x][y] == '0' || A[x][y] == '$')return make_pair(make_pair(x,y),0); 
	if(A[x][y] == 'W' || A[x][y] == '#')return make_pair(make_pair(x,y),0);
	int u = x + dx[get(A[x][y])], v = y+dy[get(A[x][y])];
	
	if(dp[x][y].first != make_pair(-1,-1))return dp[x][y];
	
	return dp[x][y] = dfs(u,v,0) + make_pair(make_pair(0,0),1);
	
}

int dis[150][(1<<10)];

int position[MAXN][MAXN];

void init2(){
	for(int i=0;i<V.size();i++){
		for(int j=0;j<(1<<10);j++)
			dis[i][j] = INF;
	}
}

void pre(){
	int k = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(A[i][j] == '$')
				position[i][j] = k++;
			if(get(A[i][j]) != -1)f(i,j);		
		}
}

int dijkstra(int st,int end){
	init2();
	int ans = -1,ans2 = -1;
	priority_queue<pair<int,pair<int,int> > >Q;
	Q.push(make_pair(0,make_pair(st,0)));
	dis[st][0] = 0;	
	while(!Q.empty()){
		pair<int,pair<int,int> >q = Q.top();
		Q.pop();
		int u = q.second.first, mask = q.second.second;
		if(__builtin_popcount(mask) < ans)continue;
		if( u == end ){
			if(__builtin_popcount(mask) > ans){
				ans = __builtin_popcount(mask);
				ans2 = dis[u][mask];
			}
			else if(__builtin_popcount(mask) == ans){
				ans2 = min(ans2,dis[u][mask]);
			}
		}
		for(int i=0;i<4;i++){
			int nu = V[u].first + dx[i], nv = V[u].second + dy[i];
			if(nu < 0 ||  nv < 0 || nu>=n || nv >=m)continue;
			pair<pair<int,int > ,int> qv = f(nu,nv);
			
			pair<int,int> v = qv.first;
			int dist = qv.second;

			int x = v.first,y = v.second;
			
			if(x < 0 || y < 0 || x>=n || y>=m || A[x][y] == 'W' || A[x][y] == '#')continue;
			
			int posv = lower_bound(V.begin(),V.end(),v) - V.begin();
			if(A[x][y] == '$'){
				
				if(dis[posv][mask |(1<<position[x][y])] > dis[u][mask] + 2 +1+ dist ){
					dis[posv][mask |(1<<position[x][y])] = dis[u][mask] + 2 +1+ dist;
					Q.push(make_pair(-dis[posv][mask | (1<<position[x][y])],make_pair(posv,mask | (1<<position[x][y]))));
				}		
			}	
			if(dis[posv][mask]  > dis[u][mask] + 1+dist){
				dis[posv][mask] = dis[u][mask] + 1+dist;
				Q.push(make_pair(-dis[posv][mask],make_pair(posv,mask)));
			}
		}
	}
	return ans2;
}
	
int main(){
	int x,y,a,b;
	while(scanf("%d%d",&n,&m) == 2){
		init();
		
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				cin>>A[i][j];
				if(A[i][j] == '0' || A[i][j] == '$')
					V.push_back(make_pair(i,j));
			}
		
		pre();
		scanf("%d%d%d%d",&x,&y,&a,&b);
		x--;y--;a--;b--;
		sort(V.begin(),V.end());
		int st = lower_bound(V.begin(),V.end(),make_pair(x,y)) - V.begin();
		int end = lower_bound(V.begin(),V.end(),make_pair(a,b)) - V.begin();
		
		cout<<dijkstra(st,end)<<"\n";		
	}

}
