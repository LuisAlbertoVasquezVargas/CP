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

ll toi(string s){istringstream is(s);ll x;is>>x;return x;}
string tos(ll t){stringstream st; st<<t;return st.str();}

string f( int n )
{
	string t;
	for( int i = 1 ; i <= n ; ++i )
		t += "sin(" + tos( i ) + (i==n?"":(i%2?"-":"+"));
	return t + string( n , ')' );
}
string g( int n )
{
	string t;
	for( int i = n ; i >= 1 ; --i )
		t = (i==1?"":")") + f(i) + "+" + tos( n + 1 - i ) + t;
	return string( n - 1 , '(' ) + t ;
}
int main()
{
	int n;
	while( cin >> n )
		cout << g( n ) << endl;
}


