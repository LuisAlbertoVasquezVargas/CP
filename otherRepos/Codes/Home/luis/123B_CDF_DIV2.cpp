#include<iostream>
#define MAXN 100001
using namespace std;
int n,m;
int a[MAXN];
int b[MAXN];
int main()
{
     while( cin >> n >> m )
     {
          int k = 1;
          if( m%2 != 0)
               a[(m+1)/2] = k++;
          for( int i = m/2 ; i >= 1 ; --i )
               a[i] = k++,a[m-i+1] = k++;
          for( int i = 1 ; i <= m ; ++i )
               b[a[i]] = i;
          for( int i = 1 ; i <= n/m ; ++i )
               for( int j = 1 ; j <= m ; ++j )
                    cout<<b[j]<<endl;
          for( int i = 1 ; i <= n%m ; ++i )                    
               if(a[b[i]]<=n)
                    cout<<b[i]<<endl;          
     }
}
