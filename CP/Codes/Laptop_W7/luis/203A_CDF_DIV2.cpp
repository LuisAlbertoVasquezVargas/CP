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

#define N 105
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int A[ N ] , B[ N ];

int main()
{
	int n , m;
	while( scanf( "%d%d" , &n , &m ) == 2 )
	{
		REP( i , n ) sc( A[ i ] );
		REP( i , m ) sc( B[ i ] );
		bool found = 0;
		int ans ;
		for( int k = 1 ; k <= 200 ; ++k )
		{
			int cnt1 = 0 , cnt2 =  0 , cnt3 = 0;
			REP( i , n ) cnt1 += ( A[ i ] <= k ) , cnt2 += ( A[ i ]*2 <= k );
			REP( i , m ) cnt3 += ( B[ i ] <= k );
			if( cnt3 == 0 && cnt2 > 0 && cnt1 == n )
			{
				found = 1 , ans = k;
				break;
			}
		}
		if( found ) printf( "%d\n" , ans );
		else puts( "-1" );
	} 
}


