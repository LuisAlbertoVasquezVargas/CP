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

int A[N],L[N],R[N];
int n , m;
void init()
{
	L[ n - 1 ] = n - 1;
	for( int i = n - 2 ; i >= 0 ; --i )
		if( A[i] <= A[i+1] ) L[i] = L[i+1];
		else L[i] = i;
	R[ 0 ] = 0 ;
	for( int i = 1 ; i < n ; ++i )
		if( A[i] <= A[i-1] )R[i] = R[i-1];
		else R[i] = i;
}
int main()
{
	while( scanf( "%d%d" , &n , &m ) == 2 )
	{
		REP( i , n )sc( A[i] );
		init();
		while( m-- )
		{
			int x , y;
			scanf( "%d%d" , &x , &y );
			x-- , y--;
			if( y - x + 1 <= 2 || L[x] >= R[y] )puts("Yes");
			else puts("No");
		}	
	}
}


