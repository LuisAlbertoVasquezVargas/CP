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


long long pow( long long a, long long b, long long c){
    long long x = 1, y = a;
    while(b>0){
        if(b&1) x = (x*y)%c;
        y = (y*y)%c;
        b >>= 1;
    }
    return x;
}
int n , m ;

int main()
{
    while( scanf("%d%d" , &n , &m ) == 2 )
    {
        vector< int > v( m );
        vector< ll > F( n , 1 );
        for( int i  = 1 ; i < n ; ++i )F[i] = i*F[i-1] , F[i]%= MOD;
        for( int i  = 0 ; i < m ; ++i )sc( v[i] ),v[i]--;
        sort( all( v ) );
        ll ans = 1 , temp = 1;
        if( v[0] != 0 )temp*=F[v[0]];
        if( v[m-1] != n-1 )temp*= F[ n - 1 - v[m-1] ];
        temp %= MOD;
        for( int i = 1 ; i < m ; ++i )
            if( v[i] - v[i-1] != 1 )
            {
                ans *= pow( 2 , v[i] - v[i-1] - 2 , MOD ),temp *= F[v[i] - v[i-1]-1];
                ans %= MOD ,temp %= MOD ;
            }
        ans *= pow( temp ,MOD - 2 ,  MOD );
        ans %= MOD;
        ans *= F[n-m];
        ans %= MOD;
        cout << ans << endl;
    }
}