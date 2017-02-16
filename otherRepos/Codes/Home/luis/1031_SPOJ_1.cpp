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

int tc , n , ns , sz;
char s[MAXN+1];
char S[MAXN+1];
int memo[MAXN][MAXN];
vector< string >v;
int dp( int pos , int last )
{
	if( pos == ns ) return 0;
	int &dev = memo[pos][last];
	if( dev == -1 )
	{
		dev  = max( dev , dp( pos + 1 , last ) );
		if( s[pos] >= s[last] )
			dev  = max( dev , 1 + dp( pos + 1 , pos ) );			
	}
	return dev; 	
}
void print( int pos , int last )
{
	if( pos == ns )
	{
		v.push_back( string(S) );
//		printf("%s\n",S );
		return;
	}
	int ans1 = dp( pos , last );
	int ans2 = dp( pos + 1 , pos );
	if( s[pos] >= s[last] && ans1 == 1 + ans2 )
	{
		S[sz++] = s[pos];
		print( pos + 1 , pos );
		sz--;	
	}
	if( ans1 == dp( pos + 1 , last ) )
		print( pos + 1 , last );
}
int main()
{
	scanf( "%d" , &tc );
	while( tc-- )
	{
		cin >> s ;
		v.clear();
		sz = 0;
		ns = strlen( s ); 
		memset( memo , -1 , sizeof( memo ) );
		memset( S , 0 , sizeof( S ) );
		int maxi = 0;
		for( int j = 0 ; j < ns ; ++j )
			maxi = max( maxi , dp(j+1,j));
		for( int j = 0 ; j < ns ; ++j )
			if( dp(j+1,j) == maxi )
			{
				sz=1;
				S[0] = s[j];
				print(j+1,j);
			}
				
		sort( v.begin() , v.end() );
		int nv = unique( v.begin() , v.end() ) - v.begin();
		for( int i = 0 ; i < nv ; ++i )
			cout << v[i] << endl;
		puts("");
	}
}
