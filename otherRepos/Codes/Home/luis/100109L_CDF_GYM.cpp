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

#define N 100005
#define MOD 1000000007
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

ll n , t1 , t2 ;
bool f( ll t )
{
    if( t/t1 + t/t2 >= n ) return 1;
    return 0;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while( cin >> n >> t1 >> t2 )
    {
        ll lo = 0 , hi = 1LL<<62;
        while( hi - lo > 1 )
        {
            ll med = lo + ( hi - lo )/2;
            if( f( med ) )hi = med;
            else lo = med;
        }
        ll ans1 = (hi/t1)*t1 + ((hi%t1)>0)*t1;
        ll ans2 = (hi/t2)*t2 + ((hi%t2)>0)*t2;
        cout << ans1/t1 + ans2/t2 << " " << max( ans1 , ans2 ) << endl;
    }
}
