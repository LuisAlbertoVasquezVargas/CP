#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define pb push_back
#define all( v ) v.begin() , v.end()

typedef vector< int > vi;

int getBoard( string p ){
	int np = p.size();
	vi T( np + 1 );
	int j = T[ 0 ] = -1;
	REP( i , np ){
		while( j != -1 && p[ i ] != p[ j ] ) j = T[ j ];
		T[ i + 1 ] = ++j;
	}
	return T[ np ];
}
string rev( string s ){ reverse( all( s ) ); return s; }
int main(){
	ios_base :: sync_with_stdio( 0 );
	string s;
	while( getline( cin , s ) ){
		string t = rev( s ) + "$" + s;
		int B = getBoard( t ) , ns = s.size();
		if( ns == B ) t = rev( s.substr( 0 , ns - getBoard( s ) ) );
		else t = rev( s.substr( 0 , ns - B ) );
		cout << s + t << '\n';
	}
}
