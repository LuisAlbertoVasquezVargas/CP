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
#define MAXN 10000

using namespace std;

int n;
long long s;
pair<int,int> p[MAXN];
int main()
{
     while( cin >> s >> n )
     {
          for( int i = 0 ; i < n ; ++i )
               cin >> p[i].first >> p[i].second ;
              sort(p,p+n);
          bool ok = 1;
          for( int i = 0 ; i < n ; ++i )
          {
               if( s > p[i].first )
               {
                    s+=p[i].second;     
               }else
               {
                    ok = 0;
                    break;     
               }
          }
          if( ok ) cout<<"YES"<<endl;
          else cout<<"NO"<<endl;
     }
}
