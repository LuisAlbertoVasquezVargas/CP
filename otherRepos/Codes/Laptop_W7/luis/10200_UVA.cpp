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

#define N 10005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;
bool isPrime( int num )
{
	if( num <= 1 ) return 0;
	if( num == 2 ) return 1;
	if( num%2 == 0 ) return 0;
	
	for( int i = 3 ; i*i <= num ; i += 2 )
		if( num%i == 0 ) return 0;
	return 1;
}

//n^2 + n + 41
int main()
{
	int a , b;
	ll T[N];
	T[0] = 0;
	for( int i = 0 ; i + 1 < N ; ++i )
		T[ i + 1 ] = T[ i ] + isPrime(1LL*i*i+i+41);
	while( scanf("%d%d" , &a , &b ) == 2 )
	{
		a++ , b++;
		int cnt = T[b] - T[a-1];
		double ans = 1.0*cnt/(b - a + 1);
		ans *= 10000;
		ans = floor( ans + 0.5 );
		ans /= 100;
		printf( "%.2f\n" , ans );
	}
}


