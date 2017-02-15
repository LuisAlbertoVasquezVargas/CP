#include<bits/stdc++.h>

using namespace std;

const int MAXN = 26;

inline int toi(char c){
  return c-'a';	
}

vector<int>adj[MAXN];
int in[MAXN];
string s[MAXN+128];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0; i<N; ++i){
    cin>>s[i];
  }
  bool nok = 0;
  memset(in,0,sizeof(in));
  for(int i=0; i<MAXN; ++i)
    adj[i].clear();
  for(int i=0; i<N; ++i){
    for(int j=i+1;j<N;++j){
      for(int x = 0; x<s[i].size();++x){
        if(x == s[j].size()){
		  nok = 1;
		  break;
        }
		if( s[i][x] == s[j][x])continue;
        adj[toi(s[i][x])].push_back(toi(s[j][x]));
        in[toi(s[j][x])]++;
		break;
	  }
	}
  }
  queue<int>Q;
  vector<int>ans;
  for(int i=0; i<MAXN;++i){
    if(in[i] == 0){
	  Q.push(i);
      ans.push_back(i);
      
	}
  }
  
  while(!Q.empty()){
    int u = Q.front();
    Q.pop();
    for(int i=0; i<adj[u].size(); ++i){
      int v = adj[u][i];
      in[v]--;
      if( in[v] == 0){
        Q.push(v);
        ans.push_back(v);
	  }
	}
  }
  
  for(int i=0; i<MAXN; ++i) 
    if(in[i] != 0)
      nok = 1;
  if(nok ||ans.size() !=26){
    puts("Impossible");
  }
  else{
    for(int i=0; i<ans.size(); ++i)
      cout<<char(ans[i]+'a');
  puts("");
  }
  
  
}
