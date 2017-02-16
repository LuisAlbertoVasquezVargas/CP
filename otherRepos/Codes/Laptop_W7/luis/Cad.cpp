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

#define N 101
#define MOD 12345678
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

char s[ N ];
int memo[ N ][ N ];
int n;
int dp( int I , int J )
{
	if( I == J ) return 1;
	if( J == I + 1 ) return (s[ I ] == s[ J ] ? 3 : 2);
	if( J < I ) return 0;
	int &dev = memo[ I ][ J ];
	if( dev == -1 )
	{
		dev = ( dp( I + 1 , J ) + dp( I , J - 1 ) )%MOD;
		if( s[ I ] == s[ J ] ) dev = ( 2*dp( I + 1 , J - 1 ) )%MOD;
	}
	return dev;
}

int main()
{
	while( sc( n ) == 1 )
	{
		scanf( "%s" , s );
		clr( memo , -1 );
		printf( "%d\n", (dp( 0 , n - 1 ) - n + MOD)%MOD );		
	}
}


