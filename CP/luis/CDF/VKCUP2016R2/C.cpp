#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP(i,n) for(int i = 0 ; i < n ; ++i)
#define clr(t , val) memset(t , val , sizeof(t))

#define mp make_pair
#define fi first
#define se second

#define all( v ) v.begin() , v.end()
#define SZ(v) ((int)v.size())
#define pb push_back

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef long long ll;
typedef vector< ll > vll;

int main(){
	int n , m , Q;
	while( sc( n ) == 1 ){
		sc( m ) , sc( Q );
		vector< vector< pair< int , int > > > T( n , vector< pair< int , int > >( m ) );
		int current = 0;
		vector< pair< int , int > > index( n * m );
		REP( i , n ) REP( j , m ){
			T[ i ][ j ] = mp( current , 0 );
			index[ current ] = mp( i , j );
		}
		vi TYPE( Q ) , R( Q ) , C( Q ) , X( Q ) , Y( Q ) , VAL( Q );
		REP( it , Q ){
			int type;
			sc( type );
			TYPE[ it ] = type;
			if( type == 1 ){
				int r;
				sc( r );
				r --;
				R[ it ] = r;
				vector< pair< int , int > > vec;
				REP( j , m ) vec.pb( T[ r ][ j ] );
				REP( j , m ) T[ r ][ j ] = vec[ (j + 1 + m)%m ];
			}else if( type == 2 ){
				int c;
				sc( c );
				c --;
				C[ it ] = c;
				vector< pair< int , int > > vec;
				REP( i , n ) vec.pb( T[ i ][ c ] );
				REP( i , n ) T[ i ][ c ] = vec[ (i + 1 + n)%n ];
			}else{
				int x , y , val;
				sc( x ) , sc( y ) , sc( val );
				x -- , y --;
				X[ it ] = x;
				Y[ it ] = y;
				VAL[ it ] = val;
				T[ x ][ y ].se = val;
			}
		}
		for( int it = Q - 1 ; it >= 0 ; --it ){
			int type = TYPE[ it ];
			if( type == 1 ){
				int r = R[ it ];
				vector< pair< int , int > > vec;
				REP( j , m ) vec.pb( T[ r ][ j ] );
				REP( j , m ) T[ r ][ j ] = vec[ (j - 1 + m)%m ];
			}else if( type == 2 ){
				int c = C[ it ];
				vector< pair< int , int > > vec;
				REP( i , n ) vec.pb( T[ i ][ c ] );
				REP( i , n ) T[ i ][ c ] = vec[ (i - 1 + n)%n ];
			}
		}
		REP( i , n ) REP( j , m ) printf( "%d%c" , T[ i ][ j ].se , (j + 1 == m ? 10 : 32) );
	}
}


