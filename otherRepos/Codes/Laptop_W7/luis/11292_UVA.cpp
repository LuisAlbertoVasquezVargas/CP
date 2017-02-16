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

#define N 20005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int A[ N ] , B[ N ];
int n , m;

int main()
{	
	while( scanf( "%d%d" , &n  ,&m ) == 2 && n )
	{
		REP( i , n ) sc( A[ i ] );
		REP( i , m ) sc( B[ i ] );
		sort( A , A + n );
		sort( B , B + m );
		int ans = 0 , ind = 0;
		bool solve = 0;
		REP( i , m )
		{
			if( ind < n && A[ ind ] <= B[ i ] ) ans += B[ i ] , ind++;
			if( ind == n ) solve = 1;
			if( solve ) break;
		} 
		if( !solve ) puts( "Loowater is doomed!" );
		else printf( "%d\n" , ans );
	}
}

