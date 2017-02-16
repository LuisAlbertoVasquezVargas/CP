#include<iostream>
#include<cstring>

#define MAXN 100000

using namespace std;

int freq[MAXN+1],a[MAXN];
int n,k,cnt,x,y;
int main()
{
     while( cin >> n >> k )     
     {
          for( int i = 0 ; i < n ; ++i )
               cin >> a[i];
          memset(freq,0,sizeof(freq));
          cnt = 0;
          y = -1;
          x = 0;
          for( int i = 0 ; i < n ; ++i )
          {
               if( freq[a[i]] == 0 )
                    cnt++;     
               freq[a[i]]++;                    
               if( cnt == k )
               {
                    y = i;
                    break;
               }
          }
          //8 3
          //1 1 2 2 3 3 4 5
          for( int i = 0 ; i < n  ; ++i )
               if( freq[a[i]] > 1 )
                    x = i + 1,freq[a[i]]--;
               else break;                        
          if( y != -1 )
          {
               cout<<x+1<<" "<<y+1<<endl;     
          }else cout<<"-1 -1\n";
     }
}
