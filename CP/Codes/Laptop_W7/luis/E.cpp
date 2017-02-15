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

int A[ N ], B[ N ];
int M[ 2*N ][ 2*N ]; 
int out[ 2*N ];
int main()
{
	int tc;
	sc( tc );
	REP( cases , tc )
	{
		int nA , nB;
		sc( nA );
		REP( i , nA )
			sc( A[ i ] );
		sc( nB );
		REP( i , nB )
			sc( B[ i ] );
		clr( M , 0 );
		clr( out , 0 );
		REP( i , nA )REP( j , nB )
		{
			if( A[ i ] == 0 )
			{
				if( B[ j ] == 0 )
				{
					M[ i ][ nA + j ] = 1;
					out[ i ] ++;
					M[ nA + j ][ i ] = 1;
					out[ nA + j ]++;
				}
			}
			else if( B[j]%A[i] == 0 )
			{
				M[ i ][ nA + j ] = 1;
				out[ i ] ++;
				M[ nA + j ][ i ] = 1;
				out[ nA + j ]++;
			}
		}
		int cnt = 0 ;
		while( 1 )
		{
			int ind = -1 , maxi = 0;
			REP( i , nA + nB )
				if( out[ i ] > maxi )
				{
					 ind = i;
					 maxi = out[ i ];
				}
			//cout << ind << endl;
			if( ind == -1 ) break;
			cnt++;
			out[ ind ] = 0;
			REP( i , nA + nB )
				if( M[ ind ][ i ] )
					out[ i ]--;
		}
		printf( "Case %d: %d\n" , cases + 1 , cnt );
	}
}


