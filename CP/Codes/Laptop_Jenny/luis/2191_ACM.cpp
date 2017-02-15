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
#define sync ios_base:sync_with_stdio(false);

#define N 200005
#define NEUTRAL 0
#define v1 ( ( node << 1 ) + 1 )
#define v2 ( v1 + 1 )
#define med ( (a + b) >> 1 )
#define LEFT v1 , a , med
#define RIGHT v2 , med + 1 , b

int A[ N ];
int T[ 4*N ];

void build_tree( int node , int a , int b ){
	if( a == b ){
		T[ node ] = A[ a ];
		return;
	}
	build_tree( LEFT );build_tree( RIGHT );
	T[ node ] = T[ v1 ] + T[ v2 ];
}
void update( int node , int a , int b , int x , int val ){
	if( x > b || a > x ) return;
	if( a == b ){
		T[ node ] = val;
		return;
	}
	update( LEFT , x , val );update( RIGHT , x , val );
	T[ node ] = T[ v1 ] + T[ v2 ];
}
int query( int node , int a ,  int b , int lo , int hi ){
	if( lo > b || a > hi ) return NEUTRAL;
	if( a >= lo && hi >= b ) return T[ node ];
	return query( LEFT , lo , hi ) + query( RIGHT , lo , hi );	
}

int main()
{
	int n , x , y ;
	int tc = 0;
	char s[ 10 ];
	while( sc( n ) == 1 && n )
	{
		if( tc ) puts( "" );
		tc++;
		printf( "Case %d:\n" , tc );
		REP( i , n ) sc( A[ i ] );
		build_tree( 0 , 0 , n - 1 );
		while( scanf( "%s" , s ) == 1 )
		{
			if( s[ 0 ] == 'E' )break;
			scanf( "%d%d" , &x , &y );
			x-- , y--;
			if( s[ 0 ] == 'S' ) update( 0 , 0 , n - 1 , x , y + 1 );
			else printf( "%d\n", query( 0 , 0 , n - 1 , x , y ) );
		}
	}	
}

