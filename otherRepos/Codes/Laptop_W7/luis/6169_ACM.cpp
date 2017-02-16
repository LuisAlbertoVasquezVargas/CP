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

int A[ 10 ];
int B[] = { 20 , 20 , 20 , 25 , 25 , 30 , 30 };
int main()
{
	while( 1 )
	{
		REP( i , 7 ) sc( A[ i ] );
		if( accumulate( A , A + 7 , 0 ) == 0 ) break;
		int ans = 0;
		for( int i = 0 ; i < 6 ; ++i )
		{
		//	cout << i << " * " << ans <<  endl;	
			if( !A[ i ] ) continue;
			if( B[ i ] == B[ i + 1 ] )
			{
				if( A[ i ] + A[ i + 1 ] < B[ i ] ) ans++ , A[ i ] = A[ i + 1 ] = 0;
				else{
					ans += ( A[ i ] + A[ i + 1 ] )/B[ i ];
					A[ i + 1 ] = ( A[ i ] + A[ i + 1 ] )%B[ i ];
				}
			}
			else
			{
				ans += A[ i ]/B[ i ];
				A[ i ]%= B[ i ];
				if( A[ i ] ) ans++ , A[ i + 1 ] = max( 0 , A[ i + 1 ] + A[ i ] - B[ i ] ) ;
				A[ i ] = 0;
			}
		}
		if( A[ 6 ] ) ans++;
		printf( "%d\n" , ans );
	}
}


