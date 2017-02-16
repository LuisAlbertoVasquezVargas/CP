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

using namespace std;

long long n , d , a , b , x ,y ;
pair< long long , long long >P[MAXN];

int main()
{
        while( cin >> n >> d >> a >> b )
        {
	        for( long long i = 0 ; i < n ; ++i )
		{
			cin >> x >> y ;
			P[i] = make_pair( a*x + b*y , i );	
		}
		sort( P , P + n );
		long long sum = 0;
		vector< long long >ans;
		for( int i = 0 ; i < n ; ++i )
			if( sum + P[i].first <= d )
			{
				sum += P[i].first;
				ans.push_back( P[i].second + 1 );
			}
			else break;
		long long nAns = ans.size();
		cout << nAns << endl;
		for( long long i = 0 ; i < nAns ; ++i )
			cout << ans[i] << " ";
		cout << endl;
        }
}
