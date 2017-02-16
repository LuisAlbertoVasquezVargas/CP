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

#define N 90
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

ll x , y , m ;
ll F[N];
void init()
{
	F[0] = F[1] = 1;
	for( int i = 2 ; i < N ; ++i )
		F[i] = F[i-1] + F[i-2];//, cout << F[i] <<endl;
}

int main()
{
	init();
	while( cin >> x >> y >> m )
	{
		if( x > y )swap( x , y );
		if( x >= m || y >= m )puts("0");
		else if( x == 0 && y == 0 )puts("-1");
		else if( x <= 0 && y <= 0 && m > y )puts("-1");
		else if( x >= 0 && y >= 0 )
		{
			REP( i , N )
				if( i && F[i]*y + F[i-1]*x >= m )
				{
					cout << i << endl;
					break;
				}
		}
		else if( x <= 0 && y <= 0 )
		{
			REP( i , N )
				if( i && F[i]*x + F[i-1]*y >= m )
				{
					cout << i << endl;
					break;
				}
			
		}
		else
		{
			x  = -x;
			ll cnt = x/y + ((x%y)>0) ;
			x = -x;
			x = x + y*cnt;
			REP( i , N )
				if( i && F[i]*y + F[i-1]*x >= m )
				{
					cout << i + cnt << endl;
					break;
				}
		}
	}
}


