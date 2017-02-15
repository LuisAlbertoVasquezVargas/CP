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

#define N 100005
#define MOD 1000000007

using namespace std;

int n;
pair<int ,int> P[N];

int main()
{
	while( sc( n ) == 1 )
	{
		for( int i = 0 ; i < n ; ++i )
			sc( P[i].first ) , P[i].second = i;
		sort( P , P + n );
		vector< int >v , w ;
		for( int i = 0 ; i < n ; ++i )
			if( i%2 )
				w.push_back( P[i].second + 1 );
			else	v.push_back( P[i].second + 1 );
		int nv = v.size() , nw = w.size() ;
		printf( "%d\n" , nv );
		for( int i = 0 ; i < nv ; ++i )
			printf( "%d%s" , v[i] , (i==nv-1)?"\n":" " );
		printf( "%d\n" , nw );
		for( int i = 0 ; i < nw ; ++i )
			printf( "%d%s" , w[i] , (i==nw-1)?"\n":" " );
	}
}
