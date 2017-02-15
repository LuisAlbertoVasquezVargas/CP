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

int n , a , b ;

int main()
{
	while( scanf( "%d%d%d" , &n , &a , &b ) == 3 )
	{
		vector< pii > v( n );
		REP( i , n ) sc( v[i].fi ) , v[i].se = i;
		if( a == b )
		{
			REP( i , a )printf("1 ");
			REP( i , b )printf( ( i + 1 == b ? "2\n":"2 ") );
			continue;
		}
		if( a > b )sort( all(v) );
		else sort( rall(v) );
		vi V( n ,2 ) , W;
		int temp = a;
		REP( i , n )
			if( ( a > b && v[i].fi < v[a-1].fi ) || ( a < b && v[i].fi > v[a-1].fi ) )V[v[i].se] = 1 , temp--;
			else if( v[i].fi == v[a-1].fi ) W.pb( v[i].se );
			else break;
		sort( all(W) );
		REP( i , temp ) V[W[i]] = 1;
		REP( i , n )printf( "%d%s" , V[i],(i+1==n?"\n":" ") );
	}
}


