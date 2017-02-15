#include<bits/stdc++.h>
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

typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef vector< vi > vvi;

const int n = 5;
bool royalFlush( vpii &a ){
	if( a[ 0 ].fi != a[ n - 1 ].fi ) return 0;
	if( a[ 0 ].se != 10 ) return 0;
	return 1;
}
void straightFlush( vpii a , int &ok , vi &best ){
	ok = 0;
	best.clear();
	if( a[ 0 ].fi != a[ n - 1 ].fi ){
		ok = 0;
		return;
	}
	REP( i , n ) if( a[ i ].se == 14 ) a[ i ].se = 1;
	sort( all( a ) );
	if( a[ 0 ].se + n - 1 != a[ n - 1 ].se ){
		ok = 0;
		return;
	}
	ok = 1;
	best = vi( 1 , a[ n - 1 ].se );
}
void four( vpii a , int &ok , vi &best ){
	ok = 0;
	best.clear();
	vi F( 15 );
	REP( i , SZ( a ) ) F[ a[ i ].se ] ++;
	int x = -1 , y = -1;
	for( int i = 1 ; i <= 14 ; ++i )
		if( F[ i ] == 4 ){
			ok = 1;
			x = i;
		}else{
			y = i;
		}
	if( !ok ) return;
	best.clear();
	best.pb( x );
	best.pb( y );
}

void fullHouse( vpii a , int &ok , vi &best ){
	ok = 0;
	best.clear();
	vi F( 15 );
	REP( i , SZ( a ) ) F[ a[ i ].se ] ++;
	int x = -1 , y = -1 , cx = 0 , cy = 0;
	for( int i = 1 ; i <= 14 ; ++i )
		if( F[ i ] == 3 ){
			cx ++;
			x = i;
		}else if( F[ i ] == 2 ){
			cy ++;
			y = i;
		}
	if( cx == 1 && cy == 1 ){
		ok = 1;
		best.clear();
		best.pb( x );
		best.pb( y );
	}
}

void flush( vpii a , int &ok , vi &best ){
	ok = 0;
	best.clear();
	if( a[ 0 ].fi != a[ n - 1 ].fi ) return;
	ok = 1;
	REP( i , SZ( a ) ) best.pb( a[ i ].se );
	sort( all( best ) );
	reverse( all( best ) );
}
bool fail( vi &v ){
	REP( i , n - 1 ) if( v[ i ] + 1 != v[ i + 1 ] ) return 1;
	return 0;
}
void straight( vpii a , int &ok , vi &best ){
	ok = 0;
	best.clear();
	vi v;
	REP( i , SZ( a ) ) v.pb( a[ i ].se );
	sort( all( v ) );
	if( !fail( v ) ){
		ok = 1;
		reverse( all( v ) );
		best = v;
		return;
	}
	if( v[ n - 1 ] == 14 ){
		v.pop_back();
		v.insert( v.begin() , 1 );
	}	
	
	if( !fail( v ) ){
		ok = 1;
		reverse( all( v ) );
		best = v;
		return;
	}

}
void three( vpii a , int &ok , vi &best ){
	ok = 0;
	best.clear();
	vi F( 15 );
	REP( i , SZ( a ) ) F[ a[ i ].se ] ++;
	int x = -1 , y = -1 , cx = 0 , cy = 0;
	for( int i = 1 ; i <= 14 ; ++i )
		if( F[ i ] == 3 ){
			cx ++;
			x = i;
		}
	if( cx == 1 ){
		ok = 1;
		best.clear();
		for( int i = 1 ; i <= 14 ; ++i )
			if( i == x ) continue;
			else{
				REP( j , F[ i ] ) best.pb( i );
			}
		best.pb( x );
		reverse( all( best ) );
		return;
	}
}

void twoPairs( vpii a , int &ok , vi &best ){
	ok = 0;
	best.clear();
	vi F( 15 );
	REP( i , SZ( a ) ) F[ a[ i ].se ] ++;
	int x = -1 , y = -1 , cx = 0 , cy = 0;
	for( int i = 1 ; i <= 14 ; ++i )
		if( F[ i ] == 2 && x == -1 ){
			cx ++;
			x = i;
		}else if( F[ i ] == 2 ){
			cy ++;
			y = i;
		}
	if( cx == 1 && cy == 1 ){
		if( x < y ) swap( x , y );
		ok = 1;
		best.clear();
		best.pb( x );
		best.pb( y );
		for( int i = 1 ; i <= 14 ; ++i )
			if( i == x ) continue;
			else if( i == y ) continue;
			else{
				REP( j , F[ i ] ) best.pb( i );
			}
		return;
	}
}
void onePair( vpii a , int &ok , vi &best ){
	ok = 0;
	best.clear();
	vi F( 15 );
	REP( i , SZ( a ) ) F[ a[ i ].se ] ++;
	int x = -1 , y = -1 , cx = 0 , cy = 0;
	for( int i = 1 ; i <= 14 ; ++i )
		if( F[ i ] == 2 ){
			cx ++;
			x = i;
		}
	if( cx == 1 ){
		ok = 1;
		best.clear();
		for( int i = 1 ; i <= 14 ; ++i )
			if( i == x ) continue;
			else{
				REP( j , F[ i ] ) best.pb( i );
			}
		best.pb( x );
		reverse( all( best ) );
		return;
	}
}
vi get( vpii a ){
	vi vec;
	REP( i , SZ( a ) ) vec.pb( a[ i ].se );
	sort( all( vec ) );
	reverse( all( vec ) );
	return vec;
}
int solve( vector< vpii > A ){
	vi ok( 2 ) ;
	vvi best( 2 );
	REP( i , 2 ) ok[ i ] = royalFlush( A[ i ] );
	
	REP( i , 2 ) if( ok[ i ] ) return i;
	
	REP( i , 2 ) straightFlush( A[ i ] , ok[ i ] , best[ i ] );
	
	if( ok[ 0 ] || ok[ 1 ] ){
		if( ok[ 0 ] && ok[ 1 ] ) return best[ 0 ] < best[ 1 ];
		REP( i , 2 ) if( ok[ i ] ) return i;
	}
	
	REP( i , 2 ) four( A[ i ] , ok[ i ] , best[ i ] );
	if( ok[ 0 ] || ok[ 1 ] ){
		if( ok[ 0 ] && ok[ 1 ] ) return best[ 0 ] < best[ 1 ];
		REP( i , 2 ) if( ok[ i ] ) return i;
	}
	
	REP( i , 2 ) fullHouse( A[ i ] , ok[ i ] , best[ i ] );
	if( ok[ 0 ] || ok[ 1 ] ){
		if( ok[ 0 ] && ok[ 1 ] ) return best[ 0 ] < best[ 1 ];
		REP( i , 2 ) if( ok[ i ] ) return i;
	}
	
	REP( i , 2 ) flush( A[ i ] , ok[ i ] , best[ i ] );
	if( ok[ 0 ] || ok[ 1 ] ){
		if( ok[ 0 ] && ok[ 1 ] ) return best[ 0 ] < best[ 1 ];
		REP( i , 2 ) if( ok[ i ] ) return i;
	}
	
	REP( i , 2 ) straight( A[ i ] , ok[ i ] , best[ i ] );
	if( ok[ 0 ] || ok[ 1 ] ){
		if( ok[ 0 ] && ok[ 1 ] ) return best[ 0 ] < best[ 1 ];
		REP( i , 2 ) if( ok[ i ] ) return i;
	}
	
	REP( i , 2 ) three( A[ i ] , ok[ i ] , best[ i ] );
	if( ok[ 0 ] || ok[ 1 ] ){
		if( ok[ 0 ] && ok[ 1 ] ) return best[ 0 ] < best[ 1 ];
		REP( i , 2 ) if( ok[ i ] ) return i;
	}
	
	REP( i , 2 ) twoPairs( A[ i ] , ok[ i ] , best[ i ] );
	if( ok[ 0 ] || ok[ 1 ] ){
		if( ok[ 0 ] && ok[ 1 ] ) return best[ 0 ] < best[ 1 ];
		REP( i , 2 ) if( ok[ i ] ) return i;
	}
	
	REP( i , 2 ) onePair( A[ i ] , ok[ i ] , best[ i ] );
	if( ok[ 0 ] || ok[ 1 ] ){
		if( ok[ 0 ] && ok[ 1 ] ) return best[ 0 ] < best[ 1 ];
		REP( i , 2 ) if( ok[ i ] ) return i;
	}
	
	vvi vec( 2 );
	REP( i , 2 ) vec[ i ] = get( A[ i ] );
	
	return vec[ 0 ] < vec[ 1 ];
}


int main(){
	vi mapa( 300 );
	for( int i = 2 ; i <= 9 ; ++i ) mapa[ '0' + i ] = i;
	mapa[ 'T' ] = 10;
	mapa[ 'J' ] = 11;
	mapa[ 'Q' ] = 12;
	mapa[ 'K' ] = 13;
	mapa[ 'A' ] = 14;
	
	ios_base :: sync_with_stdio( 0 );
	int cases;
	cin >> cases;
	REP( tc , cases ){
		string s;
		vector< vpii >A( 2 );
		REP( j , 2 ){
			REP( i , 5 ){
				cin >> s;
				int p = mapa[ s[ 0 ] ] , q = s[ 1 ];
				A[ j ].pb( mp( q , p ) );
			}
		}
		REP( j , 2 ) sort( all( A[ j ] ) );
		int winner = solve( A );	
		puts( winner ? "Player 2" : "Player 1" );
	}
}




