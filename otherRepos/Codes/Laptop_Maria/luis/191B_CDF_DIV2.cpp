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

#define MAXN 1500000

bool prime[MAXN+1];

void sieve()
{
	memset( prime , true , sizeof( prime ) );
	prime[0] = false;
	prime[1] = false;
	for( int i = 2 ; i*i <= MAXN; i++ )
		if( prime[i] )
			for( int j = i*i ; j <= MAXN ; j+=i )
				prime[j] = false;
}

int main()
{
	sieve();
	int n;
	cin >> n;
	bool ok = 0;
	REP( i , MAXN )
	{
		if( !n )break;
		if( !prime[i] )continue;
		n--;
		if( !ok ) ok = 1;
		else printf( " " );
		printf( "%d" , i );
	}
	puts("");
}


