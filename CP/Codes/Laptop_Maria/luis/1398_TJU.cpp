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

#define N 105
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , tc;
int A[N] , vis[ 1<< 21 ];

int main()
{
	sc( tc );
	while( tc -- )
	{
		sc( n );
		int Sum = 0;
		REP( i , n ) sc( A[i] ), Sum += A[i];
		if( Sum%4 )
		{
			puts( "no" );
			continue;
		}
		vi V;
		Sum /= 4;
		me( vis , 0 );
		REP( mask , 1<<n )
		{
			int sum = 0;
			REP( i , n )if( mask&(1<<i) )
				sum += A[i];
			if( sum == Sum )
				V.pb( mask );
		}
		int m = V.size();
		bool flag = 1;
		int allb = ((1<<n)-1);
		for( int i = 0 ; flag && ( i < m ) ; ++i )
			for( int j = i + 1 ; flag && ( j < m ); ++j )
			{
				int mask1 = V[i] , mask2 = V[j];
				/*cout << "mask1" << endl;
				deb( mask1 );
				cout << "mask2" << endl;
				deb( mask2 );*/
				if( !( mask1&mask2 ) )
				{
					int mask = mask1|mask2;
					int cmp = allb xor mask;
					/*
					cout << "cmp" << endl;
					deb( cmp );
					*/
					vis[ mask ] = 1;
					if( vis[ cmp ] )flag = 0;
				}
			}
		puts( flag?"no":"yes" );
	}
}

