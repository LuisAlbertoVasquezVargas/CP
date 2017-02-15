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

#define test() cout << "hola q hace" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;


typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef vector< vvpii > vvvpii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector< vvvi > vvvvi;

void fix( string &s ){
	for( auto &x : s ) x -= 'A' - 1;
}
ll POT[ 2 ][ 40 * 40 + 5 ];
vi MOD = {1000000007LL , 1000000009LL};
vvvi generate( vi &v , int n ){
    vvvi T( n , vvi( n ) );
    for( int i = 0 ; i < n ; ++i ){
    	vi H( 2 );
        for( int j = i ; j < n ; ++j ){
    		REP( k , 2 ) H[ k ] = ((ll)H[ k ] * 31LL + v[ j ])%MOD[ k ];
            T[ i ][ j ] = H;
        }
    }
    return T;
}
void mySort( vpii &a , vpii &b ){
    vector< pair< pii , pii > > v;
    REP( i , SZ(a) ) v.pb( mp(a[ i ] , b[ i ]) );
    sort( all( v ) );
    REP( i , SZ(a) ) a[ i ] = v[ i ].fi , b[ i ] = v[ i ].se;
}

void generate( vvi &T , int n , int m , vvvpii &R , vvvpii &S ){
    vvvvi P( n );
    //test();
    
    REP( i , n ) P[ i ] = generate( T[ i ] , m );	
	R = vvvpii( n + 1 , vvpii( m + 1 ) );
	S = vvvpii( n + 1 , vvpii( m + 1 ) );
	
	for( int X1 = 0 ; X1 < m ; ++X1 )
		for( int X2 = X1 ; X2 < m ; ++X2 ){
			int len2 = X2 - X1 + 1;		
			vll b = { POT[ 0 ][ len2 ] , POT[ 1 ][ len2 ] };
			for( int Y1 = 0 ; Y1 < n ; ++Y1 ){
				vll H( 2 );
				for( int Y2 = Y1 ; Y2 < n ; ++Y2 ){
					REP( i , 2 )
						H[ i ] = ((ll)H[ i ] * b[ i ] + P[ Y2 ][ X1 ][ X2 ][ i ] )%MOD[ i ];
					
					int len1 = Y2 - Y1 + 1;
					R[ len1 ][ len2 ].pb( mp( H[ 0 ] , H[ 1 ] ) );
					S[ len1 ][ len2 ].pb( mp( Y1 , X1 ) );
				}
			}
		}
	
	REP( i , n + 1 ) REP( j , m + 1 ) mySort( R[ i ][ j ] , S[ i ][ j ] );
}
int main(){
	
	REP( i , 2 ) POT[ i ][ 0 ] = 1;
	REP( i , 2 )for( int len = 1 ; len <= 40 * 40 ; ++len )
		POT[ i ][ len ] = (POT[ i ][ len - 1 ] * 31LL)%MOD[ i ];
	
	freopen( "money.in" , "r" , stdin );
	freopen( "money.out" , "w" , stdout );
	
	vvi coord( 2 , vi( 2 ) );
	while( cin >> coord[ 0 ][ 0 ] ){
		vvvi T( 2 );
		REP( i , 2 ){
			REP( j , 2 ) {
				if( !i && !j ) continue; 
				cin >> coord[ i ][ j ];
			}
			string s;
			REP( a , coord[ i ][ 0 ] ) {
				cin >> s;
				fix( s );
				vi vec( all( s ) );
				T[ i ].pb( vec );
			}
		}
		vector< vvvpii > P( 2 );
		vector< vvvpii > I( 2 );
		REP( i , 2 ) generate( T[ i ] , coord[ i ][ 0 ] , coord[ i ][ 1 ] , P[ i ] , I[ i ] );

		int maxi = 0;
		int t = 0;
		pii p1 , p2 , p;
		for( int i = 0 ; i <= min( coord[ t ][ 0 ] , coord[ t ^ 1 ][ 0 ] ) ; ++i )
			for( int j = 0 ; j <= min( coord[ t ][ 1 ] , coord[ t ^ 1 ][ 1 ] ) ; ++j )
				REP( k , SZ( P[ t ][ i ][ j ] ) ){
					auto x = P[ t ][ i ][ j ][ k ];
					if( binary_search( all( P[ t ^ 1 ][ i ][ j ] ) , x ) ){
						if( i * j <= maxi ) continue;
						maxi = i * j;
						p = mp( i , j );
						auto vec = P[ t ^ 1 ][ i ][ j ];
						int pos = lower_bound( all( vec ) , x ) - vec.begin();
						p1 = I[ t ][ i ][ j ][ k ];
						p2 = I[ t ^ 1 ][ i ][ j ][ pos ];
					}
				}
		if( maxi == 0 ){
			puts( "0 0" );
			continue;
		}
		printf( "%d %d\n" , (int)p.fi , (int)p.se );
		printf( "%d %d\n" , (int)(p1.fi + 1) , (int)(p1.se + 1) );
		printf( "%d %d\n" , (int)(p2.fi + 1) , (int)(p2.se + 1) );
	}
	
}


