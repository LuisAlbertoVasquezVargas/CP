#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define N 2000

#define DEBUG( x ) cout << #x << " " << (x) << endl;

typedef vector< int > vi;
typedef long long ll;
typedef pair< int , int > pii;
typedef vector< string > vs;

int dx[] = { 1 , 1 , 0 , -1 , -1 , -1 , 0 , 1 };
int dy[] = { 0 , 1 , 1  , 1 , 0  , -1 , -1, -1 };

bool valid( int a , int b ){ return a >= 0 && a < b ; }

bool needed( int x , int y , int n , int m , vs &S ){
	if( !valid( x , n ) ) return 0;
	if( !valid( y , m ) ) return 0;
	for( int i = 0 ; i < 8 ; i += 2 ){
		int cnt = 0;
		REP( j , 3 ){
			int nx = x + dx[ (i + j)%8 ];
			int ny = y + dy[ (i + j)%8 ];
			if( valid( nx , n ) && valid( ny , m ) && S[ nx ][ ny ] == '.' ) cnt ++;
		}
		if( cnt == 3 ) return 1;
	}
	return 0;
}

int main(){
	ios_base :: sync_with_stdio( 0 );
	int n , m;
	while( cin >> n >> m ){

		vs S( n );
		REP( i , n ) cin >> S[ i ];
		
		queue< pii > Q;
		REP( i , n ) REP( j , m )
			if( needed( i , j , n , m , S ) ) {
				S[ i ][ j ] = '.';
				Q.push( mp( i , j ) );
			}
			
		while( !Q.empty() ){
			pii node = Q.front() ; Q.pop();
			int x = node.fi , y = node.se;
			REP( k , 8 ){
				int nx = x + dx[ k ];
				int ny = y + dy[ k ];
				if( valid( nx , n ) && valid( ny , m ) && S[ nx ][ ny ] == '*' ){
					if( needed( nx , ny , n , m , S ) ){
						S[ nx ][ ny ] = '.';
						Q.push( mp( nx , ny ) );
					}
				}
			}
		}
		
		REP( i , n ) cout << S[ i ] << '\n';
	}
}


