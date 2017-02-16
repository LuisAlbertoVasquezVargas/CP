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

#define N 55
#define W 0
#define B 1
#define R 2
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

ll memo[ N ][ 4 ];
/*
W 
B
R
*/
ll dp( int n , int last )
{
	if( n == 0 )return 1;
	ll &dev = memo[n][last];
	if( dev == -1 )
	{
		dev = 0;
		for( int k = 0 ; k < 3 ; ++k )
		{
			if( last == k )continue;
			// cuidado con el B
			if( k == B )
			{
				if( n > 1 && ( last == W || last == R ) )
					dev += dp( n - 2 , last==W?R:W );
			}
			else dev += dp( n - 1 , k );
		}
	}
	return dev;
}
int main()
{
	int n;
	clr( memo , -1 ); 
	while( cin >> n )
		cout << dp( n , 3 ) << endl;
}


