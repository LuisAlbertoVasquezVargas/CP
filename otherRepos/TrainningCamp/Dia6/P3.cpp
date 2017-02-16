#include<bits/stdc++.h>

using namespace std;

const int MAXN = 80005;
const int INF = INT_MAX;

int N , R;

int dp1[MAXN], dp2[MAXN];
int new_cost[MAXN];
vector<pair<int,pair<int,int>  > >adj[MAXN];

int f(int u){
  if(dp1[u] != -1)return dp1[u];
  int ans = 0;
  for(int i=0; i<adj[u].size(); ++i){
    int v = adj[u][i].second.first , cost = adj[u][i].second.second;
    ans = max(ans , cost + f(v));
  }
  return dp1[u] = ans;
}

int g(int u){
  if( u == N-1 )return 0;
  if(dp2[u] != -1)return dp2[u];
  int ans = INF;
  for(int i=0; i<adj[u].size(); ++i){
    int v = adj[u][i].second.first , cost = adj[u][i].second.second;
    ans = min(ans, cost+ f(v));
  }
  return dp2[u] = ans;
}

vector<pair<int,int>  >change_ans;

bool can;
bool vis[MAXN] ;
int changed[MAXN];

void dfs(int u){
  int costo = f(u);
  if( u == N-1)can = 0;
  if(vis[u])return;
  vis[u] = 1;
  
  for(int i=0; i<adj[u].size(); ++i){
    int v = adj[u][i].second.first , cost = adj[u][i].second.second;
	
	if( f(v) == g(v) ){
	  
	  if( costo != f(v) + cost){
		  change_ans.push_back(make_pair(adj[u][i].first+1, costo -f(v)- cost));
		  changed[u] = true;
      }
    }
    else dfs(v);
    if(changed[v] == true)changed[u] = true;
	if(changed[v] == true  && cost + f(v) != f(u)){
	    can = false;
		return;	
	  }
  }
}

int main(){
  int a, b, c , tc = 0;
  while( scanf("%d%d",&N,&R) == 2){
  	if ( N == 0 && R == 0)break;
    printf("Case %d: ",++tc);
	for(int i=0; i<N; ++i)
      adj[i].clear();
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    
	for(int i=0; i<R; ++i){
      scanf("%d%d%d",&a,&b,&c);
      a--;b--;
      
	  adj[a].push_back(make_pair(i,make_pair(b,c)));
	}
	for(int i=N-1;i>=0;--i)
	  f(i) , g(i);
	int ans = 0;
	change_ans.clear();
	memset(vis,0,sizeof(vis));
	memset(changed,0,sizeof(changed));
	can = 1;
	dfs(0);
	sort(change_ans.begin(),change_ans.end());
	set<int>s;
	for(int i=0; i<change_ans.size(); ++i){
	  if(s.count(change_ans[i].first) != 0){
	    can = 0;
	    break;
	  }
	  s.insert(change_ans[i].first);
	}
	
	if( can == 0) puts("No solution");
	else{
	  cout<<change_ans.size()<<" "<<f(0)<<"\n";
	  for(int i=0; i<change_ans.size(); ++i){
		cout<<change_ans[i].first<<" "<<change_ans[i].second<<"\n";
	  }
	}
  }
}
