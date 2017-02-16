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
#define MOD 1000000007
#define INF (1LL<<40)
#define EPS (1e-5)

using namespace std;

int A[ N ];
int n;
ll f( ll x )
{
	ll s = 0;
	REP( i , n ) s += 1LL*A[ i ] ==( x - i );
	return s;
}
int main()
{
	sc( n );
	REP( i ,  n ) sc( A[ i ] );
	ll lo = -INF , hi = INF;
	while( hi - lo >= 4 )
	{
		int med1 = ( lo*2 + hi )/3 , med2 = ( lo + hi*2 )/3;
		if( f( med1 ) < f( med2 ) )
			hi = med2;
		else lo = med1;
	}
	cout << lo << endl;
	ll ans = INF , id;
	for( ll k = lo - 5 ; k <= lo + 5 ; ++k )
		if( f( k ) < ans )
			ans = f( k ) , id = k;
	cout << id << endl;
} 


