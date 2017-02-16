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

int m;
string s, buff;
 
int main()
{
	sync
	while( cin >> m && m )
	{
		getline( cin , buff );
		getline( cin , s );
		int ns = s.size() , maxi = 0 , cnt = 0, L = 0;
		map< char , int >M;
		for( int i = 0 ; i < ns ; ++i )
		{
			if( M.size() == m && M.find(s[i]) == M.end() )
			{
				while( M.size() )
				{
					M[s[L]]--;
					cnt--;
					if( !M[s[L]] )
					{
						M.erase( s[L] );
						L++;
						break;
					}
					L++;
				}
			}
			M[s[i]]++;
			cnt++;
			maxi = max( maxi , cnt );
		}
		cout << maxi << endl;
	}
}
