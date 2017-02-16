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

using namespace std;

#define all(v)  v.begin() , v.end()
class GoldenChain {
public:
	int minCuts(vector <int> v ) 
	{
		int ans = 0 , nv = v.size();
		sort( all(v) );
		for( int i = 0 ; i < nv ; ++i )
		{
			if( ans + v[i] <= nv - i - 1 )
				ans += v[i];
			else 
			{
				ans += max( nv - ans - i ,  0);
				break;
			}
		}
		return ans;	
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
