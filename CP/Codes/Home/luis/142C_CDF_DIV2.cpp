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
#define MAXN 100
#define MAXM 1000

using namespace std;

int n,m;
string a[MAXN];
int memo[MAXN][MAXM];
int dp( int nivel ,int pos)
{
     if( nivel == n - 1 )return 1;
     if( memo[nivel][pos] != -1 )return memo[nivel][pos];
     int dev = (1<<30);     
     if( a[nivel+1][pos] == '1' )dev = min(dev,1+dp(nivel+1,pos));
     else dev = min(dev,dp(nivel,(pos+1)%n));
     return memo[nivel][pos] = dev;
}
int main()
{
     while( cin >> n >> m )
     {
          for( int i = 0 ; i < n ; ++i )
               cin >> a[i];
          memset(memo,-1,sizeof(memo));
          cout<<dp(0,0)<<endl;
     }
}
