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
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

int id[ N + 5 ] , Rank[ N + 5 ] , LEN[ N + 5 ] , MINI[ N + 5 ] , MAXI[ N + 5 ];
int used[ N + 5 ];
int Find( int x ){ return id[ x ] = (id[ x ] == x ? x : Find( id[ x ] )); }
void Union( int u , int v ){
	int pu = Find( u ) , pv = Find( v );
	
	bool change = 0;
	if( Rank[ pu ] < Rank[ pv ] ) change = 0;
	else if( Rank[ pu ] > Rank[ pv ] ) change = 1;
	else{
		change = 1;
		Rank[pu]++;
	}
	if( change ) swap( pu , pv );
	id[ pu ] = pv;
	
	LEN[ pv ] += LEN[ pu ];
	MINI[ pv ] = min( MINI[ pv ] , MINI[ pu ] );
	MAXI[ pv ] = max( MAXI[ pv ] , MAXI[ pu ] );
}
void UNIQUE( vi &v ){
	sort( all( v ) );
	v.resize( unique( all( v ) ) - v.begin() );
}
int getId( vi &v , int x ){
	return lower_bound( all( v ) , x ) - v.begin();
}
int getId2( vi &v , int x ){
	return upper_bound( all( v ) , x ) - v.begin();
}
ll f( ll n ){ 
	return (n * (n + 1LL)) >> 1;
}
void add( int a , int b ){
	Union( a , b );
}
char cad[ 10 ];
int main(){
	int n , m;
	while( sc( n ) == 1 ){
		sc( m );
		REP( i , n ){
			id[ i ] = i;
			MINI[ i ] = MAXI[ i ] = i;
			LEN[ i ] = 1;
			used[ i ] = 0;
			Rank[ i ] = 1;
		}
		vpii v;
		vi A;
		REP( i , n ){
			int x;
			sc( x );
			A.pb( x );
			v.pb( mp( x , i ) );
		}
		sort( all( v ) );
		UNIQUE( A );
		vll F( SZ(A) , 0 );
		REP( i , n ){
			int ind;
			for( int j = i ; j < n ; ++j )
				if( v[ j ].fi == v[ i ].fi ) ind = j;
				else break;
			for( int j = i ; j <= ind ; ++j ){
				int pos = v[ j ].se;
				used[ pos ] = 1;
				if( pos - 1 >= 0 && used[ pos - 1 ] ) Union( pos , pos - 1 );
				if( pos + 1 < n && used[ pos + 1 ] ) Union( pos , pos + 1 );
			}
			ll ans = 0;
			for( int j = i ; j <= ind ; ++j ){
				int pos = v[ j ].se;
				int comp = Find( pos );
				int lo = MINI[ comp ] , hi = MAXI[ comp ] , len = LEN[ comp ];
				
				ans += f( len );
				int ind2;
				int last = -1;
				for( int k = j ; k <= ind ; ++k )
					if( v[ k ].se <= hi ) {
						if( last != -1 ) ans -= f( v[ k ].se - last - 1 );
						last = v[ k ].se;
						ind2 = k;
					}else break;
				ans -= f( v[ j ].se - lo );
				ans -= f( hi - v[ ind2 ].se );
				j = ind2;
			}
			//DEBUG2( v[ i ].fi , ans );
			F[ getId( A , v[ i ].fi ) ] = ans;
			i = ind;
		}
		vll pref( SZ(A) + 1 ) , suf( SZ( A ) + 1 );
		REP( i , SZ(A) ) pref[ i + 1 ] = pref[ i ] + F[ i ];
		for( int i = SZ(A) - 1 ; i >= 0 ; --i )
			suf[ i ] = suf[ i + 1 ] + F[ i ];
		
		REP( i , m ){
			char c , X;
			int K;
			scanf( "%s" , cad );
			c = cad[ 0 ];
			sc( K );
			scanf( "%s" , cad );
			X = cad[ 0 ];
			string s = "CD";
			if( X == 'C' ) swap( s[ 0 ] , s[ 1 ] );
			int turn;
			if( c == '=' ){
				if( !binary_search( all( A ) , K ) ) turn = 0;
				else{
					turn = F[ getId( A , K ) ] & 1;
				}
			}else if( c == '<' ){
				turn = pref[ getId( A , K ) ] & 1;
			}else{
				turn = suf[ getId2( A , K ) ] & 1;
			}
			putchar( s[ turn ] );
		}
		puts( "" );
	}
}


