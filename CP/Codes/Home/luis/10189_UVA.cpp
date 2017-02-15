#include<iostream>
#include<cstring>

using namespace std;

int m[100][100];
int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};

int main()
{
     int r,c;
     char car;
     bool in = false ;
     int it = 0;
     while(1)
     {
          cin>>r>>c;
          if( r == 0 && c == 0) break ;
          memset(m,0,sizeof(m));
                                        
          if(!in)
               in = true ;
          else cout<<"\n";
                         
          for(int i = 0 ; i < r ; ++i)
               for(int j = 0 ; j < c ; ++j)
               {
                    cin>>car;
                    if(car == '*')
                    {
                         m[i][j]=-1;
                         for(int k = 0 ; k < 8 ; ++k){
                              int ni = i +dx[k];     
                              int nj = j +dy[k];
                              if( ni>= 0 && ni < r && nj >= 0 && nj < c && m[ni][nj]!=-1)
                                   m[ni][nj]++;                                   
                         }                              
                    }
               }
               
          cout<<"Field #"<<++it<<":\n";               
          for(int i = 0 ; i < r ; ++i){
               for(int j = 0 ; j < c ; ++j){
                    if(m[i][j]==-1)cout<<"*";
                    else cout<<m[i][j];     
               }
               cout<<endl;
          }      
     }     
     
}
