#include<iostream>
#include<vector>
#include<cstring>
#define MAXN 100
#define INF 9999999
using namespace std;
bool adj[MAXN+1][MAXN+1];
int a[MAXN+1];
int main(){
     
     int n,m;
     cin>>n>>m;     
     
     for(int i = 1 ; i <= n ; ++i)
          cin>>a[i];
          
     memset(adj,0,sizeof(adj));
     int u,v;
     
     for(int j = 0 ; j < m ; ++j){
          
          cin>>u>>v;
          
          adj[u][v]=true;
          adj[v][u]=true;
          
     }
              
     int mini=INF;

     for(int i = 0 ; i <=n ;++i )
          for(int j = 0 ; j <=n ; ++j)
               for(int k = 0 ;k <=n ;++k){
                    
                    bool x=adj[i][j];
                    bool y=adj[i][k];
                    bool z=adj[j][k];
                    
                    if(x&&y&&z)
                         mini=min(mini,a[i]+a[j]+a[k]);
                    
               }               
     

     
     if(mini==INF)
          cout<<"-1";
     else          
          cout<<mini;
     
}
