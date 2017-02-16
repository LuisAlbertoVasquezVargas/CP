#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define all( v ) v.begin() , v.end()
#define pb push_back

typedef vector< string > vs;

vs allStrings( string s )
{
	int ns = s.size();
	vs ans;
	REP( i , ns )
	{
		string t;
		for( int j = i ; j < ns ; ++j )
			t.pb( s[ j ] ) , ans.pb( t );
	}
	reverse( all( s ) );
	REP( i , ns )
	{
		string t;
		for( int j = i ; j < ns ; ++j )
			t.pb( s[ j ] ) , ans.pb( t );
	}
	sort( all( ans ) );
	return ans;
}
int main()
{
	int cases;
	cin >> cases;
	while( cases -- )
	{
		int n;
		cin >> n;
		string S[ n ];
		REP( i , n ) cin >> S[ i ];
		vector< string > V[ n ];
		REP( i , n ) V[ i ] = allStrings( S[ i ] );
		int maxi = 0;
		REP( i , V[ 0 ].size() ) {
			string t = V[ 0 ][ i ];
			bool ok = 1;
			for( int j = 1 ; j < n ; ++j ) 
				if( !binary_search( all( V[ j ] ) , t ) ) {
					ok = 0;
					break;
				}
			if( ok ) maxi = max( maxi , ( int ) t.size() ) ;
		}
		cout << maxi << '\n';
	}
}
