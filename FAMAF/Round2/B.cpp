#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

bool isZero( string &s ){
	REP( i , SZ(s) - 1 )
		if( s[ i ] == s[ i + 1 ] ) return 1;
	REP( i , SZ(s) - 2 )
		if( s[ i ] == s[i + 2] ) return 1;
	return 0;
}
bool check( string &s ){
	int n = SZ( s );
	for( int i = n - 2 ; i >= n - 3 && i >= 0 ; --i )
		if( s[ i ] == s[ i + 1 ] ) return 1;
	for( int i = n - 3 ; i >= n - 4 && i >= 0 ; --i )
		if( s[ i ] == s[ i + 2 ] ) return 1;
	return 0;
}
int solve( string &s ){
	int n = SZ( s );
	int cnt = 0;
	for( char a = s[n - 2] ; a <= 'z' ; ++a )
		for( char b = ((a == s[n - 2]) ? s[n - 1] : 'a') ; b <= 'z' ; ++b ){
			s[ n - 2 ] = a;
			s[ n - 1 ] = b;
			if( check( s ) ) return cnt;
			cnt ++;
		}
	assert( 0 );
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	string s;
	while( cin >> s ){
		if( isZero( s ) ){
			cout << '0' << '\n';
			continue;
		}
		cout << solve( s ) << '\n';
	}
}



