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

int main()
{
	int n;
	while( scanf( "%d" , &n ) == 1 )
	{
		if( !n )break;
		ll lo = 0 , hi = 1e6;
		while( hi - lo > 1 )
		{
			ll med = lo + ( hi - lo )/2;
			if( med*med >= n )hi = med;
			else lo = med;
		}
		ll m = hi;
		n -= (m-1)*(m-1);		
		if( m%2 == 0 )
		{
			if( n <= m  )cout << n << " " << m << endl;
			else cout << m << " " << m + m - n << endl;
		}
		else
		{
			if( (n >= m)  )cout << m + m - n << " " << m << endl;
			else cout << m << " " << n << endl;
		}
	}
}


