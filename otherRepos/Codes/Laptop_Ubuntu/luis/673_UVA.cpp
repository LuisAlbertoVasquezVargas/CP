#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) ) 

#define SZ( v ) ((int)(v).size())
#define pb push_back

typedef vector< int>  vi;

int main(){
	ios_base :: sync_with_stdio( 0 );
	int cases;
	cin >> cases;
	string dummy;
	getline( cin , dummy );
	REP( tc , cases ){
		string s;
		getline( cin , s );
		vi STACK;
		REP( i , SZ( s ) ){
			if( SZ( STACK ) ){
				if( STACK.back() == '(' ){
					if( s[ i ] == ')' ) STACK.pop_back();
					else STACK.pb( s[ i ] );
				}else if( STACK.back() == '[' ){
					if( s[ i ] == ']' ) STACK.pop_back();
					else STACK.pb( s[ i ] );
				}else{
					STACK.pb( s[ i ] );
				}
			}else STACK.pb( s[ i ] );
		}
		cout << ( !SZ( STACK ) ? "Yes" : "No") << '\n';
	}
}


