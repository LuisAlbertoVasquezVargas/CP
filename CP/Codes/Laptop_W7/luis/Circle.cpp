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

#define N 10105
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int F[ N ];
bool f( int x )
{
	if( x%7 == 0 )return 1;
	while( x )
	{
		if( x % 10 == 7 ) return 1;
		x /= 10;
	}
	return 0;
}
int main()
{
	//cout << f( 21 ) << endl;
	int i = 1 , pos = 1;
	int dev = 1;
	while( i <= 10100 )
	{
		if( f( i ) ) dev = -dev;
		F[ i ] = pos<= 0 ? (1337 + pos): pos;
		pos += dev;
		i++;
	}
	//REP( i , 20 ) cout << F[ i +1 ] << endl;
	//test
	int tc;
	sc( tc );
	while( tc-- )
	{
		int n;
		cin >> n;
		cout << F[ n ] << endl;
	}
}


