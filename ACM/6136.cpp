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
typedef vector< string > vs;

int id[ N + 5 ];
int Find( int x ){ return id[ x ] = (id[ x ] == x ? x : Find( id[ x ] ));}
void Union( int u , int v ){
	int pu = Find( u ) , pv = Find( v );
	if( pu != pv ) id[ pu ] = pv;
}
int get( int i , int j , int n ){
	return i * (2 * n + 1) + j;
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	int n;
	while( cin >> n ){
		vs S( 2 * n - 1 , string( n , 'H' ) );//2n-1,n
		REP( i , 2 * n - 1 ) cin >> S[ i ];
		//DEBUG( SZ(S[ 0 ]) );
		REP( i , 2 * n ) REP( j , 2 * n + 1 ){//(2*n)x(2*n+1)
			int u = get( i , j , n );
			id[ u ] = u;
		}
		
		
		for( int i = 1 ; i <= 2 * n - 1 ; ++i ){
			for( int j = 1 ; j <= n ; ++j ){
				int x = i , y = 2 * j - ((i&1));
				//DEBUG2( x , y );
				int a = get( x - 1 , y - 1 , n );
				int b = get( x - 1 , y     , n );
				int c = get( x     , y - 1 , n );
				int d = get( x     , y     , n );
				if( S[ i - 1 ][ j - 1 ] == 'V' ){
					Union( a , c );
					Union( b , d );
				}else{
					Union( a , b );
					Union( c , d );
				}
			}
		}
		
		//(2*n)x(2*n+1)
		for( int j = 1 ; j + 1 < 2 * n + 1 ; j += 2 ){
			Union( get( 0 , j , n ) , get( 0 , j + 1 , n ) );
			Union( get( 2 * n - 1 , j , n ) , get( 2 * n - 1 , j + 1 , n ) );
		}
		
		for( int i = 1 ; i + 1 < 2 * n ; i += 2 ){
			Union( get( i , 0 , n ) , get( i + 1 , 0 , n ) );
		}
		
		for( int i = 0 ; i + 1 < 2 * n ; i += 2 ){
			Union( get( i , 2 * n , n ) , get( i + 1 , 2 * n , n ) );
		}
		int ans = 0;
		REP( i , 2 * n ) REP( j , 2 * n + 1 ){//(2*n)x(2*n+1)
			int u = get( i , j , n );
			if( Find( u ) == u ) ans ++;
		}
		printf( "%d\n" , --ans );
	}
}




