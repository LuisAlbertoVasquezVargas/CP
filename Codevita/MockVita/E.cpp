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
typedef vector< string > vi;
typedef vector< vi > vvi;

vi Inter( vi a , vi b ){
	vi c( SZ(a) + SZ(b) );
	vi :: iterator it = set_intersection( all( a ) , all( b ) , c.begin() );
	c.resize( it - c.begin() );
	return c;
}
vi Union( vi a , vi b ){
	vi c( SZ(a) + SZ(b) );
	vi :: iterator it = set_union( all( a ) , all( b ) , c.begin() );
	c.resize( it - c.begin() );
	return c;
}
vi Dif( vi a , vi b ){
	vi c( SZ(a) + SZ(b) );
	vi :: iterator it = set_difference( all( a ) , all( b ) , c.begin() );
	c.resize( it - c.begin() );
	return c;
}

int main(){
	ios_base :: sync_with_stdio( 0 );
	string dummy;
	int cases;
	cin >> cases;
	getline( cin , dummy );
	REP( tc , cases ){
		vvi T( 2 );
		REP( k , 2 ){
			string s;
			getline( cin , s );
			istringstream in( s );
			string x;
			while( in >> x ) T[ k ].pb( x );
		}
		REP( k , 2 ) sort( all( T[ k ] ) );

		vi a = Union( T[ 0 ] , T[ 1 ] );
		vi b = Inter( T[ 0 ] , T[ 1 ] );
		vi c = Dif( T[ 0 ] , T[ 1 ] );
		
		T.clear();
		T.pb( a );
		T.pb( b );
		T.pb( c );
		REP( k , 3 ){
			if( !SZ(T[ k ]) ){
				cout << "Empty List\n";
				continue;
			}
			REP( i , SZ(T[ k ]) ) cout << T[ k ][ i ] << char( (i + 1 == SZ( T[ k ] ) ) ? 10 : 32 );
		}
	}
}


