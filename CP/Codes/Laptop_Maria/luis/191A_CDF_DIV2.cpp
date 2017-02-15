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

#define N 105
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n;
int A[ N ];

int main()
{
	while( cin >> n )
	{
		REP( i , n ) sc( A[i] );
		int ans = 0;
		for( int i = 0 ; i < n ; ++i )
			for( int j = i ; j < n ; ++j )
			{
				int cnt = 0;
				for( int k = 0 ; k < i ; ++k )cnt += A[k];
				for( int k = i ; k <= j ; ++k )
					cnt += 1 - A[k];
				for( int k = j + 1 ; k < n ; ++k )cnt += A[k];
				ans = max( ans , cnt );
			}
		cout << ans << endl;
	}
}


