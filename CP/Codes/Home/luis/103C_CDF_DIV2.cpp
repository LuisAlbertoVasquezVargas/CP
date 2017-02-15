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
#define MAXALPHA 26
#define DELTA 1

using namespace std;

int ns , nt ;
string s , t;
int acum[MAXN+DELTA][MAXALPHA];
int acum2[MAXN+DELTA][MAXALPHA];

void f( int array[MAXN+DELTA][MAXALPHA] , string cad , int n )
{
	for( int i = 1 ; i <= n ; ++i )
		for( int j = 0 ; j < MAXALPHA ; ++j )
			if( 'a' + j == cad[i] )
				array[i][j] = array[i-1][j]+1;
			else array[i][j] = array[i-1][j];		
}

int main()
{
        while( cin >> s >> t )
        {
		ns = s.size();
		nt = t.size();
		s = "0" + s;
		t = "0" + t;
		memset( acum , 0 , sizeof( acum ) );
		memset( acum2 , 0 , sizeof( acum2 ) );		
		if( ns < nt )
			cout << 0 << endl;
		else
		{
			int cnt = 0;
			f(acum,s,ns);f(acum2,t,nt);
			for( int i = 1 ; i + nt - 1 <= ns ; ++i )
			{
				bool ok = 1;
				for( int j = 0 ; j < MAXALPHA ; ++j )	
				{
					int sum = acum[i+nt-1][j]-acum[i-1][j];
					int sum2 = acum2[nt][j]-acum2[0][j];
					if( !(sum <= sum2) )
					{
						ok = 0;
						break;	
					}
				}
				cnt+=ok;
			}
			cout << cnt << endl;
		}
        }
}
