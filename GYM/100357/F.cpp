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

void add( string &s , string t , char c ){
	if( s.empty() ) s = t;
	else{
		s = "(" + s + string( 1 , c ) + t + ")";
	}
}
void add2( string &s , string t , char c ){
	if( s.empty() ) s = t;
	else{
		s = s + string( 1 , c ) + t;
	}
}
string tos( int x ){
	if( x <= 9 ) return string( 1 , '0' + x );
	if( x == 20 ) return "20";
	return "1" + string( 1 , '0' + x % 10 );
}
string solve( int n , int m , int k ){
	string ans;
	for( int i = 0 ; i <= min( n , k ) ; ++i ){
		int j = k - i;
		if( j <= m ){
			string s;
			REP( k , i ) add2( s , "x" + tos( k + 1 ) , '|' );
			REP( k , j ) add2( s , "y" + tos( k + 1 ) , '|' );
			add( ans , s , '&' );
		}
	}
	return ans;
}

int main(){
	freopen( "merge.in" , "r" , stdin );
	freopen( "merge.out" , "w" , stdout );
	int n , m;
	while( sc( n ) == 1 ){
		sc( m );
		for( int i = 1 ; i <= n + m ; ++i ){
			string s = solve( n , m , i );
			printf( "%s\n" , s.c_str() );
			assert( SZ(s) <= 2000 );
		}
	}
}


