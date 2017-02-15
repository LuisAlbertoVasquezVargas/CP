#include<bits/stdc++.h>

using namespace std;

const int MAXN =32;

int n , A[MAXN][MAXN];

long long dp[(1<<20)];

long long f(int mask){
  int num_p = __builtin_popcount(mask);
  if( num_p == n )return 1LL;
  
  long long ans = 0LL;
  if( dp[mask] != -1LL)return dp[mask];
  for(int i=0; i<n; ++i){
    if(((mask>>i)&1) == 0)
	  if( A[num_p][i] == 1 )
        ans += f(mask | (1<<i));
  }
  return dp[mask] = ans;
}

int main(){
  int c;
  scanf("%d",&c);
  while( c-- ){
    scanf("%d",&n);
    for(int i=0; i<n; ++i)
      for(int j=0; j<n; ++j){
        scanf("%d",&A[i][j]);
      }
    memset(dp,-1LL,sizeof(dp));
    cout<<f(0)<<"\n";
	
	
	
  }
}
