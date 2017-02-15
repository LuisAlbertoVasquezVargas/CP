#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 10000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef pair< ll , ll > pll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< ll > vll;
typedef vector< ull > vull;

int P[ N + 5 ];
int CT[ N + 5 ];
ll AC[ N + 5 ];
void init(){
	clr( P , -1 );
	clr( CT , 0 );
	for( int i = 2 ; i*i <= N ; ++i )
		if( P[ i ] == -1 )
			for( int j = i*i ; j <= N ; j += i )
				P[ j ] = i;
}
void primeFact( int x ){
	if( x == 1 ) return;
	while( 1 )
	{
		if( P[ x ] == -1 ){
			CT[ x ]++;
			return;
		}
		
		int p = P[ x ];
		CT[ p ] ++;
		while( x%p == 0 )x /= p;
		if( x == 1 ) return;
	}
}
int main()
{
	int n , Q , a , b , x ;
	while( sc( n ) == 1 )
	{
		init();
		REP( i , n ) sc( x ) , primeFact( x );
		sc( Q );
		REP( i , N + 1 ) AC[ i + 1 ] = AC[ i ] + CT[ i ];
		/*REP( i , 10 ) cout << AC[ i ] << " ";
		cout << endl;
		cout << AC[ N ] << " " << AC[ N + 1 ] << endl; 
		*/
		while( Q-- )
		{
			sc( a ) , sc( b );
			if( a > N ) {
				puts( "0" );
				continue;
			}
			b = min( b , N );
			cout << AC[ b + 1 ] - AC[ a ] << '\n'; 
		}
	}
}



