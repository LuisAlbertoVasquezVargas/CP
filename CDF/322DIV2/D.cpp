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
typedef vector< pii > vpii;
typedef vector< int > vi;

int SQ[ N + 1 ];

void solve( vpii x ){
	int S = 0;
	REP( i , 3 ) S += x[ i ].fi * x[ i ].se;
	if( SQ[ S ] == -1 ){
		puts( "-1" );
		return;
	}
	int n = SQ[ S ];
	REP( it0 , 2 ){
		if( it0 ) swap( x[ 0 ].fi , x[ 0 ].se );
		REP( it1 , 2 ){
			if( it1 ) swap( x[ 1 ].fi , x[ 1 ].se );
			REP( it2 , 2 ){
				if( it2 ) swap( x[ 2 ].fi , x[ 2 ].se );
				vi p = { 0 , 1 , 2 };
				do{
					vpii X;
					REP( i , 3 ) X.pb( x[ p[ i ] ] );
					if( X[ 0 ].se == n && X[ 1 ].se + X[ 2 ].se == n && X[ 1 ].fi == X[ 2 ].fi )
						if( X[ 0 ].fi + X[ 1 ].fi == n ){
							printf( "%d\n" , n );
							REP( i , n ){
								if( i < X[ 0 ].fi ){
									REP( j , n ) putchar( 'A' + p[ 0 ] );
									puts( "" );
								}else{
									REP( j , n )
										if( j < X[ 1 ].se ) putchar( 'A' + p[ 1 ] );
										else putchar( 'A' + p[ 2 ] );
									puts( "" );
								}
							}
							return;
						}
					
					if( X[ 0 ].fi == n && X[ 1 ].fi == n && X[ 2 ].fi == n )
						if( X[ 0 ].se + X[ 1 ].se + X[ 2 ].se == n ){
							printf( "%d\n" , n );
							REP( i , n ){
								REP( j , n )
									if( j < X[ 0 ].se ) putchar( 'A' + p[ 0 ] );
									else if( j < X[ 0 ].se + X[ 1 ].se ) putchar( 'A' + p[ 1 ] );
									else putchar( 'A' + p[ 2 ] );
								puts( "" );
							}
							return;
						}
				}while( next_permutation( all( p ) ) );
			}
		}
	}
	puts( "-1" );
}

int main(){
	clr( SQ , -1 );
	for( int i = 0 ; i * i <= N ; ++i ) SQ[ i * i ] = i;
	vpii x( 3 );
	while( cin >> x[ 0 ].fi >> x[ 0 ].se ){
		REP( i , 3 ){
			if( !i ) continue;
			cin >> x[ i ].fi >> x[ i ].se;
		}
		solve( x );		
	}
}




