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

int n;

int main()
{
	while( cin >> n )
	{
		ll maxiX = -1 , maxiY = -1;
		ll miniX = INF , miniY = INF;
		ll Xlo , Ylo , Xhi , Yhi;
		ll S = 0;
		REP( i , n )
		{
			cin >> Xlo >> Ylo >> Xhi >> Yhi;
			maxiX = max( maxiX , max( Xlo , Xhi ) );
			maxiY = max( maxiY , max( Ylo , Yhi ) );
			miniX = min( miniX , min( Xlo , Xhi ) );
			miniY = min( miniY , min( Ylo , Yhi ) );
			S += (Xhi - Xlo)*(Yhi - Ylo);
		}
		if( S == (maxiX - miniX)*(maxiY - miniY) && (maxiX - miniX) ==(maxiY - miniY) )puts( "YES" );
		else puts( "NO" );
	}	
}


