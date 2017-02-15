#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

int n = 9;
bool used[ 10 ][ 100 ];
int memo[ 10 ][ 100 ];
int dp( int pos , int cur ){
	if( pos == n ) return cur == 0 ;
	if( used[ pos ][ cur ] ) return memo[ pos ][ cur ];
	used[ pos ][ cur ] = 1;
	int &dev = memo[ pos ][ cur ] = 0;
	for( int i = 0 ; i <= 9 ; ++i )
		if( cur - i >= 0 ) dev += dp( pos + 1 , cur - i );
	return dev;
}
int main(){
	int S;
	cin >> S;
	clr( used , 0 );
	int ans = dp( 0 , S );
	if( S == 1 ) ans ++;
	cout << ans << '\n';
}
