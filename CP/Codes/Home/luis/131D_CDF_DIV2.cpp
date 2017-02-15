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

#define N 105
#define D 10
#define MOD 1000000007LL

using namespace std;

int n;
int c[D];
long long C[N][N];
long long memo[D][N];

long long dp( int dig , int cnt )
{
	if( dig == D ) return cnt == 0;
	long long &dev = memo[dig][cnt];
	if( dev == -1 )
	{
		dev = 0LL;
		for( int k = max( 0 , c[dig] ) ; k <= cnt ; ++k )
			dev = ( dev +  dp( dig + 1 , cnt - k )*C[cnt][k] + MOD )%MOD ;	
	}
	return dev;
}
int main()
{
	C[0][0] = 1;
	for( int i = 0 ; i < N ; i++ )
		C[i][0] = C[i][i] = 1;
	for( int i = 0 ; i < N ; i++ )
		for( int j = 1 ; j < i ; j++ )
		    C[i][j]=(C[i-1][j]+C[i-1][j-1] )%MOD;   
	while( cin >> n )
	{
		for( int i = 0 ; i < D ; ++i )
			cin >> c[i];
		long long ans = 0LL;
		for( int dig = 1 ; dig < D ; ++dig )
		{
			c[dig]--;
			for( int L = 0 ; L < n ; ++L )
			{
				memset( memo , -1 , sizeof( memo ) );				
				ans = ( ans + dp(0,L) + MOD )%MOD;
			}
			c[dig]++;
		}
		cout << ans << "\n";
	}
}
