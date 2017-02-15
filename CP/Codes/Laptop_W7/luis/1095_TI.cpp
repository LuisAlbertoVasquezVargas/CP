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

#define N 25
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

char S[N];
int cnt[5];
int memo[N][N][N][N][8];

int dp( int cnt1 , int cnt2 , int cnt3 , int cnt4 , int mod )
{
	if( cnt1 + cnt2 + cnt3 + cnt4 == 0 )
		return mod == 0;
	int &dev = memo[ cnt1 ][ cnt2 ][ cnt3 ][ cnt4 ][ mod ];
	if( dev == -1 )
	{
		dev = 0;
		if( cnt1 )
			dev |= dp( cnt1 - 1 , cnt2 , cnt3 , cnt4 , (mod*10 + 1)%7 );
		if( cnt2 )
			dev |= dp( cnt1 , cnt2 - 1 , cnt3 , cnt4 , (mod*10 + 2)%7 );
		if( cnt3 )
			dev |= dp( cnt1 , cnt2 , cnt3 - 1 , cnt4 , (mod*10 + 3)%7 );
		if( cnt4 )
			dev |= dp( cnt1 , cnt2 , cnt3 , cnt4 - 1 , (mod*10 + 4)%7 );
	}
	return dev;
}
string f( int cnt1 , int cnt2 , int cnt3 , int cnt4 , int mod )
{
	if( (cnt1 + cnt2 + cnt3 + cnt4) == 0 )return "";
	if( cnt1 && dp( cnt1 - 1 , cnt2 , cnt3 , cnt4 , (mod*10 + 1)%7 ) )
		return "1" + f( cnt1 - 1 , cnt2 , cnt3 , cnt4 , (mod*10 + 1)%7 );
	if( cnt2 && dp( cnt1 , cnt2 - 1 , cnt3 , cnt4 , (mod*10 + 2)%7 ) )
		return "2" + f( cnt1 , cnt2 - 1 , cnt3 , cnt4 , (mod*10 + 2)%7 );		
	if( cnt3 && dp( cnt1 , cnt2 , cnt3 - 1 , cnt4 , (mod*10 + 3)%7 ) )
		return "3" + f( cnt1 , cnt2 , cnt3 - 1 , cnt4 , (mod*10 + 3)%7 );
	if( cnt4 && dp( cnt1 , cnt2 , cnt3 - 1 , cnt4 , (mod*10 + 3)%7 ) )
		return "4" + f( cnt1 , cnt2 , cnt3 , cnt4 - 1 , (mod*10 + 4)%7 );
	return "T";
}
int main()
{
	int tc;
	sc( tc );
	clr( memo , -1 );
	REP( t , tc )
	{
		clr( cnt , 0 );
		scanf( "%s" , S );
		int nS = strlen( S );
		REP( i , nS )cnt[S[i]-'0']++;
		if( dp( cnt[1] , cnt[2] , cnt[3] , cnt[4] , 0 ) )
			cout << f( cnt[1] , cnt[2] , cnt[3] , cnt[4] , 0 ) << endl;
		else puts("0");
	}
}


