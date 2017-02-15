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
#define MAXM 13
#define MAXALPHA 26
#define INF (1<<30)

using namespace std;

int nS, nT ;
char S[MAXN+1];
char T[MAXM][2];
int DP[MAXN+1][MAXALPHA+1];
bool P[MAXALPHA+1][MAXALPHA+1];

int main()
{
        while( scanf( "%s%d" , S , &nT ) == 2 )
        {
		nS = strlen(S);
		memset( P , 1 , sizeof(P) );
	        for( int i = 0 ; i < nT ; ++i )
	        {
		        scanf( "%s" , T[i] );
		        P[T[i][0]-'a'][T[i][1]-'a'] = 0;
		        P[T[i][1]-'a'][T[i][0]-'a'] = 0;		        
		}
		for( int j = 0 ; j <= MAXALPHA ; ++j )
			DP[nS][j] = 0;
		for( int pos = nS - 1 ; pos >= 0 ;--pos )
			for( int lastC = 0 ; lastC <= MAXALPHA ; ++lastC )
			{
				DP[pos][lastC] = 1 + DP[pos+1][lastC];
				if( P[S[pos]-'a'][lastC] )
					DP[pos][lastC] = min( DP[pos][lastC] , DP[pos+1][S[pos] - 'a'] ) ;
			}
		printf( "%d\n" , DP[0][MAXALPHA] );
        }
}
