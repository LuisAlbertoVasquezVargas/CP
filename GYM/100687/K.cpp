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
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef long double ld;

const int n = 16 , m = 32;
string S[ 32 ];
int dx[] = { 0 , 0 , 1 , -1 };
int dy[] = { 1 , -1 , 0 , 0 };
string model = "><v^";
void Find( int &x , int &y , int c ){
	REP( i , n ) REP( j , m )
		if( S[ i ][ j ] == c ){
			x = i;
			y = j;
			return;
		}
	assert( 0 );
}
int main(){
	vi mapa( 256 );
	REP( i , 4 ) mapa[ model[ i ] ] = i;
	
	while( cin >> S[ 0 ] ){
		REP( i , n ){
			if( i ) cin >> S[ i ];
		}
		int hx , hy;
		Find( hx , hy , ':' );
		int tx , ty;
		Find( tx , ty , 'E' );
		string cad;
		cin >> cad;
		for( auto c : cad ){
			int id = mapa[ c ];
			hx = hx + dx[ id ];
			hy = hy + dy[ id ];
		}
		puts( (hx == tx && hy == ty) ? "Yes" : "No" );
	}
}


