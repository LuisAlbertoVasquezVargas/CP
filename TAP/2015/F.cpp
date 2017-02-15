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

#define N 50000
#define M 50

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

const int INF = (INT_MAX/2);

vi G[ N + 5 ];
int D[ M + 5 ][ M + 5 ];
bool forb[ N + 5 ][ M + 5 ];
bool used[ N + 5 ][ M + 5 ];
int memo[ N + 5 ][ M + 5 ];
int E;
int dp( int u , int p , int chosenp ){
	if( used[ u ][ chosenp ] ) return memo[ u ][ chosenp ];
	used[ u ][ chosenp ] = 1;
	int &dev = memo[ u ][ chosenp ] = INF;
	REP( k , E ){
		if( forb[ u ][ k ] ) continue;
		int cost = D[ chosenp ][ k ];
		for( auto v : G[ u ] )
			if( v != p ) cost += dp( v , u , k );
		dev = min( dev , cost );
	}
	return dev;
}
int main(){
	int n;
	while( sc( n ) == 1 ){
		sc( E );
		REP( i , n ) G[ i ].clear();
		REP( i , E + 1 ) REP( j , E + 1 ) D[ i ][ j ] = 0;
		REP( i , E ) REP( j , E ) sc( D[ i ][ j ] );
		vi fav( n , -1 );
		REP( i , E ){
			int m;
			sc( m );
			REP( j , m ){
				int x;
				sc( x );
				x --;
				fav[ x ] = i;
			}
		}
		REP( i , n ){
			if( fav[ i ] == -1 ){
				REP( j , E ) forb[ i ][ j ] = 0;
			}else{
				REP( j , E ) forb[ i ][ j ] = 1;
				forb[ i ][ fav[ i ] ] = 0;
			}
		}
		REP( i , n - 1 ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			G[ u ].pb( v );
			G[ v ].pb( u );
		}
		clr( used , 0 );
		printf( "%d\n" , dp( 0 , -1 , E ) );
	}
}


