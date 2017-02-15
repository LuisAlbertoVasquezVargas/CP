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

typedef long long ll;
typedef vector< int > vi;
typedef pair< int , int > pii;
typedef vector< pii > vpii;

bool valid( string &s ){
	REP( i , SZ( s ) - 1 ) if( s[ i ] == s[ i + 1 ] ) return 0;
	return 1;
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	int cases;
	cin >> cases;
	REP( tc , cases ){
		string s;
		cin >> s;
		vi F( 26 );
		
		REP( i , SZ( s ) ) F[ s[ i ] - 'a' ] ++;
		
		vpii V;
		REP( i , 26 ) V.pb( mp( F[ i ] , i ) );
		sort( all( V ) );
		reverse( all( V ) );
		
		int C = V[ 0 ].fi;
		int R = (SZ( s ) - 1)/ C + 1;
		
		s.clear();
		REP( i , 26 ) REP( j , V[ i ].fi ) s.pb( 'a' + V[ i ].se );
		
		string ans ;
		
		REP( j , C ) REP( i , R ){
			int pos = i * C + j;
			if( pos < SZ( s ) ) ans.pb( s[ pos ] );
		}
		if( !valid( ans ) ){
			cout << -1 << '\n';
			continue;
		}
		cout << ans << '\n';
	}
}


