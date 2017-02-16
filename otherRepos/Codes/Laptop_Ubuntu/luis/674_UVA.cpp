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

#define N 10005
#define nV 6

/*int memo[ N ][ nV ];
int n = 5;
int V[] = { 1 , 5 , 10 , 25 , 50 };
int dp( int total , int k ){
	if( total == 0 ) return 1;
	if( k == n )return 0;
	int &dev = memo[ total ][ k ];
	if( dev == -1 ){
		dev = dp( total , k + 1 );
		if( total - V[ k ] >= 0 )
		dev += dp( total - V[ k ] , k );
	}
	return dev;
}*/
int DP[ N ][ nV ];
int n = 5;
int V[] = { 1 , 5 , 10 , 25 , 50 };
int main()
{
	//clr( memo , -1 );
	REP( total , N ) DP[ total ][ n ] = 0;
	REP( k , n + 1 ) DP[ 0 ][ k ] = 1;
	for( int k = n - 1 ; k >= 0 ; --k )REP( total , N )
	{
		int &dev = DP[ total ][ k ] = DP[ total ][ k + 1 ];
		if( total - V[ k ] >= 0 )
			dev += DP[ total - V[ k ] ][ k ];
	}
	int money;
	while( scanf( "%d" , &money ) == 1 )
		printf( "%d\n" , DP[ money ][ 0 ] );
}

