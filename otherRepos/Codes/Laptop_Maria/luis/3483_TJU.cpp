#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vector<int> >
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
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

int n , m , tc;

int main()
{
	sc( tc );
	while( tc -- )
	{
		cin >> n >> m;
		int g = __gcd( n , m );
		ll ans = 1;
		for( int i = 2 ; i * i <= g ; ++i )
		{
			int e = 0 ;
			while( g%i == 0 )e++ , g/= i;
			ans *= ( e + 1 );
		}
		if( g > 1 ) ans *= 2;
		cout << ans << '\n';
	}
}

