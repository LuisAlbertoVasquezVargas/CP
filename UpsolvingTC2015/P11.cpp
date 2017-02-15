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

typedef vector< int > vi;
typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;

int main(){
	string s;
	while( getline( cin , s ) ){
		if( s == "#" ) break;
		int ones = count( all( s ) , '1' );
		if( s.back() == 'e' ){
			s.pop_back();
			if( ones & 1 ) s.pb( '1' );
			else s.pb( '0' );
			cout << s << '\n';
		}else{
			s.pop_back();
			if( !(ones & 1) ) s.pb( '1' );
			else s.pb( '0' );
			cout << s << '\n';
		}
	}
}


