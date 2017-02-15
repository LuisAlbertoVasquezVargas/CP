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

#define N 1000000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;

const int MOD = 1000000009;
string S[ 3 ];
vi mapa( 256 , -1 ) , lo( 256 , -1 ) , hi( 256 , -1 );
int getOp( int x , int y ){
	return (x < y) ? 0 : ( (x == y) ? 1 : 2 );
}
vvi T = { {0 , 0 , 0} , {0 , 1 , 2} , {2 , 2 , 2} };
int F[ 3 ][ 3 ][ 30 ][ 30 ][ 30 ][ 3 ][ 3 ];
int n;

int DP[ 2 ][ 2 ][ 2 ];
int main(){
	
	for( char c = 'a' ; c <= 'z' ; ++c )
		mapa[ c ] = c - 'a' + 1;
	mapa[ 'z' + 1 ] = 0;
	mapa[ '?' ] = 27;
	
	for( int i = 0 ; i <= 26 ; ++i )
		lo[ i ] = hi[ i ] = i;
	lo[ 27 ] = 1;
	hi[ 27 ] = 26;
	
	REP( cmp1 , 2 ) REP( cmp2 , 2 ) REP( a , 28 )REP( b , 28 ) REP( c , 28 ){
		for( int x = lo[ a ] ; x <= hi[ a ] ; ++ x )
			for( int y = lo[ b ] ; y <= hi[ b ] ; ++y )
				for( int z = lo[ c ] ; z <= hi[ c ] ; ++z ){
					int ncmp1 = getOp( x , y );
					int ncmp2 = getOp( y , z );
					F[ cmp1 ][ cmp2 ][ a ][ b ][ c ][ T[ cmp1 ][ ncmp1 ] ][ T[ cmp2 ][ ncmp2 ] ] ++;
				}
	}
	
	ios_base :: sync_with_stdio( 0 );
	int cases;
	cin >> cases;
	REP( tc , cases ){
		REP( i , 3 ) cin >> S[ i ];
		n = 0;
		REP( i , 3 ) n = max( n , SZ( S[ i ] ));
		REP( i , 3 ) S[ i ].resize( n , 'z' + 1 );
		
		REP( k , 3 ) REP( i , n ) S[ k ][ i ] = mapa[ S[ k ][ i ] ];
		
		//REP( cmp1 , 2 ) REP( cmp2 , 2 ) REP( pos , n ) used[ cmp1 ][ cmp2 ][ pos ] = 0;
		
		REP( cmp1 , 2 ) REP( cmp2 , 2 ) DP[ cmp1 ][ cmp2 ][ n & 1 ] = 0;
		DP[ 0 ][ 0 ][ n & 1 ] = 1;
		
		for( int pos = n - 1 ; pos >= 0 ; --pos )REP( cmp1 , 2 ) REP( cmp2 , 2 ){
			DP[ cmp1 ][ cmp2 ][ pos & 1 ] = 0;
			REP( ncmp1 , 2 ) REP( ncmp2 , 2 )
				DP[ cmp1 ][ cmp2 ][ pos & 1 ] = (DP[ cmp1 ][ cmp2 ][ pos & 1 ] + (ll)F[cmp1][cmp2][S[0][pos]][S[1][pos]][S[2][pos]][ncmp1][ncmp2] * DP[ ncmp1 ][ ncmp2 ][ (pos + 1)&1 ] ) % MOD;
		}
		cout << DP[ 1 ][ 1 ][ 0 ] << '\n';
	}
}
