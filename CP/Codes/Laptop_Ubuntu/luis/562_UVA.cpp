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

#define N 105
#define MAXVAL 505

int n;
int V[ N ];
/*int memo[ N*MAXVAL+ 1 ][ N ];
int dp( int value , int pos )// quiero saber si value se puede formar usando algun subconjunto de vpos ..... vn-1
{
	if( value == 0 ) return 1;
	if( pos == n ) return 0;
	int &dev = memo[ value ][ pos ];
	if( dev == -1 )
	{
		dev = dp( value , pos + 1 );
		if( value - V[ pos ]  >= 0 )
			dev |= dp( value - V[ pos ] , pos + 1 );
	}
	return dev;
}*/
//int DP[ N*MAXVAL+ 1 ][ N ];
//int DP[ N*MAXVAL+ 1 ][ 2 ];
bool DP[ N*MAXVAL+ 1 ];
int main()
{
	int tc;
	sc( tc );
	while( tc-- )
	{
		sc( n );
		REP( i , n ) sc( V[ i ] ) ;
		int sum = accumulate( V , V + n , 0 );
		//clr( memo , -1 );
		/*REP( value , sum + 1 ) DP[ value ][ n ] = 0;
		REP( pos , n + 1 ) DP[ 0 ][ pos ] = 1;
		
		for( int pos = n - 1 ; pos >= 0 ; pos-- )
			for( int value = 0 ; value <= sum ; ++value )
			{
				int &dev = DP[ value ][ pos ] = DP[ value ][ pos + 1 ];
				if( value - V[ pos ]  >= 0 )
					dev |= DP[ value - V[ pos ] ][ pos + 1 ];
			}
		REP( value , sum + 1 ) DP[ value ][ n&1 ] = 0;
		DP[ 0 ][ 0 ] = DP[ 0 ][ 1 ] = 1;
		
		for( int pos = n - 1 ; pos >= 0 ; pos-- )
			for( int value = 0 ; value <= sum ; ++value )
			{
				int &dev = DP[ value ][ pos&1 ] = DP[ value ][ (pos + 1)&1 ];
				if( value - V[ pos ]  >= 0 )
					dev |= DP[ value - V[ pos ] ][ (pos + 1)&1 ];
			}*/
		REP( value , sum + 1 ) DP[ value ] = 0;
		DP[ 0 ] = 1;
		
		for( int pos = n - 1 ; pos >= 0 ; pos-- )
			for( int value = sum - V[ pos ] ; value >= 0 ; --value )
				DP[ value + V[ pos ] ] |= DP[ value ];
		int ans = (1<<30);
		REP( i , sum + 1 )
			if( DP[ i ] )
				ans = min( ans , abs( sum - (i<<1) ) );
		printf( "%d\n" , ans );
	}
}
