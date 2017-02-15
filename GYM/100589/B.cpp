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

#define N 1000000

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;

string getCad( int x ){
	return string( 1 , '0' + x );
}
string get( int a ){
	if( a >= 10 ) return getCad( a / 10 ) + getCad( a % 10 );
	return "0" + getCad( a );
}
string get( int a , int b , int c ){
	return get( a ) + ":" + get( b ) + ":" + get( c );
}
bool isPal( string s ){
	string t = s;
	reverse( all( t ) );
	return t == s;
}
int getPos( vector< string > &v , string &s ){
	return lower_bound( all( v ) , s ) - v.begin();
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	///24 , 60 , 60
	vector< string > A;
	REP( h , 24 ) REP( m , 60 ) REP( s , 60 ){
		A.pb( get( h , m , s ) );
	}
	vi AC( SZ(A) + 1 );
	REP( i , SZ( A ) )
		AC[ i + 1 ] = AC[ i ] + isPal( A[ i ] );
		
	//REP( i , 100 ) cout << isPal( A[ i ] ) << endl;
	int cases;
	cin >> cases;
	REP( tc , cases ){
		string a , b;
		cin >> a >> b;
		int pa = getPos( A , a ) , pb = getPos( A , b );
		printf( "%d\n" , AC[ pb + 1 ] - AC[ pa ] );
	}
}


