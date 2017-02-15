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

#define N 100005
#define MOD 1000000007

#define inf (1<<30)
#define eps 1e-5
#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define test puts("test");

using namespace std;

int main()
{
	int n;
	while( cin >> n )
	{
		vector<int>v[3];
		for( int i = 0 ; i < n ; ++i )
		{
			int x;
			cin >> x;
			if( x < 0 )v[0].push_back(x);
			else if( x > 0 )v[1].push_back(x);
			else v[2].push_back(x);
		}	
		if( v[1].empty() )
		{
			v[1].push_back(v[0][0]);
			v[1].push_back(v[0][1]);
			v[0].erase(v[0].begin());
			v[0].erase(v[0].begin());
		}
		if( v[0].size() % 2 == 0 )
		{
			v[2].push_back(v[0][0]);
			v[0].erase(v[0].begin());
		}
		for( int i = 0 ; i < 3 ; ++i )
		{
			cout << v[i].size() << " ";
			for( int j = 0 ; j < v[i].size() ; ++j )
				cout << v[i][j] <<(j +1== v[i].size() ?"\n":" ");	
		}
	}
}
