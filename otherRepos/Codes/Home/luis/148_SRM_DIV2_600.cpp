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


class CeyKaps {
public:
	string decipher(string s, vector <string> v ) 
	{
		string T = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		for( int i = 0 ; i < v.size() ; ++i )
			swap(T[v[i][0]-'A'],T[v[i][2]-'A']);
		map< char , char >M;
		for( int i = 0 ; i < T.size() ; ++i )
			M[ T[i] ] = 'A'+i;
		for( int i = 0; i < s.size() ; ++i )
			s[i] = M[s[i]];
		return s;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
