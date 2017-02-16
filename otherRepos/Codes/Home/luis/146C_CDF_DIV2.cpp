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
#define MAXN 100000
#define dt 50

using namespace std;

int n;

long long gcd(long long a, long long b)
{
	if( b == 0 )return a;
	return gcd(b,a%b);
}
long long lcm(long long a, long long b)
{
	return a / gcd(a,b)*b;	
}
long long LCM(long long a , long long b , long long c )
{
	return lcm(a,lcm(b,c));	
}
int main()
{
     while( cin >> n )
     {
		long long maxi = LLONG_MIN;
		for( int i = max(1,n - dt) ; i <= n ; ++i )
			for( int j = i ; j <= n ; ++j )
				for( int k = j ; k <= n ; ++k )
					maxi = max(maxi,LCM(i,j,k));
		cout<<maxi<<endl;
     }
}
