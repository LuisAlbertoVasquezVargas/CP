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

int n,tc;
string s[] = {"North","East","South","West"};

int main()
{
	cin >> tc ;
     while( tc-- )
     {
		cin >> n;
		int i = 0,pos = 1,add = 0;
		while( 1 )
		{
			if( i + pos <= n )
				i+=pos;
			else break;
			if( i + pos <= n )
				i+=pos;
			else 
			{
				add = 1;
				break;			
			}
			pos++;	
		}
		pos--;
//		cout << pos*2+add <<endl;
		cout << s[(pos*2+add)%4] << endl;
     }
}
