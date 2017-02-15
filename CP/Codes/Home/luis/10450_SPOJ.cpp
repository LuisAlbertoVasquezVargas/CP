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

#define N 500005
#define MOD 1000000000
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

// 5000000 , 500000 ,50000 ,10000,1000,100,4,4,1,1
int V[11][N];
pair< int , int > P[11][N];
int pot[ 15 ];
int L[15] = { 0 , 4 , 4 , 20 , 100 , 1000 , 10000 , 50000 , 500000 , 5000000 };
int T[N];
ll X = 300000001;
int main()
{

	pot[0] = 1;
	for( int i = 1 ; i <= 9 ; ++i )
		pot[i] = 10*pot[i-1];
	//int tim = clock();
	for( int i = 1 ; i <= 8 ; ++i )
	{
		pot[i] = 10*pot[i-1];
		int cnt = 0;
		int x = 1;
		while( cnt < L[i] )
		{
			T[cnt] = x;
			P[i][cnt] = mp( x%pot[i] , cnt + 1 );
			int y = (x<<1)%MOD;
			int z = (y<<1)%MOD;
			x = ( (y + z)%MOD + x )%MOD;
			cnt++;
		}
		sort( P[i] , P[i] + L[i] );
		REP( j , L[i] )
			V[i][j] = P[i][j].fi;
	}
	char s[15];
	while( scanf("%s" , s ) == 1 )
	{
		int ns = strlen( s );
		int H = 0;
		REP( i , ns )H = H*10 + s[i]-'0';
		if( ns == 9 )
		{
			bool solve = 0;
			int pos = lower_bound( V[ns-1] , V[ns-1] + L[ns-1] , H%pot[ns-1] ) - V[ns-1] ;
			if( pos != L[ns-1] && V[ns-1][pos] == (H%pot[ns-1]) )
			{
				ll t = T[ P[ns-1][pos].se - 1 ];
				ll e = 1;
				REP( i , 10 )
				{
					ll q = (t*e)%pot[ns];
					//cout << q << " : : " << P[ns-1][pos].se<< endl;
					if( q == H )
					{
						printf( "%d\n" , 500000*i + P[ns-1][pos].se );
						solve = 1;
						break;
					}
					e = (e*X)%pot[ns];
				}
			}
			if( !solve ) puts("-1");
			continue;
		}
		int pos = lower_bound( V[ns] , V[ns] + L[ns] , H ) - V[ns] ;
		if( pos != L[ns] && V[ns][pos] == H )
			printf( "%d\n" , P[ns][pos].se );
		else puts("-1");
	}
	//cout << double(clock() - tim)/CLOCKS_PER_SEC << endl;	
}


