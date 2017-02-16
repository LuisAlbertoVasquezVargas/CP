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

int n, m;

ll F[N],G[N],A[N];
void init(){
	F[0] = 1;
	for( int i = 1 ; i < N ; ++i ) 
		F[i] = i*F[i-1] , F[i] %= m;
	G[0] = 1;
	A[0] = 0;
	for( int i = 1 ; i < N ; ++i )
	{
		int cnt = 0 , t = i;
		while( t > 0 && t%2 == 0 ) t/= 2 , cnt++;
		G[i] = G[i-1]*t , G[i]%= m;
		A[i] = A[i-1] + cnt;
	}
}
ll pow( ll numa, ll  numb, ll numc ){
    ll numx = 1, numy = numa;	
    while( numb > 0 ){
        if( numb&1 ) numx = ( numx * numy )%numc;
        numy = ( numy*numy)%numc;
        numb >>= 1;
    }	
    return numx;
}


int main()
{
	while( cin >> n )
	{
		vector< int > v(n) ,w(n); 
		map< int , int >M;
		for( int i = 0 ; i < n ; ++i )sc( v[i] ), M[v[i]]++;
		for( int i = 0 ; i < n ; ++i )sc( w[i] ),M[w[i]]++;
		int cnt = 0;
		for( int i = 0 ; i < n ; ++i )
			if( v[i] == w[i] )cnt++;
		cin >> m;
		init();
		ll ans = 1;
		FOR(o,M)
		{ 
			if( cnt == 0 )ans*= F[o->second] , ans%=m;
			else if( A[o->second] <= cnt )cnt-= A[o->second] , ans*= G[o->second] , ans%=m;
			else ans*= G[o->second] , ans%=m , ans*= pow( 2 , A[o->second] - cnt , m ) ,cnt = 0 , ans%= m;
		}
		cout << ans << endl;
	} 
} 
