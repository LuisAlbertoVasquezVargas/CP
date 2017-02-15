#include<iostream>
#include<cstring>
#include<queue>
#define MAXN 30

using namespace std;

bool B[MAXN*MAXN*MAXN];
bool vis[MAXN*MAXN*MAXN];

int D[MAXN*MAXN*MAXN];
int L=MAXN,R=MAXN,C=MAXN;

int dx[]={-1,1,0,0,0,0};
int dy[]={0,0,-1,1,0,0};
int dz[]={0,0,0,0,-1,1};

queue<int>Q;

int main()
{
     int l,r,c,id0,idf;
     char car;
     while(1)
     {
          cin>>l>>r>>c;
          if(l == 0 && r == 0 && c == 0) break ;
          
          memset(B,false,sizeof(B));
          memset(vis,false,sizeof(vis));          
          memset(D,-1,sizeof(D));  
                  
          for ( int k = 0 ; k < l ; ++k)
               for( int  i = 0 ; i < r ; ++i)
                    for( int j = 0 ; j < c ; ++j){
                         cin>>car;
                         if(car == 'S')                              
                              id0 = i*c*l+j*l+k;
                         if(car == 'E')                                                            
                              idf = i*c*l+j*l+k;
                         if(car == '#')
                              B[i*c*l+j*l+k]=true;                              
                    }
          Q.push(id0);          
          vis[id0] = true;                                                       
          D[id0] = 0;
          
          while(!Q.empty())
          {
               int id = Q.front();
               Q.pop();
               
               int x = id /(c*l);
               int y = (id %(c*l)/l);
               int z = id%l;                              

               for( int k = 0 ; k < 6 ; ++k)
               {
                    int nx = x + dx[k];                                             
                    int ny = y + dy[k];
                    int nz = z + dz[k]; 
                    int nid = nx*c*l + ny*l + nz;

                    if(nx>=0&&nx<r&&ny>=0&&ny<c&&nz>=0&&nz<l&&!vis[nid]&&!B[nid])
                    {
                         Q.push(nid);                                                  
                         vis[nid] = true;
                         D[nid] = D[id] + 1;
                    }
               }
          }
          if(D[idf] != -1) cout<<"Escaped in "<<D[idf]<<" minute(s).\n";
          else cout<<"Trapped!\n";
     }     
}
