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

#define N 400005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

string s , t;
int ns , nt;
bool solve()
{
	int i = 0 , j = 0;
	while( 1 )
	{
		if( j == nt ) return 1;
		if( i == ns ) return 0;
		if( s[ i ] == t[ j ] )
		{
			i++ , j++;
		}else i++;
	}
}
int main()
{
	int n;
	sync
	while( cin >> n )
	{
		t[ 0 ] = 0;
		REP( i , n ) cin >> s , t += "<3" , t += s;
		t += "<3";
		cin >> s;
		nt = t.size() , ns = s.size();
		puts( solve() ? "yes":"no" );
	}
}
