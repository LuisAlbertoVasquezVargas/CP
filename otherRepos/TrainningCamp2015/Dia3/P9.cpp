#include<bits/stdc++.h>

using namespace std;


#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())


const int MAXN = 2024;
const int MAXD = 23;
const int INF = (1<<28);

int n , d;
int a[MAXN];
int dp[MAXN][MAXD][MAXD];
bool vis[MAXN][MAXD][MAXD];

int g(int x){
  if( x < 5) return -x;
  return 10-x;
}

int f(int pos,int div, int lleva){ 
  if( pos == n ){
    return g(lleva);
  }
  if(vis[pos][div][lleva])return dp[pos][div][lleva];
  vis[pos][div][lleva] = 1;
  int ans = INF;
  if( div < d ){
    ans = min(ans, g(lleva) + f(pos+1,div+1,a[pos]%10));
  }
  ans = min(ans,f(pos+1,div,((lleva + a[pos]%10))%10));
  return dp[pos][div][lleva] = ans;
}


int main(){
  while( scanf("%d%d",&n,&d) == 2){
    int sum = 0;
	for(int i=0; i<n; ++i)
	  scanf("%d",&a[i]) , sum += a[i];
	  memset(vis,0,sizeof(vis));
	  cout<<sum + f(0,0,0)<<"\n";
  }
  
}
