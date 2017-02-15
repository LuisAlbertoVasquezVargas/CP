#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#define MAXN 1000

using namespace std;

int n,m;
int a[MAXN];
int main()
{
     while( cin >> m >> n )
     {
          for( int i = 0 ; i < n ; ++i )
               cin >> a[i];
          sort(a,a+n);
          int smini = 0;
          int M = m;
          for( int i = 0 ; (i < n )&&M; ++i )
          {
               if(a[i] < M )
               {
                    smini += a[i]*(a[i]+1)/2;
                    M-=a[i]; 
               }else
               {
                    smini += a[i]*(a[i]+1)/2;
                    smini -= (a[i]-M)*(a[i]-M+1)/2;
                    M = 0;
               }
          }
          M = m;
          int smaxi = 0;
          for( int i = a[n-1] ; (i > 0)&&M ; --i )
          {
               for( int j = n-1 ; (j >= 0)&&M ; --j )
               {
                    if(a[j]>=i)
                    {
                         M--;
                         smaxi += i;
                    }     
               }     
          }
          cout<<smaxi<<" "<<smini<<endl;
     }
}
