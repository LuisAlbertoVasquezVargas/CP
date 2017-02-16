#include<cstdio>
#include<cstring>
#define MAXN 1025

using namespace std;

int t[MAXN][MAXN],s[MAXN][MAXN],ans[MAXN][MAXN];

int main()
{
     int p;
     scanf("%d",&p);          
     for( int k = 0 ; k < p ; ++k )
     {
          int d,n;
          scanf("%d%d",&d,&n);
          memset(t,0,sizeof(t));
          for(int i = 0 ; i < n ; ++i )
          {
               int x,y,val;
               scanf("%d%d%d",&x,&y,&val);               
               t[x][y] = val;                                             
          }
          for( int  i = MAXN-1 ; i >= 0 ; --i )
               for( int j = MAXN-1 ; j >= 0 ; --j )
                    s[i][j] = t[i][j] + s[i+1][j] + s[i][j+1] - s[i+1][j+1];
          int maxi = 0;
          int posx = 0;
          int posy = 0;
          int D = 2*d +1;
          for( int  i = MAXN-1 ; i >= 0 ; --i )
               for( int j = MAXN-1 ; j >= 0 ; --j )
               {
                    ans[i][j] = s[i][j] - s[i+D][j] - s[i][j+D] + s[i+D][j+D];
                    if(ans[i][j] >= maxi )
                    {
                         maxi = ans[i][j];
                         posx = i;
                         posy = j;   
                    }
               }
          printf("%d %d %d\n",posx+d,posy+d,maxi);
     }
}
