#include<iostream>

using namespace std;
// 011 101 110  B C G
string s[6] = {"BGC","BCG","GBC","GCB","CBG","CGB"};
int v[6][9] = {
     {0,1,1,1,0,1,1,1,0},
     {0,1,1,1,1,0,1,0,1},
     {1,0,1,0,1,1,1,1,0},
     {1,0,1,1,1,0,0,1,1},
     {1,1,0,0,1,1,1,0,1},
     {1,1,0,1,0,1,0,1,1}
     };
int a[9];
int main()
{
     while(cin>>a[0])
     {
          for( int  i = 1 ; i < 9 ; ++i )
               cin>>a[i];
          int mini = (1<<30);               
          string cad;
          for( int  i = 0 ; i < 6 ; ++i )
          {
               int ans = 0;     
               for( int j = 0 ; j < 9 ; ++j )
                    if(v[i][j]) ans+=a[j];
               if(ans < mini )
               {
                    mini = ans;
                    cad = s[i];
               }else if( ans == mini && cad > s[i] )
                    cad = s[i];   
          }
          cout<<cad<<" "<<mini<<endl;
     }
}
