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

#define N (25*600+5)
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)
#define ALF 26

using namespace std;


int next[N][ALF] , node , T[N] , term[N];
int memo[600][N];
int nS;
string S;
int m , k;
void add( string s ){
    int ns = s.size() , ac = 0;
    for(int i = 0 ; i < ns ; i++){
        if( next[ ac ][ s[i] - 'a' ] == -1 ) next[ac][ s[i] - 'a' ] = ++node;
        ac = next[ac][ s[i] - 'a' ];
    }
    term[ac] = 1;
}
 

int dp( int pos , int nodo )
{
	if( pos == nS )return term[nodo]?0:INF;
	int &dev = memo[pos][nodo];
	if( dev == -1 )
	{
		int sig = next[nodo][S[pos]-'a'];
		dev = 1 + dp( pos + 1 , nodo );
		if( sig != -1 ){
        	dev = min( dev , dp( pos + 1 , sig ) );
        	if( term[sig] ) dev = min( dev , dp(pos + 1 , 0 ) );
    	}
	}
	return dev;
}
int main()
{
	sync	
	while( cin >> m >> nS )
	{
		cin >> S;
		node = 1;
    	me( next , -1 );
    	me( term , 0 );
        for(int i = 0 ; i < m ; i++){
            string s;
			cin >> s;
            add( s );
        }
        me( memo , -1 );
        cout << dp( 0 , 0 ) << '\n';
	}
}
