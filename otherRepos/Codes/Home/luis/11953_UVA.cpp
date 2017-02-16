#include<iostream>
#include<cstring>
#define MAXN 100
 
using namespace std;
 
int t,n;
int cont,contx,conta;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool vis[MAXN][MAXN];
char c[MAXN][MAXN];
void dfs(int i,int j)
{
 
    if( i < 0 || i >= n )  return;
    if( j < 0 || j >= n )  return;    
    if(vis[i][j]) return;
    else 
    {
        vis[i][j] = 1;
        if(c[i][j]=='.')
        {
            vis[i][j] = 1;
            return;
        }
        if(c[i][j]=='x')    contx++;
        if(c[i][j]=='@')    conta++;
        for(int k = 0 ; k < 4 ; ++k )
            dfs(i+dx[k],j+dy[k]);        
    }  
}
int main()
{
    cin >> t;
    for( int k = 0 ; k < t ; ++k )
    {
        cin >> n ;
        for( int i = 0 ; i < n ; ++i )
            for( int j = 0; j < n ; ++j )
                cin >> c[i][j];
        memset(vis,0,sizeof(vis));                
        cont = 0;
        for( int i = 0 ; i < n ; ++i )
            for( int j = 0; j < n ; ++j )
                if(!vis[i][j])
                {
                    contx = conta = 0;
                    dfs(i,j);
                    if(contx > 0 ) cont++;
                }
        cout<<"Case "<<k+1<<": "<<cont<<endl;                
    }
    
}
 
