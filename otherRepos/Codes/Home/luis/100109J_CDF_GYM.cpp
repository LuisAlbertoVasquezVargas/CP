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

#define N 205
#define inf (1<<30)
#define eps 1e-5
#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define test puts("test");


using namespace std;

int n , a , b;
string s;
int memo[N][N][N];
int dp( int pos , int cnta , int cntb )
{
    if( pos == n )
    {
        if( cnta == a && cntb == b )return 0;
        return inf;    
    }    
    int &dev = memo[pos][cnta][cntb];
    if( dev == -1 )
    {
        dev = inf;
        for( char c = '0' ; c <= '2' ; ++c )
            dev = min( dev , (c!=s[pos]) + dp( pos + 1 , cnta + (c=='0') ,cntb + (c=='1') ) );
    }
    return dev;
}
string f( int pos , int cnta , int cntb )
{
    if( pos == n )
        return "";
    int ans = dp( pos , cnta , cntb );
    for( char c = '0' ; c <= '2' ; ++c )
    {
        int temp = (c!=s[pos]) + dp( pos + 1 , cnta + (c=='0') ,cntb + (c=='1') ) ;
        if( temp == ans )return string(1,c) + f( pos + 1 , cnta + (c=='0') ,cntb + (c=='1') );
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while( cin >> n >> a >> b >> s )
    {
        me( memo, -1 );
        int ans = dp( 0 , 0 , 0 );
        if( ans >= inf )puts("-1");
        else{
            cout << ans << endl;
            cout << f( 0 , 0 , 0 ) << endl;
        }
    }
}
