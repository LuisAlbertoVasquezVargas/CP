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

string S[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};

int f( int year )
{
	return year/4 - year/100 + year/400;
}
int main()
{
	sync
	map< string , int>M;
	REP( i , 12 )M[S[i]] = i + 1;
	int tc;
	cin >> tc;
	REP( t , tc )
	{
		string s ;
		int day , year;
		char c;
		cin >> s >> day >> c >> year;
		int x , y;
		if( M[s] > 2 )x = year + 1;
		else x = year;
		cin >> s >> day >> c >> year;
		if( M[s] > 2 || (M[s] == 2 && day == 29) )y = year;
		else y = year - 1;
		int ans = 0;
		if( y >= x - 1 )
			ans = f( y ) - f( x - 1 );
		cout << "Case " << t + 1 << ": " << ans << endl;
	}
}


