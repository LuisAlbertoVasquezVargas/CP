#include<iostream>
#include<algorithm>
#define MAXN 5005

using namespace std;
unsigned long long a[MAXN],b[MAXN],x[MAXN];
unsigned long long n,num,m,j;
bool encont;

int b_search(int pos0,int posf,int T)
{
     int lo = pos0 , hi = posf - 1;     
     
     for( int i = 0 ; i < 15 ; ++i)
     {
          int me = lo + (hi - lo)/2;
          
          if( a[me] < T )   lo = me + 1;          
          else  hi = me;
     }
     if( a[lo] == T) return lo;
     return posf;
}
int main()
{
     while(cin>>n)
     {    
          m=0;
          for(int i = 1 ; i <= n ; ++i)
               cin>>x[i];
          sort(x+1,x+n+1);
                         
          for(int i = 1 ; i <= n ; ++i)
          {
               num = x[i];
               j=1;
               encont=false;
               while(j<=m&&!encont){
                    if(a[j]==num){
                         encont=true;
                         b[j]++;                         
                    } else j++;    
               }
               if(!encont){
                    m++;                    
                    a[m]=num;     
                    b[m]=1;
               }
          }

          unsigned long long s = 0 ;

          for(int k = 3 ; k <=m ;++k)
          {
               unsigned long long bus=a[k];
               int i = 1;
               int j = k-1;
               while(i < j )
               {
                    unsigned long long sum = a[i]+a[j];
                    
                    if( sum == bus ) 
                    {
                         s+=b[i]*b[j]*b[k];
                         i++;j--;
                    }
                    if (sum < bus )
                         i++;
                    if (sum > bus )
                         j--;                                            
               }
          }

          for(int i = 2 ; i <= m ; ++i)
          {
               if( a[i]%2 == 0){
                    int k = b_search(1,i,a[i]/2);
                    if( k != i ){ 
                    unsigned long long l = b[k];                         
                         if(l%2==0)
                              s+=b[i]*(l-1)*(l/2);
                         else s+=b[i]*l*((l-1)/2);
                    }
               }
               
          }
          cout<<s<<endl;
     }
}
