#include<stdio.h>
#include<string.h>

int memo[1<<19];
int a[21];

int f(int mask,int des)
{
     int mask2 = mask;
     int i,j,k;
     for( i = 2 ; i <= 20 ; ++i )
          if((mask&(1<<i))==0)
               for( j = i ; j <= 20 ; j+= i )
                    for( k = j ; k <= 20 ; k+= des )
                         if((mask2&(1<<k)))
                              mask2-=(1<<k);

     for( i = des ; i <= 20 ; i+= des )
          if((mask2&(1<<i)))     
               mask2-=(1<<i);          
     return mask2;     
}
int dp( int mask )
{
     if( mask == 0 )return 0;
     if( memo[(mask>>2)] != -1 ) return memo[(mask>>2)];
     int in = 0;
     int i;
     for( i = 2 ; i <= 20 ; ++i )
          if( (mask&(1<<i))!=0 )
               in = (in || (!dp(f(mask,i))));
                     
     return memo[(mask>>2)] = in;
}

int main()
{
     int t;
     scanf("%d", &t);
     memset(memo,-1,sizeof(memo));
     int i,j;
     for( i = 1 ; i <= t ; ++i )
     {
          int mask = 0;
          int n;
          scanf("%d", &n);
          for( j = 0 ; j < n ; ++j )
          {
               scanf("%d", &a[j]);
               mask+=(1<<a[j]);
          }
          int v[21];
          int s = 0;
          for( j = 0 ; j < n ; ++j )                    
               if(!dp(f(mask,a[j])))
                    v[s++] = a[j];
          printf("Scenario #%d:\n",i);
          if( s == 0 )
          {
               puts("There is no winning move.\n");
          }else
          {
               printf("The winning moves are:");
               for( j = 0 ; j < s ; ++j )
                    printf(" %d",v[j]);
               puts(".\n");
          }
     }
}
