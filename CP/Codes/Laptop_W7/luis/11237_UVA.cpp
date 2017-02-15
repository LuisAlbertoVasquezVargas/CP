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

int A[ N ] , B[ N ], ind[ N ];

int main()
{
	int c , n;
	while( scanf( "%d%d" , &c , & n ) == 2 && c )
	{
		clr( ind , -1 );
		REP( i , n ) sc( A[i] );
		B[0] = A[0]%c;
		ind[ B[0] ] = 0;
		bool solve = 0;
		for( int i = 1 ; i < n ; ++i )
		{
			B[i] = (B[i-1] + A[i])%c;
			if( ind[ B[i] ] == -1 )
				ind[ B[i] ] = i;
			else
			{
				for( int j = ind[B[i]] + 1 ; j <= i ; ++j )
					printf( "%d%s" , j + 1 , (j==i?"\n":" " ) );
				solve = 1;
				break;
			}
		}
		if( !solve )
			REP( i , n )
				if( !B[i] )
				{
					for( int j = 0 ; j <= i ; ++j )printf( "%d%s" , j + 1 , (j==i?"\n":" " ) );
					break;
				}
	}
}


