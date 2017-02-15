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

#define N 100005
#define MOD 1000000009
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

ll pow( ll a , ll b , ll c ){
	ll ans = 1;
	while( b )
	{
		if( b & 1 ) ans = ( ans * a )%c;
		a = ( a * a )%c;
		b /= 2;
	}
	return ans;
}
int main()
{
	ll n , m , k ;
	while( cin >> n >> m >> k )
	{
		ll u = ( n / k )*( k - 1 ) + ( n % k );
		ll t = m - u;
		if( t <= 0 ) cout << m << endl;
		else 
		{
			cout << ( ( 2*k*( pow( 2 , t , MOD ) - 1 + MOD ) )%MOD + ( m - (k*t)%MOD + MOD )%MOD )%MOD << endl;
			//cout << t << "  " << k << endl;
		}
	}
}


