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

#define MAXN 200
#define INF (1<<20)

using namespace std;

int n;
string S[MAXN];
int T[MAXN][3];
int d[MAXN][MAXN];

void init()
{
    for( int i = 0 ; i < n ; ++i )
		d[i][i] = 0;	
    for( int i = 0 ; i < n ; ++i )
        for( int j = 0 ; j < n ; ++j )
            d[i][j] = INF;	
}
void floyd()
{
    for( int k = 0 ; k < n ; ++ k )
        for( int i = 0 ; i < n ; ++i )
            for( int j = 0 ; j < n ; ++j )
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);	
}
int main()
{
     while( cin >> n )
     {
          for( int i = 0 ; i < n ; ++i )
               cin >> S[i] >> T[i][0] >> T[i][1] >> T[i][2];
          init();
          for( int i = 0 ; i < n ; ++i )
          	for( int j = 0 ; j < n ; j++ )
          		if( j != i )
          		{
					int cnt = 0;
					for( int k = 0 ; k < 3 ; ++k )	
						if( T[i][k] > T[j][k] )
							cnt++;
					if( cnt >= 2 )
						d[i][j] = 1;
				}
		floyd();
		for( int i = 0 ; i < n ; ++i )
		{
			int cnt = 0 ;
			for( int j = 0 ; j < n ; j++ )
				if( d[i][j] != INF )
					cnt ++;
			if( cnt == n )
				cout << S[i] << endl;
		}
     }
}
