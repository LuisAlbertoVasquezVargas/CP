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
#define MAXN 100000

using namespace std;

vector<pair<int , int> >v;

int main()
{
     int n,m;
     cin>>n>>m;
     
     for( int i = 1 ; i <= m ; ++i)
     {
          v.push_back(make_pair(abs((m+1)/2-i),i));                         
     }
     sort(v.begin(),v.end()); 
     for( int i = 0 ; i < m ; ++i)
          cout<<v[i].first<<" "<<v[i].second<<endl;
                        
}
