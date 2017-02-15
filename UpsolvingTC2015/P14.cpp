#include<bits/stdc++.h>
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

int B = 26;
int Hash( string &s ){
	int ans = 0;
	for( auto c : s )
		ans = (ans * B + c - 'A');
	//DEBUG( ans );
	return ans;
}
int n = 6 , m = 5;
string cad;
vector< int > T;
void dfs( int pos , vector< string > &S ){
	if( pos == m ){
		T.pb( Hash( cad ) );
		return;
	}
	for( int i = 0 ; i < n ; ++i ){
		cad.pb( S[ i ][ pos ] );
		dfs( pos + 1 , S );
		cad.pop_back();
	}
}
vi inter( vi &a , vi &b ){
	set< int > SET( all( a ) );
	vi c;
	for( auto x : b )
		if( SET.count( x ) ) c.pb( x );
	sort( all( c ) );
	c.resize( unique( all( c ) ) - c.begin() );
	return c;
}
string deHash( int x ){
	string ans( m , 'A' );
	REP( i , m ){
		int r = x % B;
		ans[ i ] += r;
		x /= B;
	}
	reverse( all( ans ) );
	return ans;
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	int cases;
	cin >> cases;
	REP( tc , cases ){
		int K;
		cin >> K;
		vector< vector< string > > S( 2 , vector< string >( n ) );
		vector< vi > R( 2 );
		REP( it , 2 ){
			REP( i , n ) cin >> S[ it ][ i ];
			T.clear();
			dfs( 0 , S[ it ] );
			R[ it ] = T;
		}
		T = inter( R[ 0 ] , R[ 1 ] );
		/*
		for( auto x : T ) cout << x << " ";
		cout << endl;
		*/
		if( SZ( T ) < K ){
			cout << "NO\n";
			continue;
		}
		cout << deHash( T[ K - 1 ] ) << '\n';
	}
}


