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

#define N 500

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< string > vs;

int MOD;
/*
bool used[ N + 1 ][ N + 1 ][ N + 1 ];
int memo[ N + 1 ][ N + 1 ][ N + 1 ];
int dp( int lvl , int ct0 , int ct1 ){
	if( lvl == 0 ) return ct0 == 0 && ct1 == 0;
	if( used[ lvl ][ ct0 ][ ct1 ] ) return memo[ lvl ][ ct0 ][ ct1 ];
	used[ lvl ][ ct0 ][ ct1 ] = 1;
	int &dev = memo[ lvl ][ ct0 ][ ct1 ] = 0;
	for( int k = 0 ; k <= 2 ; ++k ){
		ll fact = (ll)comb(ct0 , k) * comb( ct1 , 2 - k );
		fact %= MOD;
		if( ct0 - k >= 0 && ct1 - (2 - k) >= 0 )
			dev = (dev + (ll)fact * dp( lvl - 1 , ct0 - k , ct1 - (2 - k) + k ) )%MOD;
	}
	return dev;
}
*/
int C[ N + 5 ][ 3 ];
int DP[ 2 ][ N + 5 ];
int main(){
	
	ios_base :: sync_with_stdio( 0 );
	int n , m;
	while( cin >> n >> m >> MOD ){
		for( int i = 0 ; i <= 2 ; ++i ) C[ i ][ i ] = C[ i ][ 0 ] = 1;
		for( int i = 0 ; i <= N ; ++i ) C[ i ][ 0 ] = 1;
		for( int i = 2 ; i <= N ; ++i )
			for( int j = 1 ; j <= min( i , 2 ) ; ++j ){
				C[ i ][ j ] = C[ i - 1 ][ j - 1 ] + C[ i - 1 ][ j ];
				if( C[ i ][ j ] >= MOD ) C[ i ][ j ] -= MOD;
			}
		vs S( m );
		REP( i , m ) cin >> S[ i ];
		vi F( 3 );
		REP( j , n ) {
			int cnt = 0;
			REP( i , m ) if( S[ i ][ j ] == '1' ) cnt ++;
			F[ cnt ] ++;
		}
		for( int ct0 = 0 ; ct0 <= n ; ++ ct0 ){
			int turn = n - m;
			int x = F[ 0 ] - ct0;
			int y = 2 * turn - x;
			int ct1 = F[ 1 ] - y + x;
			DP[ turn & 1 ][ ct0 ] = (ct0 == 0 && ct1 == 0);
		}
		for( int turn = n - m - 1 ; turn >= 0 ; -- turn )
			for( int ct0 = 0 ; ct0 <= F[ 0 ] ; ++ ct0 ){
				int x = F[ 0 ] - ct0;
				int y = 2 * turn - x;
				int ct1 = F[ 1 ] - y + x;
				DP[ turn & 1 ][ ct0 ] = 0;
				for( int k = 0 ; k <= 2 ; ++k ){
					int fact = ((ll)C[ ct0 ][ k ] * C[ ct1 ][ 2 - k ])%MOD;
					if( ct0 - k >= 0 && ct1 - (2 - k) >= 0 )
						DP[ turn & 1 ][ ct0 ] = (DP[ turn & 1 ][ ct0 ] + (ll)fact * DP[ (turn + 1)&1 ][ ct0 - k ] )%MOD;
				}
			}
		cout << DP[ 0 ][ F[ 0 ] ]<< '\n';
	}
}

