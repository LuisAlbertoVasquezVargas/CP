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
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int A[ N ];

int main()
{
	int n , m;
	while( scanf( "%d%d" , &n , &m ) == 2 )
	{
		REP( i , m )sc( A[i] );
		m = unique( A , A + m ) - A;
		ll ans = A[0] - 1;
		for( int i = 1 ; i < m ; ++i )
			if( A[i] > A[i-1] )
				ans += A[i] - A[i-1];
			else ans += n - A[i-1] + A[i];
		cout << ans << '\n';
	}
}


