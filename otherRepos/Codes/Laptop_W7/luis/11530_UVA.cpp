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

string A = "abcdefghijklmnopqrstuvwxyz ";
string P = "123123123123123123412312341";
map< char , int >M;

int main()
{
	int nA = A.size() , tc;
	REP( i , nA ) M[ A[i] ] = P[i] - '0';
	while( cin >> tc )
	{
		string s;
		getline( cin , s );
		REP( i , tc )
		{
			getline( cin , s );
			int ans = 0;
			FOR( o , s )ans += M[*o];
			cout << "Case #" << i + 1 << ": " << ans << endl;
		}
	}
}


