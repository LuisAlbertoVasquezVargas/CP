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

#define all(v)  v.begin() , v.end()

using namespace std;

int n , k;
int main()
{
	while( cin >> n >> k )
	{
		vector< int >v(n);
		for( int i = 0 ; i < n ; ++i )
			cin >> v[i];
		if( k == 1 )
		{
			cout << n << endl;
			continue;	
		}
		sort( all(v) );
		set< int >S;
		int ans = 0;
		for( int i = 0 ; i < n ; ++i )
		{
			int u = v[i];
			if( u%k == 0 && S.find(u/k) == S.end() || ( u%k ) )
				S.insert( u ) ,ans++;
		}
		cout << ans << endl;
	}
}
