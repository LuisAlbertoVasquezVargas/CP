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

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , k;
ll pow( ll numa, ll  numb, ll numc ){
    ll numx = 1, numy = numa;	
    while( numb > 0 ){
        if( numb&1 ) numx = ( numx * numy )%numc;
        numy = ( numy*numy)%numc;
        numb >>= 1;
    }	
    return numx;
}
ll f( int t )
{
	return pow( t , t - 1 , MOD ); 
}
int main()
{
	while( cin >> n >> k )
	{
		if( n == k )cout << f( n ) << endl;
		else	cout << (((f( k ) *( n - k ))%MOD) * f( n - k ))%MOD << endl;
	}
}
