#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair< int , int >
#define pll pair< ll , ll >
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vi >
#define vpii vector< pii >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

int phi( int n ){
	int ans = n;
	for( int i = 2 ; i * i <= n ; ++i )
		if( n%i == 0 ){
			while( n%i == 0 ) n /= i;
			ans -= ans/i;
		}
	if( n > 1 ) ans -= ans/n;
	return ans;
}

int main()
{
	int n;
	while( cin >> n ) {
		if( n == 0 ) break;
		if( n == 1 ){
			puts( "0" );
			continue;
		}
		printf( "%d\n" , phi( n ) );
	}
}

