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
#include <climits>
#include <cctype>
#define MAXN 1000001

using namespace std;

int n,tc;
pair<int,int> p[MAXN];
int main()
{
	cin >> tc;
     while(tc--)
     {
		cin >> n;
          for( int i = 0 ; i < n ; ++i )
               cin >> p[i].second >> p[i].first;
          sort(p,p+n);
          for( int i = 0 ; i < n ; ++i )
          	swap( p[i].second,p[i].first);
          int cnt = 0;
          int hi = -1;
          for( int i = 0 ; i < n ; ++i )
			if( p[i].first >= hi )
			{
				hi = p[i].second;
				cnt++;
			}
		cout<<cnt<<endl;
     }
}
