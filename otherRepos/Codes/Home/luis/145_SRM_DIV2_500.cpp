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


class ExerciseMachine {
public:
	int getPercentages(string S) 
	{
		S[2] = S[5] = ' ';
		istringstream in(S);
		int h,m,s;
		in >> h >> m >> s;
		int u = h*3600 + 60*m + s , cnt = 0;
		for( int i = 1 ; i < 100 ; i++ )
			if( (u*i)%100 == 0 )
				cnt ++ ;
		return cnt;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
