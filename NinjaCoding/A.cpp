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

#define N 5

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int mat[ N + 1 ][ N + 1 ];
int vis[ N + 1 ][ N + 1 ];
int dx[] = { 0 , 0 , 1 , -1 };
int dy[] = { 1 , -1 , 0 , 0 };

bool valid( int x ){ return x >= 0 && x < N; }
void dfs( int x , int y ){
	vis[ x ][ y ] = 1;
	REP( k , 4 ){
		int nx = x + dx[ k ];
		int ny = y + dy[ k ];
		if( valid( nx ) && valid( ny ) && !vis[ nx ][ ny ] && !mat[ nx ][ ny ] )
			dfs( nx , ny );
	}
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		REP( i , N ) REP( j , N ) sc( mat[ i ][ j ] );
		REP( i , N ) REP( j , N ) vis[ i ][ j ] = 0;
		REP( k , N )if( !mat[ k ][ 0 ] ) dfs( k , 0 );
		REP( k , N )if( !mat[ 0 ][ k ] ) dfs( 0 , k );
		puts( vis[ N - 1 ][ N - 1 ] ? "COPS" : "ROBBERS" );
	}
}


