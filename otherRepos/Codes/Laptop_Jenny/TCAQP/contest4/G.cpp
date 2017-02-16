#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()

#define N 50000

typedef vector< int > vi;

vi E[ N + 5 ];

struct tri
{
	int x , y , id;
	tri(){}
	tri( int x , int y , int id ) : x( x ) , y( y ) , id( id ) {}
};
bool operator < ( const tri &a , const tri &b ){
	if( a.x != b.x ) return a.x < b.x;
	if( a.y != b.y ) return a.y < b.y;
	return a.id < b.id;
}

int main(){
	int cases , n , a , b , c ;
	sc( cases );
	while( cases -- ){
		sc( n );
		n -= 2;
		vector< tri > V;
		REP( i , n ){
			sc( a ) , sc( b ) , sc( c );
			//cout << "a  b  c " << endl;
			//cout << a << " " << b << " " << c <<endl;
			int A[] = { a , b , c };
			sort( A , A + 3 );
			a = A[ 0 ] , b = A[ 1 ] , c = A[ 2 ];
			V.pb( tri( a , b , i ) );
			V.pb( tri( a , c , i ) );
			V.pb( tri( b , c , i ) );						
		}
		sort( all( V ) );
		int m = V.size();
		REP( i , n ) E[ i ].clear();
		//REP( i , m ) cout << V[ i ].x << " " << V[ i ].y << " " << V[ i ].id << endl;
		REP( i , m - 1 )
			if( V[ i ].x == V[ i + 1 ].x && V[ i ].y == V[ i + 1 ].y ){
				int u = V[ i ].id , v = V[ i + 1 ].id;
				//cout << u << " " << v << endl;
				E[ u ].pb( v );
				E[ v ].pb( u );
			}
		if( E[ 0 ].size() == 1 ){
			puts( "YES" );
			continue;
		}
		//	cout << "not simple " << endl;
		puts( n&1 ? "NO" : "YES" );
	}
}
