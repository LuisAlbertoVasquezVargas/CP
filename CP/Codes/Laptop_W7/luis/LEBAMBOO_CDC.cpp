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

#define N 55
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;
int A[ N ] , B[ N ];
int main()
{
	int tc;
	sc( tc );
	while( tc-- )
	{
		int n;
		sc( n );
		REP( i , n ) sc( A[ i ] );
		REP( i , n ) sc( B[ i ] );
		int a = 0 , b = 0;
		REP( i , n )
			if( A[ i ] < B[ i ] ) a += B[ i ] - A[ i ] ;
			else b += A[ i ] - B[ i ];
		if( n == 1 )
		{
			if( a ) puts( "-1" );
			else printf( "%d\n" , b );
		}
		else if( n == 2 )
		{
			if( A[ 0 ] + A[ 1 ] == B[ 0 ] + B[ 1 ] ) printf( "%d\n" , a );
			else puts( "-1" );
		}
		else
		{
			if( (a - b)%(n - 2) == 0 && a - b*( n - 1 ) >= 0 )
				printf( "%d\n" , ( a - b ) / ( n - 2 ) );
			else puts( "-1" );
		}
	}
}


