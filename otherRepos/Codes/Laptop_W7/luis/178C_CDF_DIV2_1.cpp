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

#define N 1005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , m ;

ll pow( ll numa, ll  numb, ll numc ){
    ll numx = 1, numy = numa;	
    while( numb > 0 ){
        if( numb&1 ) numx = ( numx * numy )%numc;
        numy = ( numy*numy)%numc;
        numb >>= 1;
    }	
    return numx;
}
ll modular_inverse( ll numa , ll mod )
{
	return pow( numa , mod - 2 , mod );	
}
ll F[N],FP[N];
void init(){
	F[0] = 1;
	for( int i = 1 ; i < N ; ++i ) 
		F[i] = i*F[i-1] , F[i] %= MOD;
	FP[N-1] = modular_inverse( F[ N - 1 ] , MOD ) ;
	for( int i = N - 2 ; i >= 0 ; --i ) 
		FP[i] = FP[i+1]*(i+1) , FP[i] %= MOD;
}

int main()
{
	init();
	while( cin >> n >> m )
	{
		vector< int >v( m );
		for( int i = 0 ; i < m ; ++i )cin >> v[i],v[i]--;
		sort( all(v) );
		vector< int > w;
		ll ans = 1;
		for( int i = 1 ; i < m ; ++i )
			if( v[i] != v[i-1] + 1 )
				w.pb( v[i] - v[i-1] - 1 ) , ans*= pow( 2 , v[i] - v[i-1] - 2 , MOD ) , ans %= MOD;
		if( v[0] != 0 ) w.pb( v[0] );
		if( v[m-1] != n - 1 ) w.pb( n - 1 - v[m-1] );
		ll cnt = 0;
		for( int i = 0 ; i < w.size() ; ++i ) cnt+=w[i] , ans*=FP[w[i]] , ans%= MOD;
		ans *= F[cnt];
		ans %= MOD;
		cout << ans << endl;
	}
}
