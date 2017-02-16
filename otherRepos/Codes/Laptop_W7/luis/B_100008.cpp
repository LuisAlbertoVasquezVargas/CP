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

int x, y ;
string z;
int tc;

int f( char c )
{
	if( isdigit( c ) )return c - '0';
	return 10 + c - 'A';
}
char g( int x )
{
	if( x <= 9 )return '0' + x;
	return 'A' + x - 10 ;
}
int main()
{
	sync;
	cin >> tc;
	while( tc-- )
	{
		cin >> x >> y >> z;
		ll val = 0;
		int nz = z.size();
		REP( i , nz ) val = val*x + f(z[i]);
		string s = (val==0)?"0":"";
		while( val > 0 )
		{
			int dig = val%y;
			s = ( g(dig) ) + s ;
			val/=y;
		}
		cout << s << endl;
	}
}


