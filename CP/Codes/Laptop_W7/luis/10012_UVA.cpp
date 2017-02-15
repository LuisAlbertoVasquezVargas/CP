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

#define N 10
#define ld long double

using namespace std;

ld R[ N ];
ld X[ N ];
int main()
{
	int tc;
	cin >> tc;
	while( tc -- )
	{
		int n;
		cin >> n;
		REP( i , n ) cin >> R[i];
		sort( R , R + n );
		ld mini = 1e100;
		do
		{
			X[ 0 ] = 0;
			for( int i = 1 ; i < n ; ++i )
			{
				ld maxpos = -1;
				for( int j = 0 ; j < i ; ++j )
				{
					ld pos = X[j] + 2*sqrt( R[i]*R[j] );
					maxpos = max( maxpos , pos );
				}
				X[ i ] = maxpos;
			}
			ld _L = 1e100 , _R = -1e100;
			REP( i  , n ) _L = min( _L  , X[i] - R[i] ) , _R = max( _R  , X[i] + R[i] ) ;  
			mini = min( mini , _R - _L );
		}
		while( next_permutation( R , R + n ) );
		printf( "%.3f\n" , double( mini ) );
	}
}


