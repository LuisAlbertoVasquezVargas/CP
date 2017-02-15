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

#define MAXN 10000000000000LL

using namespace std;

vector < pair <long long, long long> > primeFact(long long N)
{
	vector < pair <long long, long long> > V;
	
	for(long long i=2; i*i<=N; i++)
	{
		long long a=0;
		while(N%i==0)
		{
			N/=i;
			a++;
		}
		if(a!=0) V.push_back(make_pair(a, i));
	}
	if(N>1) V.push_back(make_pair(1, N));
	
	return V;
}

long long n;
int main()
{
     while( cin >> n )
     {
		vector < pair <long long, long long> > v = primeFact(n);
		if( n == 1 || ( v.size() == 1 && v[0].first == 1 ) )
		{
			cout << 1 << endl;
			cout << 0 << endl;
			continue;
		}
		sort(v.rbegin(),v.rend());
		if( v.size() == 1 && v[0].first > 2 )
		{
			cout << 1 << endl;
			cout << v[0].second*v[0].second << endl;	
		}
		else if( v.size() > 2 || ( v.size() == 2 && v[0].first + v[1].first > 2 ) )
		{
			cout << 1 << endl;	
			cout << v[0].second*v[1].second << endl;
		}else
		{
			cout << 2 << endl;	
		}
     }
}
