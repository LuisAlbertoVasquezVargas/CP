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

string tos(int n){
	string s;
	while( n ){
		s.pb( '0' + (n & 1) );
		n >>= 1;
	}
	reverse( all( s ) );
	return s;
}



int NEXT[ N + 5 ][ 2 ] , node , CNT[ N + 5 ];

void init(){
	node = 1;
	clr( CNT , 0 );
	clr( NEXT , 0 );
}
void add( string s , int n ){
	int p = 0;
	REP( i , n ){
		s[ i ] -= '0';
		if( !NEXT[ p ][ s[ i ] ] ) NEXT[ p ][ s[ i ] ] = node++;
		p = NEXT[ p ][ s[ i ] ];
		CNT[ p ] ++;
	}
}
int ans , tot , n;
void dfs( int u , int cur , int len ){
	//DEBUG( u );
	ans = min( ans , (tot - cur) + len * n - cur );
	
	if( NEXT[ u ][ 0 ] && NEXT[ u ][ 1 ] ){
		int v = NEXT[ u ][ 0 ];
		if( v ) dfs( v , cur + CNT[ v ] , len + 1 );
		return;
	}
	REP( i , 2 ){
		int v = NEXT[ u ][ i ];
		if( v ) dfs( v , cur + CNT[ v ] , len + 1 );
	}
}
int main(){
	while( sc( n ) == 1 ){
		int cur = 0;
		init();
		tot = 0;
		REP( i , n ){
			int x;
			sc( x );
			string s = tos( x );
			
			cur += SZ( s );
			add( s , SZ(s) );
		}
		ans = cur;
		tot = cur;
		dfs( 0 , 0 , 0 );
		printf( "%d\n" , ans );
	}
}

