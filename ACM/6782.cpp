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

#define N 1000

typedef long long ll;
typedef long double ld;
typedef pair< int , int > pii;
typedef vector< int > vi;

struct Node{
	vi v;
	ld x;
	Node(){}
	Node( vi v , ld x ) : v( v ) , x( x ){}
};
bool operator < ( const Node &a , const Node &b ){
	return a.x < b.x;
}
vector< Node > V;
int can[ N + 5 ][ N + 5 ];
bool used[ N + 5 ][ N + 5 ][ 4 ];
int memo[ N + 5 ][ N + 5 ][ 4 ];
int n;
int dp( int pos , int last , int side ){
	if( pos == n ) return 0;
	if( used[ pos ][ last ][ side ] ) return memo[ pos ][ last ][ side ];
	used[ pos ][ last ][ side ] = 1;
	
	int &dev = memo[ pos ][ last ][ side ] = dp( pos + 1 , last , side );
	if( last == n ){
		REP( k , 3 ) dev = max( dev , 1 + dp( pos + 1 , pos , k ) );
	}else{
		if( V[ last ].x != V[ pos ].x ){
			REP( a , 3 )
				if( a != side ){
					REP( b , 3 ){
						if( V[ last ].v[ a ] == V[ pos ].v[ b ] )
							dev = max( dev , 1 + dp( pos + 1 , pos , b ) );
					}
				}
		}
	}
	return dev;
}

int main(){
	while( sc( n ) == 1 ){
		V.clear();
		REP( i , n ){
			vi vec( 3 );
			REP( k , 3 ) sc( vec[ k ] );
			sort( all( vec ) );
			double x;
			scanf( "%lf" , &x );
			V.pb( Node( vec , x ) );
		}
		sort( all( V ) );
		REP( i , n + 1 ) REP( j , n + 1 ) REP( k , 4 ) used[ i ][ j ][ k ] = 0;
		printf( "%d\n" , dp( 0 , n , 3 ) );
	}
}


