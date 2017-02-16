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
#define MAXN 1001

using namespace std;

int n,k;
pair<int,int> p[MAXN];
int main()
{

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

     while( cin >> n >> k  )
     {
          for( int i = 0 ; i < n ; ++i )
               cin >> p[i].first, p[i].second = i;
          sort(p,p+n);
          vector<int>v;
          for( int i = n-k ; i < n ; ++i )
          	v.push_back(p[i].second + 1);
          sort(v.begin(),v.end());
		cout<<p[n-k].first<<endl;
		for( int i = 0 ; i < k ; ++i )
			cout<<v[i]<<" ";
		cout<<endl;
	}
}
