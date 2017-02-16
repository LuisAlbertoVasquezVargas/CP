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

int n;
string S;

int toi(string s){istringstream is(s);int x;is>>x;return x;}

bool is_number( int lo , int hi )
{
	for( int i = lo ; i <= hi ; ++i )
		if( !isdigit(S[i]) )
			return 0;
	return 1;	
}
int f( int lo , int hi )
{
	if( is_number(lo,hi) )
		return toi(S.substr(lo,hi-lo+1));
	int cnt = 0;
	for( int i = hi ; i > lo ; --i )
	{
		if( S[i] == '(' )
			cnt--;
		if( S[i] == ')' )
			cnt++;
		if( cnt == 0 && i > 1 )
		{
			int dev1 = f(lo,i-2);
			int dev2 = f(i,hi);

			if( S[i-1] == '*' )
				return dev1*dev2;
			if( S[i-1] == '+' )
				return dev1+dev2;
			if( S[i-1] == '-' )
				return dev1-dev2;
		}
	}
	return f(lo+1,hi-1);
}
int main()
{
     while( cin >> S )
	{
		n = S.size();
		cout << f(0,n-1) << endl;	
	}
}
