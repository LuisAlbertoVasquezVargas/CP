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

int n;

int main()
{
	while( cin >> n )
	{
		int A[n][n];
		REP( i , n )REP( j , n ) cin >> A[i][j];
		cout << A[0][0];
		for( int i = 1 ; i < n ; ++i )
			for( int j = 0 ; i - j >= 0 ; ++j )
				cout << " " << A[i-j][j];
		for( int j = 1 ; j < n ; ++j )
			for( int k = 0 ; j + k < n ; ++k )
				cout << " " << A[n-1-k][j+k];
		puts("");
	}
}


