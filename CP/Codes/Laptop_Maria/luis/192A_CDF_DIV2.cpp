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

int n , m ;

int main()
{
	while( cin >> n >> m )
	{
		vector< string >S( n );
		REP( i , n )cin >> S[i];
		set< pii >Set;
		REP( i , n )
		{
			int cnt = 0;
			REP( j , m ) if( S[i][j] == '.' )cnt++;
			if( cnt == m )REP( j , m ) Set.insert( mp( i , j ) );
		}
		REP( j , m )
		{
			int cnt = 0;
			REP( i , n )if( S[i][j] == '.' )cnt++;
			if( cnt == n )REP( i , n ) Set.insert( mp( i , j ) );
		}
		cout << Set.size() << endl;
	}
}


