#include<bits/stdc++.h>

using namespace std;

const int MAXN = 128;

string s;

int dp[MAXN][10][3];

bool f(int pos, int div, bool ini){
  if( pos == s.size() ){
    return (ini == true && div == 0);
  }
  if( dp[pos][div][ini] != -1)return dp[pos][div][ini];
  bool ans = 0;
  ans = f(pos+1,(div*10 + (s[pos]-'0'))%8,1) || f(pos+1,(div),ini);
  return dp[pos][div][ini] = ans;
}

void reco(int pos,int div, bool ini){
  if( pos == s.size())return;
  
  if( f(pos+1,(div*10 + (s[pos]-'0'))%8,1) ){
    cout<<s[pos];
	reco(pos+1,(div*10 + (s[pos]-'0'))%8,1);
  }
  else{
    reco(pos+1,(div),ini);
  }
  
}

int main(){
  cin>>s;
  memset(dp,-1,sizeof(dp));
  if( f(0,0,0) ){
    puts("YES");
    reco(0,0,0);
    puts("");
  }
  else{
    puts("NO");
  }
}
