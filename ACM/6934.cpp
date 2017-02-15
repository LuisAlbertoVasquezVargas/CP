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
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< string > vs;

int n , m;
vs T = { "123" , "456" , "789" , "*0*" };
vi vec;
vi dx = { 0 , 0 , 1 };
vi dy = { 0 , 1 , 0 };
bool valid( int a , int b ){ return a >= 0 && a < n && b >= 0 && b < m ;}
void dfs( int i , int j , int cur ){
	vec.pb( cur );
	REP( k , SZ(dx) ){
		int ni = i + dx[ k ];
		int nj = j + dy[ k ];
		int ncur = cur;
		if( k == 0 ) {
			ncur = cur * 10 + (T[ i ][ j ] - '0');
			if( cur == 0 && T[ i ][ j ] == '0' ) return;
		}else ncur = cur;
		if( valid( ni , nj ) && T[ ni ][ nj ] != '*' && ncur < 1000 )
			dfs( ni , nj , ncur );
	}
}
int main(){
	n = SZ( T ) , m = SZ( T[ 0 ] );
	dfs( 0 , 0 , 0 );
	sort( all( vec ) );
	vec.resize( unique( all( vec ) ) - vec.begin() );
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		int pos = upper_bound( all( vec ) , n ) - vec.begin();
		int best = INT_MAX , num = -1;
		for( int k = 0 ; k <= 1 ; ++k ){
			if( pos - k >= 0 && pos - k < SZ( vec ) ){
				int dist = abs( vec[ pos - k ] - n );
				if( dist < best ) best = dist , num = vec[ pos - k ];
			}
		}
		printf( "%d\n" , num );
	}
}




