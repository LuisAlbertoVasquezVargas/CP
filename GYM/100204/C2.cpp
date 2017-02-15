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

#define N 3000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< short > vsh;
typedef vector< vsh > vvsh;
typedef pair< int , short > pish;
typedef vector< pish > vpish;
typedef vector< vpish > vvpish;
typedef unsigned char uc;
typedef vector< unsigned char > vuc;
typedef vector< vuc > vvuc;
int A[ N + 5 ];
vvsh table ;
vvuc DP;

void rec( int i , int j ){
	while( 1 ){
		if( table[ j ][ i ] != -1 ){
			printf( "%d " , A[ i ] );
			int ni = j;
			int nj = table[ j ][ i ];
			i = ni;
			j = nj;
			continue;
		}
		printf( "%d %d\n" , A[ i ] , A[ j ] );
		return;
	}
}

int main(){
	//freopen( "fibsubseq.in" , "r" , stdin );
	//freopen( "fibsubseq.out" , "w" , stdout );
	int n;
	while( sc( n ) == 1 ){
		REP( i , n ) sc( A[ i ] );
		if( n == 1 ){
			puts( "1" );
			printf( "%d\n" , A[ 0 ] );
			continue;
		}
		/*
		vpii v;
		REP( i , n ) v.pb( mp( A[ i ] , i ) );
		sort( all( v ) );
		*/
		vvpish pref( n ) , suf( n );
		REP( i , n ){
			if( i ) pref[ i ] = pref[ i - 1 ];
			pref[ i ].pb( mp( A[ i ] , (short)i ) );
			for( int j = SZ( pref[ i ] ) - 2 ; j >= 0 ; --j )
				if( pref[ i ][ j ] > pref[ i ][ j + 1 ] ) swap( pref[ i ][ j ] , pref[ i ][ j + 1 ] );
				else break;
			//for( auto p : pref[ i ] ) cout << "(" << p.fi << " " << p.se << ") "; cout << endl;
		}
		
		for( int i = n - 1 ; i >= 0 ; --i ){
			if( i < n - 1 ) suf[ i ] = suf[ i + 1 ];
			suf[ i ].pb( mp( A[ i ] , (short)i ) );
			for( int j = SZ( suf[ i ] ) - 2 ; j >= 0 ; --j )
				if( suf[ i ][ j ] > suf[ i ][ j + 1 ] ) swap( suf[ i ][ j ] , suf[ i ][ j + 1 ] );
			//for( auto p : suf[ i ] ) cout << "(" << p.fi << " " << p.se << ") "; cout << endl;
		}
		table = vvsh( n );//stores dp( i , j ) in table( j , i ) just for comodity
		REP( j , n ){
			table[ j ] = vsh( n , -1 );
			if( j == 0 || j == n - 1 ) continue;
			//pref[ j - 1 ] , suf[ j + 1 ]
			REP( i , SZ( suf[j + 1] ) ) suf[ j + 1 ][ i ].fi -= A[ j ];
			
			for( int a = 0 , b = 0 ; a < SZ(pref[j - 1]) ; ++a ){
				//checking pref[j - 1][ a ]
				while( b < SZ(suf[j + 1]) && suf[j + 1][b].fi < pref[j - 1][ a ].fi )
					b ++;
				if( b >= 0 && b < SZ(suf[j + 1]) && pref[j - 1][ a ].fi == suf[ j + 1 ][ b ].fi ){
					short k = suf[ j + 1 ][ b ].se;
					short i = pref[ j - 1 ][ a ].se;
					table[ j ][ i ] = k;
				}
			}
			
			pref[ j - 1 ].clear();
			suf[ j + 1 ].clear();
		}
		//test();
		/*
		for( int i = 0 ; i < n ; ++i )
			for( int j = i + 1 ; j < n ; ++j ){
				int target = A[ i ] + A[ j ];
				// int pos = lower_bound( all( v ) , mp( target , j + 1 ) ) - v.begin();
				int pos = search( v , target , j + 1 );
				if( pos < n && v[ pos ].fi == target ) NEXT[ i ][ j ] = v[ pos ].se;
			}
		*/
		DP = vvuc( n , vuc( n ) );
		for( int i = n - 1 ; i >= 0 ; --i )
			for( int j = i + 1 ; j < n ; ++j ){
				DP[ i ][ j ] = 2;
				if( table[ j ][ i ] != -1 ) 
					DP[ i ][ j ] = max( DP[ i ][ j ] , (uc)(1 + DP[ j ][ table[ j ][ i ] ]) );
				/*
				if( NEXT[ i ][ j ] != -1 ) 
					DP[ i ][ j ] = max( DP[ i ][ j ] , (short)(1 + DP[ j ][ NEXT[ i ][ j ] ]) );
				*/
			}
		
		vi vec( 3 );
		for( int i = 0 ; i < n ; ++i )
			for( int j = i + 1 ; j < n ; ++j ){
				vi temp = { (int)DP[ i ][ j ] , i , j };
				vec = max( vec , temp );
			}
		printf( "%d\n" , vec[ 0 ] );
		rec( vec[ 1 ] , vec[ 2 ] );
	}
}


 
