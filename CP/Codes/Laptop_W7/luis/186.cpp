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

#define N 27
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int P[] = { 2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43 , 47 , 53 , 59 , 61 , 67 , 71 , 73 , 79 , 83 , 89 , 97 , 101 , 103 };
int E[110][N+1];
 
int main()
{
	for( int i = 2 ; i <= 106 ; ++i )
	{
		int p = i;
		for( int j = 0 , cnt = 0; j < N ; ++j )
		{
			while( p%j == 0 )cnt++ , p/=j;
			E[i][j] = cnt;
		}
	}
	int n;
	while( sc(n) == 1 )
	{
		ll ans = 1;
		REP( i , N )
			ans = ( ans * ( ( E[n][i] + 1 )%MOD ) )%MOD;
		cout << ans << '\n';
	}
}


