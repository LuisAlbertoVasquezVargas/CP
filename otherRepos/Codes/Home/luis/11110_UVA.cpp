#include<iostream>
#include<algorithm>
#include<sstream>
#include<cstring>
#include<queue>
#define MAXN 100
 
using namespace std;
 
int n,x,y,time_;
int G[MAXN][MAXN];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
bool vis[MAXN][MAXN],ok;
string s;


void dfs(int i, int j,int group){
     if(G[i][j]!=group)
          return ;
     if(i<0||i>=n||j<0||j>=n)
          return;
     if(vis[i][j])
          return;          
     vis[i][j]=true;
     time_++;
     for( int k = 0 ;  k < 4 ; ++k )
          dfs(i+dx[k],j+dy[k],group);
          
} 
int main(){
    
    while( cin >> n )
    {
        if( n == 0 ) break;
        getline(cin,s);
        memset(G,0,sizeof(G));        
        memset(vis,0,sizeof(vis));
        ok=true;        
        for( int i = 1 ; i < n ; ++i)
	   {
            getline(cin,s);
            istringstream in(s);
            while(in>>x>>y)
               G[x-1][y-1]=i;
        }
        for( int i = 0 ; i < n ; ++i)
          for( int j = 0 ; j < n ; ++j)
		{
               time_ = 0;
               if(!vis[i][j])
			{
                    dfs(i,j,G[i][j]);
                    if(time_ != n )
                         ok=false;                    
               }
          }                                        
        if(ok)
            cout<<"good\n";
        else
            cout<<"wrong\n";          
    }
}
