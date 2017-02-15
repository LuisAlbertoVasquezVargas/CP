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

#define MAXN 52

using namespace std;

int n;
vector < vector< string > >st;
string s;
bool ok;

void doit()
{
	ok = 1;
	while( 1 )
	{
		if( !ok ) break;
		ok = 0;
		n = st.size();
		for( int k = 0 ; k < n ; ++k )
		{
			string s1 , s2 , s3;
			if( k - 3 >= 0 )
				s1 = st[k-3].back();
			if( k - 1 >= 0 )
				s2 = st[k-1].back();
			s3 = st[k].back();
			if( k - 3 >= 0 && s1[0] == s3[0] || s1[1] == s3[1] )
			{
				
				ok = 1;
				st[k-3].push_back(s3);
				st[k].pop_back();
				if( st[k].empty() )
					st.erase( st.begin() + k );
				break;
			}
			else if( k - 1 >= 0 && s2[0] == s3[0] || s2[1] == s3[1] )
			{				
				ok = 1;
				st[k-1].push_back(s3);
				st[k].pop_back();
				if( st[k].empty() )
					st.erase( st.begin() + k );
				break;				
			}
		}			
	}
}

void present()
{
	n = st.size();
	if( n == 1 )
	{
		cout << "1 pile remaining: " << st[0].size() << "\n";
		return;
	}
	cout << n << " piles remaining:";
	for( int i = 0 ; i < n ; ++i )
		cout << " " << st[i].size() ;
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);	
     while( cin >> s )
     {
		st.clear();
		if( s == "#" )return 0;
		vector< string >v;
          v.push_back(s);
          st.push_back(v);
          for( int i = 1 ; i < MAXN ; ++i )
          {
               cin >> s ;
               v.clear();
               v.push_back(s);
               st.push_back(v);
		}
		doit();
		present();
     }
}
