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

#define N 305
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int A[ N ];

int main()
{
	int n;
	while( cin >> n )
	{
		REP( i , n )
			cin >> A[ i ];
		REP( i , n )
			if( i == 0 )
			{
				REP( k , A[ 0 ] ) cout << "PRL";
				cout << "R";
			}
			else
			{
				REP( k , A[ i ] ) cout << "PLR";
				if( i != n - 1 )cout << "R";
			}
		cout << '\n';
	}
}


