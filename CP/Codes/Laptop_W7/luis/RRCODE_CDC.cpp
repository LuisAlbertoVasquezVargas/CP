#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair< int , int >
#define pll pair< ll , ll >
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vi >
#define vpii vector< pii >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 1005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

int A[ N ];
char s[ 100 ];

int main()
{
	int tc;
	sc( tc );
	while( tc-- )
	{
		int n , k , ans , t;
		sc( n ) , sc( k ) , sc( ans );
		REP( i , n ) sc( A[ i ] );
		scanf( "%s" , s );
		if( k == 0 )
		{
			printf( "%d\n" , ans );
			continue;
		}
		if( s[ 0 ] == 'X' )
		{
			t = 0;
			REP( i , n ) t = ( t xor A[ i ] );
			if( !(k&1) ) t = 0;
			printf( "%d\n" , t xor ans );
		}
		else if( s[ 0 ] == 'O' )
		{
			t = 0;
			REP( i , n ) t = ( t bitor A[ i ] );
			printf( "%d\n" , t bitor ans );
		}
		else
		{
			t = -1;
			REP( i , n ) t = ( t bitand A[ i ] );
			printf( "%d\n" , t bitand ans );			
		}
	}
}
