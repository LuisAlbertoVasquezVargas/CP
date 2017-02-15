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
bool prime( int k )
{
	for( int i = 2 ; i * i <= k ; ++i )
		if( k%i == 0 )
			return 0;
	return 1;	
}
int main()
{
	while( cin >> n )
	{
		if( n == 0 )break;
		if( !prime( n ) )
			printf( "The number %d is a Carmichael number.\n" , n );
		else	printf( "%d is normal.\n" , n ); 
	}
}
