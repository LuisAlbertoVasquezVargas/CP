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
#define MAXM 201
 
using namespace std;

int n;
int memo[MAXN][MAXM];
map< pair< int , int > , pair< int , int > >P;
pair< int , int >p,q; 

int dp( int pos , int mod )
{
	if( pos == MAXN - 1 && mod != 0 )return 0;
	if( mod == 0 )
	{
		p = make_pair( pos , mod );
		return 1;
	}
	int &ret = memo[pos][mod];
	if( ret == -1 )
	{
		ret = dp( pos + 1 , (mod*10+1)%n )|| dp( pos + 1 , (mod*10)%n );
		if( dp( pos + 1 , (mod*10+1)%n ) )
			P[ make_pair( pos + 1 , (mod*10 + 1)%n ) ] = make_pair( pos , mod );
		if( dp( pos + 1 , (mod*10)%n ) )			
			P[ make_pair( pos + 1, (mod*10)%n ) ] = make_pair( pos , mod );		
	}
	return ret;	
}

int main()
{
        for( n =  1 ; n <= 200 ; n++ )
        {
	
		memset( memo , -1 , sizeof( memo ) );
		P.clear();
		string ans ;
		dp(1,1);
		while( p != make_pair(1,1) )
		{
			q = P[p];
			int x = p.second;
			int y = q.second;	
			if( (y*10+1)%n == x )
				ans.push_back('1'); 
			else ans.push_back('0');
			p = q;
		}
		ans.push_back('1');
		reverse( ans.begin() , ans.end() );
		cout << ",\"" << ans << "\"";
        }
}
