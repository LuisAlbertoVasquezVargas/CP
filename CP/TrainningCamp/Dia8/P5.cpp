#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1024;
const int INF = (1<<29);

string s;
int dif[MAXN] , n , dp[MAXN]; 
int down[MAXN], up[MAXN];

int num_sw(char c){
  return min(c-'a',26-(c-'a'));
}

int get_sw(char c,int nsw){
  int x = num_sw(c);
  if( nsw > 0 )return x;
  return x + nsw;
}


int f(int pos){
  
  if( pos == s.size()){
	return 0;
  }
  if(dp[pos] != -1) return dp[pos];
  int ans = INF;
  ans = min(ans, num_sw(s[pos]) + f(pos+1) );
  int u = 0 , d = 0;
  for(int i=pos; i<n; ++i){
    if(u + up[i] < 26)u += up[i];
    if(d + down[i] < 26)d += down[i];
    if(u <= 13)ans = min( ans , u+get_sw(s[pos],-u) +  f(i+2) );
    if(d <= 13)ans = min( ans , d+get_sw(s[pos],d) +  f(i+2) );
  }
  return dp[pos] = ans;
}

int main(){
  while( cin>>s ){
	  if( s == "*" )break;
	  memset(dp,-1,sizeof(dp));
	  n = s.size() - 1;
	  
	  for(int i=0; i<int(s.size())-1; ++i){
	    if( s[i+1] > s[i] )down[i] = s[i+1] - s[i];
	    else down[i] = 26 - (s[i] - s[i+1]) ;
	    up[i] = 26-down[i];
	  }
	  cout<<f(0)<<endl;
  }
}
