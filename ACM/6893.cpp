#include <bits/stdc++.h>
using namespace std;
 
#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < (n) ; i++ )
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

#define N 2000

typedef long long ll;
typedef vector< ll > vll;
typedef vector< vll > vvll;
typedef vector< vvll > vvvll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< string > vs;

const int dim = 3;
vll MOD = { 1000000007LL , 1000000009LL , 1000000021LL };
const ll B = 3;

ll POT[ dim ][ N + 5 ];
vvll getHash( string &s ){
	int n = SZ( s );
	vvll T( dim , vll( n + 1 ) );
	REP( k , dim ){
		REP( i , n ) {
			ll val = (s[ i ] == 'o' ? 1 : 2);
			T[ k ][ i + 1 ] = (T[ k ][ i ] * B + val)%MOD[ k ];
		}
	}
	return T;
}
vll getSub( vvll &hash , int lo , int hi ){
	vll ans( dim );
	REP( k , dim ) {
		ans[ k ] = (hash[ k ][ hi + 1 ] - hash[ k ][ lo ] * POT[ k ][ hi - lo + 1 ])%MOD[ k ];
		if( ans[ k ] < 0 ) ans[ k ] += MOD[ k ];
	}
	return ans;
}
int R[ 2 ] , C[ 2 ];

int f( vvll p , vvll t ){
    int np = p.size() , nt = t.size();
    vi T( np + 1 );
    int j = T[ 0 ] = -1;
    REP( i , np ){
        while( j != -1 && p[ i ] != p[ j ] ) j = T[ j ];
        T[ i + 1 ] = ++j;
    }
    //KMP matcher
    //SPOJ 32. A Needle in the Haystack
    int ans = 0;
    j = 0;
    REP( i , nt ){
        while( j != -1 && ( j == np || t[ i ] != p[ j ] ) ) j = T[ j ];
        j ++;
        if( j == np ) ans ++;
    }
    return ans;
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	REP( k , dim ){
		POT[ k ][ 0 ] = 1;
		for( int i = 1 ; i <= N ; ++i )
			POT[ k ][ i ] = (POT[ k ][ i - 1 ] * B) % MOD[ k ];
	}
	while( cin >> R[ 0 ] >> C[ 0 ] ){
		REP( i , 2 ){
			if( !i ) continue;
			cin >> R[ i ] >> C[ i ];
		}
		vector< vs > T( 2 );
		REP( i , 2 ){
			T[ i ].resize( R[ i ] );
			REP( k , R[ i ] ) cin >> T[ i ][ k ];
		}
		vvll pat( R[ 0 ] );
		REP( i , R[ 0 ] ) {
			auto vec = getHash( T[ 0 ][ i ] );
			vll v( dim );
			REP( k , dim ) v[ k ] = vec[ k ].back();
			pat[ i ] = v;
			//DEBUG( pat[ i ][ 0 ] );
		}
		vvvll text( R[ 1 ] );
		REP( i , R[ 1 ] ) text[ i ] = getHash( T[ 1 ][ i ] );
		int ans = 0;
		for( int j = 0 ; j + C[ 0 ] - 1 < C[ 1 ] ; ++j ){
			vvll cur;
			for( int i = 0 ; i < R[ 1 ] ; ++i ){
				cur.pb( getSub( text[ i ] , j , j + C[ 0 ] - 1 ) );
			}
			ans += f( pat , cur );
		}
		cout << ans << '\n';
	}
}


