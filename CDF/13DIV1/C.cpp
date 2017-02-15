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

#define N 5000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

vi A , B;
int n , m;
ll DP[ 2 ][ N + 5 ];

int main(){
	
	while( sc( n ) == 1 ){
		A = vi( n );
		REP( i , n ) sc( A[ i ] );
		B = A;
		sort( all( B ) );
		B.resize( unique( all( B ) ) - B.begin() );
		m = SZ( B );
		REP( last , m ) DP[ n & 1 ][ last ] = 0;
		for( int pos = n - 1 ; pos >= 0 ; --pos ){
			for( int last = m - 1 ; last >= 0 ; --last ){
				DP[ pos & 1 ][ last ] = LLONG_MAX/3;
				if( last + 1 < m ) DP[ pos & 1 ][ last ] = min( DP[ pos & 1 ][ last ] , DP[ pos & 1 ][ last + 1 ] );
				DP[ pos & 1 ][ last ] = min( DP[ pos & 1 ][ last ] , (ll)abs( B[ last ] - A[ pos ] ) + DP[ (pos + 1)&1 ][ last ] );
			}
		}
		cout << DP[ 0 ][ 0 ] << '\n';
	}
}



