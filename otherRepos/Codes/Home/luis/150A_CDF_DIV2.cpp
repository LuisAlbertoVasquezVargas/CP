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

#define MAXN1 30*30
#define MAXN2 30

using namespace std;

int n,x,k;
int a[MAXN1];
int main()
{
     while( cin >> n >> k )
     {
		memset( a, -1 ,sizeof(a) );
          for( int i = 0 ; i < k ; ++i )
               cin >> x ,a[x-1] = i;
          int it = 0,cnt = 0;
          for( int j = 0 ;  j < n*k ; ++j )
          {
			if( a[j] != -1 )
				continue;
			if( cnt == n - 1)
			{
				cnt = 0;
				it++;	
			}
			a[j] = it;
			cnt++;
		}
		vector< int >v[MAXN2];
		for( int i = 0 ;  i < n*k ; ++i )
			v[a[i]].push_back(i+1);
		for( int i = 0 ; i < k ; ++i )
		{
			for( int j = 0 ; j < n ; ++j )
				cout << v[i][j] << " ";
			cout << endl;
		}
     }
}
