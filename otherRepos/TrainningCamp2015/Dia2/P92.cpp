#include<bits/stdc++.h>

using namespace std;

const int MAXN = 128;

int n , a, b;

vector<int>adj[MAXN];

int dp[MAXN];
bool vis[MAXN];

int f(int node, int p=-1){
  
  vis[node] = 1;
  int ans = 0;
  for(int i=0 ; i< adj[node].size(); ++i){
    int v = adj[node][i];
    if( v !=  p){
      if( vis[node] == 0 ){
	  	ans = max( ans , 1 + f(v,node));
	  }
	  else{
	    if( dp[v] != -1)ans = max(ans, 1 + dp[v]);	
	  }
	}
  }
  return dp[node] = ans;
}

int main(){
  int T;
  scanf("%d",&T);
  while( T-- ){
    scanf("%d",&n);
	for(int i=0;i<(n*(n-1))/2;++i){
	  scanf("%d%d",&a,&b);
	  a--;b--;	
	  adj[a].push_back(b);
	}
	cout<<f(0)<<endl;
	
  }
}
