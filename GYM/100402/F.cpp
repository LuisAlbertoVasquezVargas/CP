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

#define N 500000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef vector< string > vs;

string g( string s ){
	char mini = *min_element( all( s ) );
	int freq = count( all( s ) , mini );
	if( freq == SZ( s ) ) return s;
	vs vec;
	REP( i , SZ( s ) ){
		if( s[ i ] == mini ) continue;
		int ind;
		string cad;
		for( int j = i ; j < SZ(s) ; ++j )
			if( s[ j ] != mini ) cad.pb( s[ j ] ) , ind = j;
			else break;
		vec.pb( cad );
		i = ind;
	}
	reverse( all( vec ) );
	REP( i , SZ( vec ) - 1 ) reverse( all( vec[ i ] ) );
	string ans;
	REP( i , SZ( vec ) - 1 ) ans += vec[ i ];
	ans += g( vec.back() );
	ans += string( freq , mini );
	return ans;
}
string rev( string s ){
	reverse( all( s ) );
	return s;
}
string f( string s ){
	char mini = *min_element( all( s ) );
	int freq = count( all( s ) , mini );
	if( freq == SZ( s ) ) return s;
	vs vec;
	REP( i , SZ( s ) ){
		if( s[ i ] == mini ) continue;
		int ind;
		string cad;
		for( int j = i ; j < SZ(s) ; ++j )
			if( s[ j ] != mini ) cad.pb( s[ j ] ) , ind = j;
			else break;
		vec.pb( cad );
		i = ind;
	}
	string ans = string( freq , mini );
	ans += rev( g( vec[ 0 ] ) );
	REP( i , SZ( vec ) ){
		if( !i ) continue;
		ans += vec[ i ];
	}
	return ans;
}
char S[ N + 5 ];
int main(){
	freopen( "prefixes.in" , "r" , stdin );
	freopen( "prefixes.out" , "w" , stdout );
	
	while( scanf( "%s" , S ) == 1 ){
		int n = strlen( S );
		string s( S , S + n );
		cout << f( s ) << '\n';
	}
}


