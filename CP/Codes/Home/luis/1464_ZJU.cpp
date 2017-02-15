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

using namespace std;
vector<long long>v;          
long long f(vector<long long> &v ,long long L)
{
     int n = v.size();
     long long s = 0;
     for( int i = 0; i < n ; ++i )
          s+=v[i]/L;
     return s;          
}
int main()
{
     int t;
     cin >> t ;
     for( int k = 0 ; k < t ; ++k )
     {
          long long n,N;
          cin >> n >> N;
          v.clear();
          for( int i = 0 ; i < n ; ++i )
          {
               long long x,y;
               scanf("%lld.%lld",&x,&y);
               v.push_back(x*100+y);
          }
          if( f(v,1) < N )
          {
               if(k!=0)puts("");               
               puts("0.00");
               continue;     
          }

          long long lo = 0; 
          long long hi = 1000000000000000LL;                    
          long long med;
          for(  ; lo + 1 < hi ;  )
          {
               med = lo + (hi -lo )/2;
               if( f(v,med) < N )
                    hi = med ;
               else lo = med;                         
          }
          double ans = lo/100.0;
          if(k!=0)puts("");
          printf("%.2lf\n",ans);
     }       
}
