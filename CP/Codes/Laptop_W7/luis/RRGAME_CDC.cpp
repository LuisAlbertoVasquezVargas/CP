#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define pii pair< int , int >
#define pll pair< ll , ll >
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vi >
#define vpii vector< pii >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);
 
#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)
 
ll A[ N ];
 
int main()
{
	int n ;
	ll m , k , x ;
	scanf( "%d%lld%lld" , &n , &m , &k );
 
	REP( i , n )
	{
		scanf( "%lld" , &x );
		A[ i ] = ( m - x )/k + 1;	
	}
	sort( A , A + n );
	ll u = accumulate( A , A + n - 1 , 0LL );
	ll v = u + A[ n - 1 ];
	if( u&1 ) u++;
	if( v&1 ) v--;
	u >>=1 , v >>=1;
	//cout << u << " " << v << endl;
	printf( "%lld\n" , ( v - u + 1 + MOD )%MOD );
} 
