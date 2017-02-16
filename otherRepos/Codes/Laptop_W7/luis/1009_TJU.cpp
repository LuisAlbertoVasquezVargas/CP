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

using namespace std;

int L , n;
int v[ N ] , vis[ N ];
int res;
bool f( int pos , int sz )
{
	if( res ) return 1;
	if( pos == n ) return res = 1;
	if( sz == 0 ) sz = L;
	REP( i , n )
	{
		if( !vis[ i ] && v[ i ] <= sz )
		{
			vis[ i ] = 1;
			if( f( pos + 1, sz - v[ i ] ) ) return res = 1;
			vis[ i ] = 0;
			if( sz == v[ i ] || sz == L ) break;
		}
	}
	return 0;
}
int main()
{
	int t;
	while( sc( t ) == 1 && t )
	{
		n = 0;
		REP( i , t )
		{
			int x;
			sc( x );
			if( x > 50 )continue;
			v[ n++ ] = x;
		}
		if( n == 0 )
		{
			puts( "0" );
			continue;
		}
		sort( v , v + n );
		reverse( v , v + n );
		int S = accumulate( v , v + n , 0 ) , maxi = *max_element( v , v + n );
		for( L = maxi ; L <= S ; L++ )
		{
			if( S%L == 0 )
			{
				res = 0;
				clr( vis , 0 );
				if( f( 0 , L ) )
					break;
			}
		}
		printf( "%d\n" , L );
	}
}
