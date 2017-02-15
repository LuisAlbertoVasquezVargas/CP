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

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector< string > vs;

vvi generate( vi T , int m ){
	int n = SZ( T ) ;
	vvi ans;
	REP( mask , 1 << m ){
		vi vec( n );
		REP( i , n ){
			int mask2 = (mask ^ T[ i ] ^ (-1) );
			vec[ i ] += __builtin_popcount( mask2 ) - (32 - m);
			//DEBUG( vec[ i ] );
		}
		ans.pb( vec );
	}
	sort( all( ans ) );
	return ans;
}
vi complement( vi a , vi b ){
	vi c( SZ( a ) );
	REP( i , SZ(a) ) c[ i ] = b[ i ] - a[ i ];
	return c;
}

int generate2( vi T , vvi P , vi W , int m ){
	int n = SZ( T ) ;
	REP( mask , 1 << m ){
		vi vec( n );
		REP( i , n ){
			int mask2 = (mask ^ T[ i ] ^ (-1) );
			vec[ i ] += __builtin_popcount( mask2 ) - (32 - m);
		}
		if( binary_search( all( P ) , complement( vec , W ) ) ) return mask;
	}
	return -1;
}

int main(){
	ios_base :: sync_with_stdio( 0 );
	int cases;
	cin >> cases;
	REP( tc , cases ){
		int n , m;
		cin >> n >> m;
		vs S( n );
		vi W( n );
		REP( i , n ) cin >> S[ i ] >> W[ i ];
		
		vvi T( 2 , vi( n ) );
		vi len = { (m/2) , m - (m/2) };
		REP( i , n )REP( j , m ){
			int tope = 0;
			if( j >= m/2 ) tope = m/2;
			if( S[ i ][ j ] == '1' )
				T[ !(j < (m/2)) ][ i ] |= (1 << (j - tope));
		}
		vvvi P( 2 );
		REP( k , 2 ) P[ k ] = generate( T[ k ] , len[ k ] );
		
		int ans = 0;
		
		vi s , t;
		for( auto x : P[ 0 ] ){
			vi y = complement( x , W );
			ans += upper_bound( all( P[ 1 ] ) , y ) - lower_bound( all( P[ 1 ] ) , y );
		}
		
		
		if( ans == 1 ){
			int a = generate2( T[ 0 ] , P[ 1 ] , W , len[ 0 ] );
			int b = generate2( T[ 1 ] , P[ 0 ] , W , len[ 1 ] );
			REP( i , m/2 ) cout << ((a & (1 << i)) ? 1 : 0);
			REP( i , m - m/2 ) cout << ((b & (1 << i)) ? 1 : 0);
			cout << '\n';
			continue;
		}
		
		cout << ans << " solutions" << '\n';
	}
}





