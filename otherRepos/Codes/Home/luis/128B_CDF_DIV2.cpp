#include<iostream>
#include<cstring>
#define MAXN 1000

using namespace std;

int n,m,pos,x,y;
bool in;
int cnt[MAXN][MAXN];
void search()
{
     
     
}
int main()
{
     while( cin >> n >> m )
     {
          pos = -1;
          in = 1;
          memset(cnt,0,sizeof(cnt));          
          for( int k = 0 ; k < m ; ++k )
          {
               cin >> x >> y;
               for( int i = max(0,x-3) ; i < x ; ++i )
                    for( int j = max(0,y-3) ; j < y ; ++j )
                    {
                         cnt[i][j]++;
                         if( cnt[i][j] == 9 && in )
                         {
                              pos = k + 1;
                              in = 0;
                         }
                    }
          }
          cout<<pos<<endl;
     }
}
