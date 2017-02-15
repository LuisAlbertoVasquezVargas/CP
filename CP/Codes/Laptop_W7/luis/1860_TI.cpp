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

#define N 1000006
#define MOD 1000000007LL
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int P[N+5];
int F[N+5];

int init()
{
	clr( P , -1 );
	P[1] = 0;
	for( int i = 2 ; i*i <= N ; ++i )
		if( P[i] == -1 )
		{
			for( int j = i*i ; j <= N ; j+=i )
				P[j] = i;
		}
}
int main()
{
	init();
	int n;
	while( sc( n ) == 1 )
	{
		if( n <= 1 )puts("1");
		else
		{
			ll ans = 1;
			vi T;
			while( n > 1 && P[n] != -1 )
			{
				int p = P[n];
				T.pb( p );
				while( n%p == 0 )n/=p;
			}
			if( n > 1 )T.pb( n );
			int nv = T.size();
			for( int i = 0 ; i < nv ; ++i )
			{
				int p = T[i];
				cout << "*" << p << (i+1==nv?"\n":"*");
				F[0] = F[1] = 0;
				for( int j = 2 ; j <= n ; ++j )
				{
					F[j] = ( F[j-1] + F[j-2] )%MOD;
					int dev = 0 , temp = j;
					while( temp%p == 0 )dev++, temp/=p;
					F[j] = ( F[j] + dev )%MOD; 
				}
				ans = ( ans * (F[n] + 1) )%MOD;
			}
			printf( "%d\n" , ans );
		}
	}
}

