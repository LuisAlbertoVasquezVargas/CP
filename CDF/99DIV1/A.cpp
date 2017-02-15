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

#define test() cerr << "hola q hace" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 100000

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< string > vs;
typedef vector< vs > vvs;

string vow = "aeiou";
bool isvowel( char c ){
	for( auto x : vow )
		if( x == c ) return 1;
	return 0;
}
int K;
bool rima( string &s , string &t ){
	int pos = -1 , len;
	int match = K;
	for( int i = SZ(s) - 1 ; i >= 0 ; --i ){
		if( isvowel( s[ i ] ) ){
			match --;
			if( !match ){
				pos = i;
				len = SZ(s) - i;
				break;
			}
		}
	}
	if( pos == -1 ) return 0;
	if( SZ(t) < len ) return 0;
	string cad1 = s.substr( SZ( s ) - len );
	string cad2 = t.substr( SZ( t ) - len );
	return cad1 == cad2;
}
string get( vs &v , int K ){
	if( rima( v[ 0 ] , v[ 1 ] ) && rima( v[ 0 ] , v[ 2 ] ) && rima( v[ 0 ] , v[ 3 ] ) ) return "aaaa";
	if( rima( v[ 0 ] , v[ 1 ] ) && rima( v[ 2 ] , v[ 3 ] ) ) return "aabb";
	if( rima( v[ 0 ] , v[ 2 ] ) && rima( v[ 1 ] , v[ 3 ] ) ) return "abab";
	if( rima( v[ 0 ] , v[ 3 ] ) && rima( v[ 1 ] , v[ 2 ] ) ) return "abba";
	return "-1";
}
string f( string &a , string &b ){
	if( a == "aaaa" ) return b;
	if( b == "aaaa" ) return a;
	if( a == b ) return a;
	return "-1";
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	int n ;
	while( cin >> n >> K ){
		string ans = "aaaa";
		REP( i , n ){
			vs v;
			REP( j , 4 ){
				string s;
				cin >> s;
				v.pb( s );
			}
			string t = get( v , K );
			ans = f( ans , t );
		}
		if( ans == "-1" ){
			cout << "NO\n";
		}else{
			cout << ans << '\n';
		}
	}
}


