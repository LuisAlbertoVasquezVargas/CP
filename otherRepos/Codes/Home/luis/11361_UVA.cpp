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

int k , n ;
//int memo[12][2][100][100];
int DP[12][2][100][100];
int target[ 12 ];
/*
int dp( int pos , int menor , int mod1 , int mod2 )
{
	if( pos == n )return mod1 == 0 && mod2 == 0 ;
	int &dev = memo[pos][menor][mod1][mod2];
	if( dev == -1 )
	{
		dev = 0;
		if( menor )
		{
			for( int i = 0 ; i <= 9 ; ++i )
				dev += dp( pos + 1 , 1 , (mod1 + i)%k , (mod2*10+i)%k );
		}
		else
		{
			for( int i = 0 ; i <= target[pos] ; ++i )
				dev += dp( pos + 1 , i < target[pos] , (mod1 + i)%k , (mod2*10+i)%k );
		}
	}
	return dev;
}
*/
int f( int x )
{
	if( x == 0 )return 1;
	n = 0;
	while( x > 0 )
	{
		target[n++] = x%10;
		x/= 10;
	}
	reverse( target , target + n );
	REP( mod1 , k )REP( mod2 , k )REP( menor , 2 )
		DP[n][menor][mod1][mod2] =  mod1 == 0 && mod2 == 0;
	
	for( int pos = n - 1 ; pos >= 0 ; --pos )
		REP( mod1 , k )REP( mod2 , k )REP( menor , 2 )
		{
			int &dev = DP[pos][menor][mod1][mod2] = 0;
			for( int i = 0 ; i <= (menor?9:target[pos] ) ; ++i )
				dev += DP[ pos + 1 ][ ( menor? 1 : (i<target[pos]) ) ][ (mod1 + i)%k ][ (mod2*10+i)%k ];
		}
	/*
	clr( memo , -1 );
	return dp( 0 , 0 , 0 , 0 );
	*/
	return DP[0][0][0][0];
}
int main()
{
	int tc , a , b ;
	sc( tc );
	REP( t , tc )
	{
		scanf( "%d%d%d" , &a , &b , &k );
		if( k > 98 )
		{
			puts("0");
			continue;
		}
		int F = f( b ) , I = f( a - 1 );
		printf( "%d\n" , F - I );
	}
}



