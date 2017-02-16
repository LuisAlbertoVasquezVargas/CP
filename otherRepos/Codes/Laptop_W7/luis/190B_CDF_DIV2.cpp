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

ll a , b , c;
int main()
{
	while( cin >> a >> b >> c )
	{
		vector< pll >P;
		P.pb( mp(a%3,a) );
		P.pb( mp(b%3,b) );
		P.pb( mp(c%3,c) );
		sort( all(P) );
		if( P[0].fi == 0 && P[1].fi == 2 && P[2].fi == 2 && P[0].se == 0 )
		{
			cout << a/3 + b/3 + c/3 << endl;
			continue;
		}		
		if( P[0].fi == 0 && P[1].fi == 1 && P[2].fi == 2 )
		{
			cout << a/3 + b/3 + c/3 << endl;
			continue;
		}
		cout << ( a + b + c )/3 << endl;
	}
}


