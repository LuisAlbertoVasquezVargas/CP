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

int S , C , P , L ;

int main()
{
	int it = 0;
	while( cin >> S >> C >> P >> L )
	{
		if( !S )break;
		bool found = 0;
		int r , m ,s = S;
		REP( j , 1000 )
		{
			REP( i , 1000 )
				if( (i+1)*C - (j+1)*S == L - P )
				{
					found = 1;
					r = j , m = S - P;
					break;
				}
			if( found )break;
		}
		if( P == 0 ) r++ , m = 0;
		if( !found ) printf( "Case %d: Never\n" , ++it );
		else printf( "Case %d: %d %d/%d\n" , ++it , r , m , s );
	}
}


