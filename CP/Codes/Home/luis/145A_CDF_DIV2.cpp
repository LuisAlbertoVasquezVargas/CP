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
#define MAXN 101

using namespace std;

int n;
string s;
pair<int,int>p[MAXN];
int main()
{

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
     while( cin >> n >> s )
     {
		int dx = n/2;
		for( int i = 0 ; i < dx ; ++i )
			p[i].first = i, p[i].second = i + dx;
		for( int i = 0 ; i < dx ; ++i )
			if( s[p[i].first] == 'R' && s[p[i].second] == 'L' )
				swap(p[i].first,p[i].second);
		for( int i = 0 ; i < dx ; ++i )
			cout << p[i].first + 1 << " " << p[i].second + 1<< endl;
     }
}
