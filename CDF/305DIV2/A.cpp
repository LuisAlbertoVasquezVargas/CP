#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define SZ( v ) ((int)(v).size())
#define all( v ) v.begin() , v.end()

#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef vector< int > vi;

bool rev( string &s ){
	string t = s;
	reverse( all( t ) );
	return t == s;
}
string solve( string &s , int m , int K ){
	REP( i , K ){
		string t = s.substr( i * m , m );
		if( !rev( t ) ) return "NO";
	}
	return "YES";
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	string s;
	int K;
	while( cin >> s >> K ){
		int n = SZ( s );
		if( n % K ){
			cout << "NO\n" ;
			continue;
		}
		int m = n / K;
		cout << solve( s , m , K ) << "\n" ;
	}
}


