#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for( int i = 0 ; i < n ; ++i )

#define SZ(v) ((int)v.size())
#define pb push_back
#define all( v ) v.begin() , v.end()

typedef vector< int > vi;

int main(){
	ios_base :: sync_with_stdio( 0 );
	int cases;
	cin >> cases;
	REP( tc , cases ){
		string s;
		cin >> s;
		int n = SZ( s );
		vi F( 26 );
		for( auto c : s ) F[ c - 'a' ] ++;
		int maxi = *max_element( all( F ) );

		if( !(maxi <= (n - 1)/2 + 1) ){
			cout << "IMPOSSIBLE" << '\n';			
			continue;
		}
		string ans( n , '#' );
		vi ind;
		REP(i , n) ind.pb( i );
		
		REP( k , 26 ){
			
			int cur = 0;
			vi vis = vi( SZ( ind ) );
			REP( i , F[ k ] ){
				ans[ ind[ cur ] ] = 'a' + k;
				vis[ cur ] = 1;
				cur += 2;
			}
			vi nind;
			REP( i , SZ( ind ) )
				if( !vis[ i ] ) nind.pb( ind[ i ] );
			ind = nind;
		}
		
		cout << ans << '\n';
	}
}


