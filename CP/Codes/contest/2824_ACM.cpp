#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

typedef vector< string > vs;
typedef vector< int > vi;

void impr( vs v ){
	int nv = v.size();
	REP( i , nv ){
		int sz = v[ i ].size();
		REP( j , sz ) cout << v[ i ][ j ];
	}
	cout << endl;
}
int main()
{
	ios_base :: sync_with_stdio( 0 );
	string s , t;
	while( cin >> s ){
		if( s == "THEEND" ) break;
		cin >> t;
		int m = s.size() , n = t.size()/m;
		vs ans( n , string( m , '0' ) );
		int sz = 0;
		vi ind( m );
		for( char c = 'A' ; c <= 'Z' ; ++c )
			REP( i , m ) if( s[ i ] == c ) ind[ sz++ ] = i;
		REP( i , m ){
			string temp = t.substr( i*n , n );
			//cout << temp << endl;
			//cout << "ind : " << ind[ i ] << endl;
			REP( j , n ) ans[ j ][ ind[ i ] ] = temp[ j ];
		}
		impr( ans );
	}
}
