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

vector < pair <int, int> > primeFact(int N)
{
	vector < pair <int, int> > V;
	
	for(int i=2; i*i<=N; i++)
	{
		int a=0;
		while(N%i==0)
		{
			N/=i;
			a++;
		}
		if(a!=0) V.push_back(make_pair(i, a));
	}
	if(N>1) V.push_back(make_pair(N, 1));
	
	return V;
}
int n;
int main()
{
     while( cin >> n )
	{
		vector < pair <int, int> >v = primeFact(n);
		if( n%3 == 0 )
		{
			cout << 2 << endl;	
		}
		else if( n%4 == 0 )
		{
			cout << 3 << endl;
		}
		else if( v[0].first == 2 )
		{
			cout << v[1].first - 1 << endl; 	
		}
		else{
			cout << v[0].first - 1 << endl; 				
		}
	}
}
