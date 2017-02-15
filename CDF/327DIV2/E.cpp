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

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector< string > vs;

const int INF = INT_MAX/3;

vi dx = { 0 , 0 , 1 , -1 };
vi dy = { 1 , -1 , 0 , 0 };
const char OBSTACLE = '#';
const char FREECELL = '.';

bool valid( int a , int b ){
	return a >= 0 && a < b;
}
vvi bfs( char c , vs &S , int n , int m ){
	vvi dist( n , vi( m , INF ) );
	
	deque< pii > Q;
	REP( i , n )REP( j , m ){
		if( S[ i ][ j ] == c ){
			Q.push_front( mp( i , j ) );
			dist[ i ][ j ] = 0;
		}
	}
	
	while( !Q.empty() ){
		pii U = Q.front(); Q.pop_front();
		int x = U.fi , y = U.se;
		REP( k , 4 ){
			int nx = x + dx[ k ];
			int ny = y + dy[ k ];
			
			if( valid( nx , n ) && valid( ny , m ) && S[ nx ][ ny ] != OBSTACLE ){
				int w = (S[ nx ][ ny ] == FREECELL);
				if( dist[ x ][ y ] + w < dist[ nx ][ ny ] ){
					dist[ nx ][ ny ] = dist[ x ][ y ] + w;
					if( w == 0 ) Q.push_front( mp( nx ,  ny ) );
					else Q.push_back( mp( nx ,  ny ) );
				}
			}
		}
	}
	return dist;
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	int n , m;
	while( cin >> n >> m ){
		vs S( n );
		REP( i , n ) cin >> S[ i ];
		
		vvvi T( 3 );
		REP( k , 3 ) T[ k ] = bfs( '1' + k , S , n , m );
		
		int ans = INF;
		REP( i , n ) REP( j , m ){
			if( S[ i ][ j ] == OBSTACLE ) continue;
			ans = min( ans , T[ 0 ][ i ][ j ] + T[ 1 ][ i ][ j ] + T[ 2 ][ i ][ j ] - 2 * (S[ i ][ j ] == FREECELL) );
		}
		if( ans >= INF - 2 ) ans = -1;
		printf( "%d\n" , ans );
	}
}




