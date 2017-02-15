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

#define N 10000

typedef long long ll;
typedef long double ld;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;

int P[ N + 5 ];
void sieve(){
	clr( P , -1 );
	P[ 0 ] = P[ 1 ] = 0;
	for( int i = 2 ; i * i <= N ; ++i )
		if( P[ i ] == -1 )
			for( int j = i * i ; j <= N ; j += i ) P[ j ] = i;
}
struct bigNum{
	vi vec;
	ld val;
	bigNum(){}
	bigNum( vi vec , ld val ) : vec( vec ) , val( val ){}
};
typedef vector< bigNum > vb;
typedef vector< vb > vvb;

bool operator < ( const bigNum &a , const bigNum &b ){
	if( a.val != b.val ) return a.val < b.val;
	return a.vec < b.vec;
}
ld get( vi &vec ){
	ld p = 1;
	for( auto x : vec ) p *= x;
	return p;
}
vb generate( vi &vec ){
	int n = SZ( vec );
	vb T;
	REP( mask , (1 << n) ){
		vi temp;
		REP( i , n )
			if( mask & (1 << i) ) temp.pb( vec[ i ] );
		T.pb( bigNum( temp , get( temp ) ) );
	}
	sort( all( T ) );
	return T;
}
vi comp( vi a , vi b ){
	vi c;
	for( auto x : b ){
		if( count( all( a ) , x ) ) continue;
		c.pb( x );
	}
	return c;
}
vi add( vi a , vi b ){
	for( auto x : b ) a.pb( x );
	return a;
}

const int base = 1000*1000*1000;
void impr( vi &a ){
	printf ("%d", a.empty() ? 0 : a.back());
	for (int i=SZ(a)-2; i>=0; --i)
		printf ("%09d", a[i]);
}

vi get( string s ){
	vi a;
	for (int i=(int)s.length(); i>0; i-=9)
		if (i < 9)
			a.push_back (atoi (s.substr (0, i).c_str()));
		else
			a.push_back (atoi (s.substr (i-9, 9).c_str()));
	while (a.size() > 1 && a.back() == 0) a.pop_back();
	return a;
}

vi mult1( vi a , int b ){
	int carry = 0;
	for (size_t i=0; i<a.size() || carry; ++i) {
		if (i == a.size())
			a.push_back (0);
		long long cur = carry + a[i] * 1ll * b;
		a[i] = int (cur % base);
		carry = int (cur / base);
	}
	while (a.size() > 1 && a.back() == 0)
		a.pop_back();
	return a;
}
vi answers[ 50 ];
int main(){
	freopen("handsome.in", "r", stdin);
	freopen("handsome.out", "w", stdout);

	sieve();
	vi vec;
	REP( i , N ) 
		if( P[ i ] == -1 ){
			vec.pb( i );
			if( SZ( vec ) >= 30 ) break;
		}
	int n , tc = 0;
	while( sc( n ) == 1 ){
		if( !n ) break;
		if( SZ( answers[ n ] ) ){
			printf( "Case #%d: " , ++tc );
			impr( answers[ n ] );
			puts( "" );
			continue;
		}
		vi A = vec;
		A.resize( n );
		vvi T( 2 );
		REP( i , n )
			T[ i >= (n >> 1) ].pb( A[ i ] );
		vvb G( 2 );
		REP( i , 2 ) G[ i ] = generate( T[ i ] );
		ld prod = get( A );
		ld pp = sqrt( prod );
		ld best = 1e100;
		vi chosen;
		REP( k , 2 )
			for( auto cur : G[ k ] ){
				ld a = cur.val;
				ld b = prod / a;
				if( abs( b - a ) < best ){
					best = abs( b - a );
					if( a < b ) chosen = cur.vec;
					else {
						chosen = comp( cur.vec , A );
					}
				}	
			}
		
		for( auto cur : G[ 0 ] ){
			ld a = cur.val;
			ld b = prod/a;
			ld target = pp / a;
			
			int pos = lower_bound( all( G[ 1 ] ) , bigNum( vi() , target ) ) - G[ 1 ].begin();
			if( pos < SZ( G[ 1 ] ) ){
				ld x = G[ 1 ][ pos ].val;
				if( abs( a * x - b / x ) < best ){
					best = abs( a * x - b / x );
					vi w = add(cur.vec,G[ 1 ][ pos ].vec);
					if( a * x < b / x ) chosen = w;
					else chosen = comp( w , A );
				}
			}
			if( pos - 1 >= 0 ){
				ld x = G[ 1 ][ pos - 1 ].val;
				if( abs( a * x - b / x ) < best ){
					best = abs( a * x - b / x );
					vi w = add(cur.vec,G[ 1 ][ pos - 1 ].vec);
					if( a * x < b / x ) chosen = w;
					else chosen = comp( w , A );
				}
			}
		}
		
		vi ans = get( "1" );
		for( auto x : chosen )
			ans = mult1( ans , x );
		printf( "Case #%d: " , ++tc );
		impr( ans );
		puts( "" );
		answers[ n ] = ans;
	}
}


