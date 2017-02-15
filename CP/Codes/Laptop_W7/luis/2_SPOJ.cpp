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
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;


ll modulo(ll a, ll b, ll c){
	ll x = 1, y = a;
	while(b){
		if(b & 1) x = (x*y)%c;
		y = (y*y)%c;
		b >>= 1;
	}
	return x % c;
}
bool miller(ll p, int it = 8){
	if(p < 2) return false;
	if(p != 2 && p % 2 == 0) return false;
	ll s = p - 1;
	while(s % 2 == 0) s /= 2;
	while( it-- ){
		ll a = rand() % (p - 1) + 1, temp = s;
		ll mod = modulo(a, temp, p);
		while(temp != p - 1 && mod != 1 && mod != p - 1){
			mod = (mod*mod)%p;
			temp *= 2;
		}
		if(mod != p - 1 && temp % 2 == 0) return false;
	}
	return true;
}


int main()
{
	int tc;
	sc( tc );
	bool ok = 0;
	while( tc-- )
	{
		if( !ok ) ok = 1;
		else puts( "" );
		int n , m;
		sc( n ) , sc( m );
		for( int i = n ; i <= m ; ++i )
			if( miller( i ) )
				printf( "%d\n" , i );
	}
}


