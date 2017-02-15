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
#define MAXN 300

using namespace std;

int n;
string s;
int a[MAXN];
int main()
{
     while( cin >> s )
     {
		memset(a,0,sizeof(a));
		n = s.size();
          for( int i = 0 ; i < n ; ++i )
          	a[s[i]] = 1;
          int cnt = 0;
          for( int i = 0 ; i < MAXN ; ++i )
          	cnt += a[i];
		if( cnt % 2 == 0 )
			puts("CHAT WITH HER!");
		else puts("IGNORE HIM!");
     }
}
