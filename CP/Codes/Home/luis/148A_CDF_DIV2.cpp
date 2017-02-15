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

int y,k,n;
vector<int>v;
int main()
{
     while( cin >> y >> k >> n )
     {
		v.clear();
		for( int i = y/k + 1 ; i <= n/k ; ++i )
			v.push_back( i*k - y );
		int nv = v.size();
		if( nv == 0 )
		{
			cout << -1 <<endl;
			continue;
		}
		for( int i = 0 ; i < nv ; ++i )
			cout << v[i] << " ";
	}
}
