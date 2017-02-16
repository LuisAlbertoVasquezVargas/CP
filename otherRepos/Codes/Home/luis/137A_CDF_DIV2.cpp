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
#include <cstdlib>
#include <cassert>
#define MAXN 1000

using namespace std;

int n,m,k;
int a[MAXN][MAXN];
int main()
{
     while( cin >> n >> m >> k )
     {
          for( int i = 0 ; i < n ; ++i )
               for( int j = 0 ; j < m ; ++j )
                    cin >> a[i][j];
          int x = a[n-1];
          int j = n-1;
          while(j>=0&&x==a[j])
               j--;
          if( j >= k - 1 )
               cout<<-1<<endl;
          else cout<<j+1<<endl;
     }
}
