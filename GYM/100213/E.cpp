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
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

#define cte 500
#define N 1005
#define M 1100005

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;

int id[ M + 5 ] , len[ M + 5 ];

int Find( int x ){ return id[ x ] = ( (id[ x ] == x) ? x : Find( id[ x ] ) );}
void Union( int u , int v ){
	int pu = Find( u ) , pv = Find( v );
	if( pu != pv ){
		len[ pv ] += len[ pu ];
		id[ pu ] = pv;
	}
}
bool valid( int x , int y ){
	return x >= 0 && x < N && y >= 0 && y < N;
}
bool used[ N + 1 ][ N + 1 ];
vvi dx = { { -1 , -1 , 0 , 0 , 1 , 1 } , { -1 , -1 , 0 , 0 , 1 , 1 } };
vvi dy = { { 0 , -1 , -1 , +1 , 0 , -1 } , { 0 , 1 , -1 , +1 , 0 , 1 } };
int getID( int x , int y ){
	return x * N + y;
}
void doit( int x , int y , int S ){
	if( used[ x ][ y ] ) return ;
	int t = x & 1 ;
	vi ind;
	REP( k , 6 ){
		int nx = x + dx[ t ][ k ];
		int ny = y + dy[ t ][ k ];
		if( valid( nx , ny ) && used[ nx ][ ny ] ){
			ind.pb( Find( getID( nx , ny ) ) );
		}
	}
	sort( all( ind ) );
	ind.resize( unique( all( ind ) ) - ind.begin() );
	int r = 0;
	for( auto id : ind ) r += len[ id ];
	if( r + 1 > S ) return;
	used[ x ][ y ] = 1;
	for( auto id : ind ) Union( id , getID( x , y ) );
}
int main(){
	
	freopen( "islands.in" , "r" , stdin );
	freopen( "islands.out" , "w" , stdout );
	
	int n , S;
	while( sc( n ) == 1 ){
		sc( S );
		REP( i , M ) id[ i ] = i , len[ i ] = 1;
		clr( used , 0 );
		REP( i , n ){
			int x , y;
			sc( x ) , sc( y );
			doit( x + cte , y + cte , S );
		}
		vi vec;
		REP( x , N ) REP( y , N ){
			int id = getID( x , y );
			if( used[ x ][ y ] && Find( id ) == id ){
				vec.pb( len[ id ] );
			}
		}
		sort(all( vec ));
		printf( "%d\n" , SZ(vec) );
		REP( i , SZ(vec) ) printf( "%d%c" , vec[ i ] , (i + 1 == SZ(vec)) ? 10 : 32 );
	}
}

