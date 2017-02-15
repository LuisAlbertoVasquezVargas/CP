#include<bits/stdc++.h>

using namespace std;

const int MAXN = 16;

vector<char>adj[MAXN];
int k;
char A[MAXN][MAXN] , B[MAXN][MAXN];
string ans ="";
string ax;


void dfs(int node){
  if( node == 5 ){
    k--;
    if( k == 0 )ans = ax;
  }
  else{
    for(int i=0; i<adj[node].size(); ++i){
	  ax[node] = adj[node][i];
	  dfs(node+1);
	}	
  }
}

int main(){
  int T;
  scanf("%d",&T);
  ax = "00000";
  while( T-- ){
    scanf("%d",&k);
    ans = "NO";
    for(int i=0; i<6; ++i){
      for(int j=0; j<5; ++j)
        cin>>A[i][j];
      adj[i].clear();
	}
	for(int i=0; i<6; ++i)
      for(int j=0; j<5; ++j)
        cin>>B[i][j];
	
	
	char c;
	for(int i=0; i<5; ++i){
	  for(int j=0;j<6;++j){
	    c = A[j][i];	    
	    for(int r=0; r<6;++r){
	      if( c == B[r][i] ){
		    adj[i].push_back(c);	
		  }
	    }
	  }
      sort(adj[i].begin(),adj[i].end());
	}
	
	dfs(0);
	
	cout<<ans<<"\n";
  }
}
