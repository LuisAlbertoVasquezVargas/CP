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

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

int n;
int A[ N ];

int f( int x ){
	REP( i , n ) 
		if( A[ i ] + x > A[ i + 1 ] ) continue;
		else if( A[ i ] + x == A[ i + 1 ] ) x--;
		else return 0;
	return 1;
}
int bs()
{
	int lo = 0 , hi = A[ n ];
	while( hi - lo > 1 )
	{
		int med = ( lo + hi )>>1;
		if( f( med ) ) hi = med;
		else lo = med;
	}
	return hi;
}
int main()
{
	int cases;
	sc( cases );
	REP( tc , cases )
	{
		sc( n );
		REP( i , n ) sc( A[ i + 1 ] );
		int ans = bs();
		printf( "Case %d: %d\n" , tc + 1 , ans );
	}
}

