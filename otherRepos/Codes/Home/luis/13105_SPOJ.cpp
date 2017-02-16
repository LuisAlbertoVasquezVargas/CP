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

#define N 1000000

using namespace std;

int nS;
int DP[N+1][2];
char S[N+1];

int main()
{
        while( scanf("%d", &nS ) == 1 )
        {
                scanf( "%s" , S );
                reverse(S,S+nS);
                DP[nS][0] = DP[nS][1] = 0;
                for( int pos = nS -1 ; pos >= 0 ; pos -- )
                        for( int is_A = 0 ; is_A < 2 ; ++is_A )
                                if( S[pos] == (is_A?'A':'B') )
                                        DP[pos][is_A] = DP[pos+1][is_A];
                                else    DP[pos][is_A] = min( 1 + DP[pos+1][is_A] , 1 + DP[pos+1][1-is_A] );

                printf("%d\n",DP[0][1] );
        }
}
