#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ(v) ((int)v.size())

#define mp make_pair
#define fi first
#define se second

typedef vector< int > vi;
typedef long long ll;

ll f( ll n ){
	return ( n * (n - 1) )>>1;
}
int main(){
	string s;
	while( getline( cin , s ) ){
		int n = SZ( s );
		ll ans = 0;
		REP( i , n ){
			if( !isdigit( s[ i ] ) ) continue;
			int ind;
			vi F( 3 );
			int ac = 0;
			F[ ac ] ++;
			for( int j = i ; j < n ; ++j )
				if( isdigit( s[ j ] ) ) ac = (ac + s[ j ] - '0')%3 , ind = j , F[ ac ] ++;
				else break;
			ans += f( F[ 0 ] ) + f( F[ 1 ] ) + f( F[ 2 ] );
			i = ind ;
 		}
		cout << ans << '\n';
	}
}



