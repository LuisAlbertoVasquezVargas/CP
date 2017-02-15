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
vector< int > a(3) ,x(3),b(3),vis;

void doit()
{
	for( int k = 1 ; k <= 52 ; ++k )
		if( !vis[k] )
		{
			b = x;
			b[2] = k;				
			sort( a.begin() , a.end() );
			int mini = 10;
			do
			{
				int cnt = 0;
				for( int i = 0 ; i < 3 ; ++i )
					if( b[i] > a[i] )
						cnt++;
				mini = min( mini , cnt );
			}while( next_permutation( a.begin() , a.end() ) );
			if( mini >= 2 )
			{
				cout << k << endl;
				return;	
			}
		}	
	puts("-1");
}
int main()
{
        while( cin >> a[0] >> a[1] >> a[2] >> x[0] >> x[1] )
        {
			if( a[0] == 0 )break;
			x[2] = 0;
			vis = vector< int >(53,0);
			for( int i = 0 ; i < 3 ; ++i )
				vis[a[i]] = vis[x[i]] = 1;
			doit();
        }
}
