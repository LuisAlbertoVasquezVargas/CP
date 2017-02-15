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

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

#define N 410149
#define MOD 1000000007
#define INF (1<<30)
#define MAXNOD 521196
#define MAXALPHA 27

using namespace std;

int n , nT;
int trie[MAXNOD+5][MAXALPHA],Node,term[MAXNOD];
char S[MAXNOD+5] , T[100];
int memo[50][MAXNOD][6];

void add( char s[] )
{
    int p = 0 ; 
    int ns = strlen(s);
    for( int i = 0 ; i < ns ; ++i )
    {
        if( trie[p][s[i]-'a'] == 0 )
            p = trie[p][s[i]-'a'] = ++Node;
        else p = trie[p][s[i]-'a'];
    }
    term[p] = 1;
}
void init()
{
    memset(trie,0,sizeof(trie));
    memset(term,0,sizeof(term));
    Node = 0;
    for( int i = 0 ; i < N ; ++i )
    	cin >> S , add( S );
}
int dp( int pos , int node , int intouch )
{
	if( pos == nT )
	{
		if( term[node] == 0 )return 0;
		return INF;
	}
	int &dev = memo[pos][node][intouch];
	if( dev == -1 )
	{
		dev = INF;
		if( term[node] )
			dev = dp( pos , 0 , intouch );
		else if( intouch )
			dev = dp( pos + 1 , trie[node][T[pos]-'a'], intouch - 1 );
		else
		{
			for( int i = 0 ; i < 26 ; ++i )
				if( 'a' + i == T[pos] )
				{
					if( trie[node][T[pos]-'a'] != 0 )
						dev = min( dev ,  dp( pos + 1 , trie[node][T[pos]-'a'] , 5 ) );
				}
				else
				{
					if( trie[node][i] != 0 )
						dev = min( dev , 1 + dp( pos + 1 , trie[node][i] , 5 ) );
				}
		}
	}
	return dev;
}
int main()
{
	sync
	init();
	int tc;
	cin >> tc;
	for( int t = 0 ; t < tc ; ++t )
	{
		scanf( "%s" , T );
		nT = strlen( T );
		me( memo , -1 );
		cout << "Case #" << t + 1 << ": " << dp( 0 , 0 , 0 ) << endl;
	}
}
