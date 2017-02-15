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

#define test() puts("************test************");
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;

struct Node{
	int val , x , y;
	Node(){ val = x = y = 0;}
	Node( int val , int x , int y ) : val( val ) , x( x ) , y( y ){}
};
bool operator < ( const Node &a , const Node &b ){
	if(a.val != b.val)return a.val < b.val;
	if(a.x != b.x)return a.x < b.x;
	return a.y < b.y;
}
void fix( map< int , int > &mapa , int x ){
	mapa[ x ]--;
	if( !mapa[ x ] ) mapa.erase( x );
}
int main(){
	int n;
	while( sc( n ) == 1 ){
		vi L( n );
		REP( i , n ) sc( L[ i ] );
		vvi T( n );
		vector< Node > V;
		REP( i , n ){
			T[ i ].resize( L[ i ] );
			REP( j , L[ i ] ) {
				int x;	
				sc( x );
				T[ i ][ j ] = x;
				V.pb( Node( x , i , j ) );
			}
		}
		int ans = INT_MAX;
		sort( all( V ) );
		map< int , int > mapa;
		int lo = -1 , hi = -2;
		for( int i = 0 , j = -1 ; i < SZ(V) ; ++i ){
			while( j + 1 < SZ(V) && SZ(mapa) < n ){
				mapa[ V[ j + 1 ].x ] ++;
				j ++;
			}
			int temp = V[ j ].val - V[ i ].val;
			if( SZ(mapa) == n && temp < ans	 ){
				lo = i , hi = j;
				ans = temp;
			}
			fix( mapa , V[ i ].x );
		}
		vi ind( n , -1 );
		for( int i = lo ; i <= hi ; ++i )
			if( ind[ V[ i ].x ] == -1 ) ind[ V[ i ].x ] = V[ i ].y;
		printf( "%d\n" , ans );
		
		REP( i , n ) printf( "%d%c" , ind[ i ] + 1 , (i + 1 == n) ? 10 : 32 );
	}
}


