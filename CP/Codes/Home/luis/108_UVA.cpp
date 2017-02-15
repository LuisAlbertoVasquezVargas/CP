#include<cstdio>
#include<algorithm>
#define MAXN 100

using namespace std;

int n;
int a[MAXN][MAXN],s[MAXN+1][MAXN+1],temp[MAXN],dp[MAXN];
int main()
{
     scanf("%d",&n);
     for( int i = 0; i < n ; ++i )
          for( int j = 0 ; j < n ; ++j )
               scanf("%d",&a[i][j]);
               
     for( int i = 0 ; i < n ; ++i )
          for( int j = n - 1 ; j >= 0 ; --j )
               s[i][j] = s[i][j+1] + a[i][j];
     int maxi = -(1<<30);               
     for( int j1 = 0 ; j1 < n ; ++j1 ){
          for(int j2 = j1; j2 < n ; ++j2 )
          {
               for( int i = 0 ; i < n ; ++i)
                    temp[i] = s[i][j1] - s[i][j2+1];
                    
               int ans = dp[0] = temp[0];
               for( int i = 1 ; i < n ; ++i)
               {
                    dp[i] = max( temp[i] ,dp[i - 1]+temp[i]);
                    ans = max ( ans , dp[i]);
               }
               maxi = max ( maxi , ans);
          }
     }
     printf("%d\n",maxi);
}
