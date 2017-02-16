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
#define MAXN 100001


using namespace std;

long long n,m,x,y;
long long a[MAXN],f[MAXN];
map<long long,long>acum;
int main()
{
     while( cin >> n >> m )
     {
          acum.clear();
          memset(f,0,sizeof(f));
          for( int i = 1 ; i <= n ; ++i )
          {
               cin >> a[i];
               acum[a[i]]++;
               if(acum[a[i]] == a[i])
                    f[i] = f[i-1]+1;
               else f[i] = f[i-1];
          }
          for( int i = 1 ; i <= m ; ++i )
          {
               cin >> x >> y;
               cout<<f[y]-f[x-1]<<endl;
          }
     }
}

