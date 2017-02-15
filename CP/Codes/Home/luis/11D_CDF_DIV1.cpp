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

#define N 20
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , m, tail ;
int M[N][N];
ll memo[1<<N][N];

ll dp( int pos , int mask )
{
	if( mask&(1<<tail) )return ones( mask ) > 2 ;
	ll &dev = memo[ mask ][ pos ];
	if( dev == -1 )
	{
		dev = 0;
		for( int i = tail ; i < n ; ++i )
			if( M[pos][i] && !( mask &(1<<i) ) )
				dev += dp( i , mask^(1<<i) );
	}
	return dev;
}
int main()
{
	int x , y;
	cin >> n >> m;
	REP( i , m )
	{
		cin >> x >> y;
		x -- , y--;
		M[x][y] = M[y][x] = 1;
	}
	ll ans = 0;
	REP( i , n )
		clr( memo , -1 ) , tail = i , ans += dp( i , 0 );
	cout << (ans >>1) << endl;
}



