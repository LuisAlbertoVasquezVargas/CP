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
#define MAXN 1000000

using namespace std;

 
long long a[MAXN];
long long v[10];
long long n;
void pre()
{
     long long N = n;
     memset(v,0,sizeof(v));
     while( N > 0 )
     {
          v[N%10] = 1;
          N/=10;
     }

}
bool is_digit(long long d)
{
     bool ok = 0;
     while( d > 0 )
     {
          if(v[d%10]) ok = 1;
          d/=10;     
     }
     return ok;
}
int main()
{
        while( cin>> n )
        {
                long long l = 0 ;
                long long d = 1;
                while( d*d <= n )
                {
                        if( n%d == 0 )
                        {
                                a[l]=d; 
                                a[l+1]=n/d;     
                                l+=2;
                        }
                         d++;
                }
                pre();
                sort(a,a+l);
                l = unique(a,a+l)-a;
                long long cont = 0 ;
                for( int i = 0 ; i < l ; ++i )
                    if(is_digit(a[i]))
                         cont++;
                cout<<cont<<endl;
        }       
}
 

