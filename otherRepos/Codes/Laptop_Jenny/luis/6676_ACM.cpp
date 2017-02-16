#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define all( v ) v.begin() , v.end()
#define pb push_back

#define N 9

typedef vector< string > vs;

void impr( vs &v ){
	int nv = v.size();
	cout << nv << '\n';
	REP( i , nv ) cout << v[ i ] << '\n';
}
bool f( string &s , string &t ){
	REP( i , N ) 
		if( s[ i ] == '*' ) continue;
		else if( s[ i ] != t[ i ] ) return 0;
	return 1;
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	int n;
	string s , t;
	while( cin >> s ){
		cin >> n;
		vs v;
		REP( i , n ) {
			cin >> t;
			if( f( s , t ) ) v.pb( t );
		}
		impr( v );
	}
}
