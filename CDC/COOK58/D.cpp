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

#define test puts("************test************");
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 18
#define BITS 31

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;

vvi dx = { {0 , 1} , {0 , -1} };
vvi dy = { {1 , 0} , {-1 , 0} };
int n;
vi T[ 2 ][ N + 1 ][ N + 1 ];
int A[N + 1][N + 1];
bool valid( int x , int y ){
	return x >= 0 && y >= 0 && x < n && y < n;
}
void back( int x , int y , int t , int cur ){
	if( x + y == n - 1 ){
		if( t ) cur ^= A[ x ][ y ];
		T[ t ][ x ][ y ].pb( cur );
		return;
	}
	REP( k , 2 ){
		int nx = x + dx[ t ][ k ];
		int ny = y + dy[ t ][ k ];
		if( !valid( nx , ny ) ) continue;
		int ncur = cur ^ A[ nx ][ ny ];
		back( nx , ny , t , ncur );
	}
}
int node;
int NEXT[ BITS * (1<<18) + 5 ][ 2 ];
void clear(){
	node = 1;
	clr( NEXT , 0 );
}
void add( int x ){
	int p = 0;
	for( int i = BITS - 1 ; i >= 0 ; --i ){
		int cur = (x & (1 << i)) > 0;
		if( !NEXT[ p ][ cur ] ) NEXT[ p ][ cur ] = node ++;
		p = NEXT[ p ][ cur ];
	}
}
int get( int x ){
	int p = 0 , ans = 0;
	for( int i = BITS - 1 ; i >= 0 ; --i ){
		int cur = (x & (1 << i)) > 0;
		if( NEXT[ p ][ cur ^ 1 ] ){
			ans |= (1 << i);
			p = NEXT[ p ][ cur ^ 1 ];
			continue;
		}
		if( NEXT[ p ][ cur ] ){
			p = NEXT[ p ][ cur ];
			continue;
		}
		assert( 0 );
	}
	return ans;
}
void impr( vi &v ){
	for( auto x : v ) cout << x << " "; cout << endl;
}
int main(){
	while( sc( n ) == 1 ){
		REP( i , n ) REP( j , n ) sc( A[ i ][ j ] );
		back( 0 , 0 , 0 , A[ 0 ][ 0 ] );
		back( n - 1 , n - 1 , 1 , A[ n - 1 ][ n - 1 ] );
		int ans = -1;
		REP( x , n ){
			int y = n - 1 - x;
			clear();
			//REP( t , 2 ) assert( SZ(T[ t ][ x ][ y ]) < BITS * (1<<18) + 5 );
			for( auto z : T[ 0 ][ x ][ y ] ) add( z );
			for( auto z : T[ 1 ][ x ][ y ] ) ans = max( ans , get( z ) );
		}		
		printf( "%d\n" , ans );
	}
}



