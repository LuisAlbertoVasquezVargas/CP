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

#define MAXN 100000

using namespace std;

int n;
pair< int , int >P[MAXN];

int main()
{
     while( cin >> n )
     {
          for( int i = 0 ; i < n ; ++i )
               cin >> P[i].first >> P[i].second;
          int minix = INT_MAX;
          int maxiy = INT_MIN;
          for( int i = 0 ; i < n ; ++i )
          {
			minix = min( minix , P[i].first );
			maxiy = max( maxiy , P[i].second );	
		}
		bool ok = 0;
          for( int i = 0 ; i < n ; ++i )
			if( minix == P[i].first && maxiy == P[i].second )
			{
				cout << i + 1 << endl;
				ok = 1;
				break;	
			}	
		if( !ok )
			cout << -1 << endl;
     }
}
