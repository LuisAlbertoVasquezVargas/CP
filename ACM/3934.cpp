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

#define N 300

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< string > vs;

int n , m;
bool f( vi &A , vi &B ){
	REP( i , n ){
		if( A[ i ] == B[ 1 ] ) continue;
		if( A[ i ] == B[ 0 ] && A[ i ] == B[ 1 ] ) continue;
		if( A[ i ] < B[ 1 ] ) return 1;
	}
	return 0;
}
int main(){
	while( sc( n ) == 1 ){
		sc( m );
		if( !n && !m ) break;
		vi A( n ) , B( m );
		REP( i , n ) sc( A[ i ] );
		REP( i , m ) sc( B[ i ] );
		
		sort( all( B ) );
		puts( f( A , B ) ? "Y" : "N" );
	}
}


