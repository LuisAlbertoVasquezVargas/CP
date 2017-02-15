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


class BigBurger {
public:
	int maxWait(vector <int> u, vector <int> v) {
		int n = v.size();
		int maxi = 0 , t = u[0] + v[0];
		for( int i = 1 ; i < n ; ++i )
		{
			maxi = max( maxi , max( 0 , t - u[i] ) );
			t = max( t , u[i] ) + v[i];
		}
		return maxi;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
