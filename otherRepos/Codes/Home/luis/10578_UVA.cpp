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

string s;

int sum( vector<int> v )
{
	int cnt = 0;
	for( int i = 0 ; i < 6 ; ++i )
		cnt += (i+1)*v[i];
	return 21*4-cnt;
}
bool f( vector<int> &v )
{
	if( sum(v) > 31 )return 0;
	bool ok = 0;
	for( int i = 0 ; i < 6 ; ++i )
	{
		if( v[i] > 0 )
		{
			v[i]--;
			ok = ok || f(v);
			v[i]++;
		}
	}
	return !ok;
}
int main()
{
     while( getline( cin , s ) )
     {
		vector< int > v(6,4);
		int ns = s.size();
		for( int i = 0 ; i < ns ; ++i )
			v[s[i]-'1']--;
		if( (f(v) + ns )%2 )
			cout << s << " B" << endl;
		else cout << s << " A" << endl;
     }
}
