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

#define vi vector<int> 
#define all(v) v.begin() , v.end() 
#define rall(v) v.rbegin() , v.rend() 
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)

using namespace std;

int m;
int main()
{
	while( cin >> m )
	{
		vi v(m);
		for( int i = 0 ; i < m ; ++i )cin >> v[i];
		sort( rall(v) );
		long long sum = 0 ;
		for( int i = 0 ; (1<<i)*(1<<i) <= m ; ++i )
		{
			int tam = (1<<i)*(1<<i);
			for( int j = 0 ; j < tam ; ++j )
				sum += v[j];
		}
		cout << sum << endl;
	}
}
