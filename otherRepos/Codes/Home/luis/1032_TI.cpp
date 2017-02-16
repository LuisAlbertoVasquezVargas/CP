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

using namespace std;

int n;
int a[N];
int A[N];
int pos[N];

void doit()
{
	for( int i = 0 ; i < n ; ++i )
		if( a[i] %n == 0 )
		{
			puts("1");
			printf("%d\n",a[i]);
			return ;
		}
	A[n] = 0;
	for( int i = n - 1 ; i >= 0 ; --i )
		A[i] = (A[i+1] + a[i])%n;
	memset( pos , -1 , sizeof( pos ) );
	for( int i = n ; i >= 0 ; --i )
		if( pos[A[i]] == -1 )
			pos[A[i]] = i;	
		else
		{
			printf( "%d\n" , pos[A[i]] - i  );
			for( int j = i ; j < pos[A[i]] ; ++j )
				printf( "%d\n" , a[j] );
			return;
		}
	puts("0");
}
int main()
{
	while( cin >> n )
	{
		for( int i = 0 ; i < n ; ++i )
			cin >> a[i];
		doit();
	}
}
