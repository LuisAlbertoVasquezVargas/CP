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

#define inf (1<<30)
#define eps 1e-5
#define ll long long
#define all(v)  v.begin() , v.end()
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define test puts("test");

#define N 100005
#define MOD 1000000007

using namespace std;

int n;

int main()
{
	while( cin >> n )
	{
		vector< int >v(n+1),T(n+2);
		v[n] = 10;
		for( int i = 0 ; i < n ; ++i )
			cin >> v[i];
		sort( all(v) );
		T[0] = 0;
		for( int i = 0 ; i <=n ; ++i )
			T[i+1] = T[i] + v[i];
		int pos = upper_bound( all(T) , 360*2 ) - T.begin();
		int time = 0;
		for( int i = 0 ; i <= pos - 1 ; ++i )
			if( T[i] >= 360 )
				time += T[i] - 360 ;
		cout << pos - 2 << " " << time << endl; 
	}
}
