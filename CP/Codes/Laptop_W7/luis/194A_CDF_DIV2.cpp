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

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n;
int A[ N ];
vi E[ N ];

int main()
{
	while( sc( n ) == 1 )
	{
		REP( i , n ) E[ i ].clear();
		int m = n*n , cnt = 0 , ind = 0;
		for( int j = 1 ; j <= m/2 ; ++j )
		{
			if( cnt == n )
			{
				ind ++;
				cnt = 0;
			}
			A[ j ] = ind;
			A[ m - j + 1 ] = ind;
			cnt += 2;
		}
		for( int j = 1 ; j <= m ; ++j )
			E[ A[ j ] ].pb( j );
		REP( j , n )
			if( !E[ j ].empty() )
				REP( i , E[ j ].size() )
					cout << E[ j ][ i ] << ( i + 1 == E[ j ].size() ? "\n": " " );
		puts( "" );
		/*for( int j = 1 ; j <= m ; ++j )
			cout << A[ j ] << " ";
		puts( "" );*/
	}
}


