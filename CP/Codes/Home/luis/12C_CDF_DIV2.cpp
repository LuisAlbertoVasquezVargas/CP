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
#define MAXN 100

using namespace std;

int n,m;
int a[MAXN];
int b[MAXN];
map<string,int>M;
string s;

int main()
{
     while( cin >> n >> m )
     {
		M.clear();
		
          for( int i = 0 ; i < n ; ++i )
               cin >> a[i];
          for( int i = 0 ; i < m ; ++i )
          	cin >> s ,M[s]++;
          	
          m = 0;
		map<string,int>::iterator it;
		for( it = M.begin() ; it != M.end() ; ++it )
			b[m++] = (*it).second;

          sort(a,a+n);			
		sort(b,b+m);
		int best = 0, worst = 0;
		for( int i = 0 ; i < m ; ++i )
			best += a[i]*b[m-1-i];
		for( int i = 0 ; i < m ; ++i )
			worst += a[n-1-i]*b[m-1-i];
		cout<<best<<" "<<worst<<endl;
     }
}
