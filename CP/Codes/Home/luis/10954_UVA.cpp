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

using namespace std;

int n,x;

int main()
{
        while( cin >> n )
        {
		if( n == 0 )return 0;
		priority_queue<long long>Q;
	        for( int i = 0 ; i < n ; ++i )
	        {
		        cin >> x;
		        Q.push(-x);
		}
		long long ans = 0;
		while( Q.size() >= 2 )
		{
			long long p = -Q.top();
			Q.pop();
			long long q = -Q.top();
			Q.pop();
			ans += p + q;			
			Q.push(-p-q);
		}
		cout << ans << "\n";
        }
}
