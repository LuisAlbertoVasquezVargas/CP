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

class PeopleCircle {
public:
	string order(int n, int m, int K) 
	{
		string S(n+m,'M');
		int pos = 0,cont = 0,tot = 0;
		while( 1 )
		{
			if( tot == m )break;
			if( pos == n+m)pos = 0;
			if( S[pos] == 'M' )
				cont ++;
			if( cont == K )
			{
				cont = 0;
				S[pos] = 'F';
				tot++;
			}
			pos++;
		}
		return S;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
