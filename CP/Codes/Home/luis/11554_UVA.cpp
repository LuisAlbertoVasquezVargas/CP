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

long long n , tc;

int main()
{
	cin >> tc;
	while( tc -- )
	{
		cin >> n;
		long long ans ; 
		if( n%2 == 0 )
			ans = n*(n-2)*(2*n-5);
		else	ans = (n-1)*(n-3)*(2*n-1);
		ans/=24;	
		cout << ans << endl;	
	}
}
