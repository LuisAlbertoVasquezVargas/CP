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

#define N 300000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

string s;
int n , gap;
int pos[ N + 5 ] , tmp[ N + 5 ] , sa[ N + 5 ] , lcp[ N + 5 ];

bool sufCmp( int i , int j ){
	if( pos[ i ] != pos[ j ] ) return pos[ i ] < pos[ j ];
	i += gap , j += gap;
	return (i < n && j < n) ? pos[ i ] < pos[ j ] : i > j ;
}
void build(){
	n = s.size();
	REP( i , n ) sa[ i ] = i , pos[ i ] = s[ i ];
	for( gap = 1 ; ; gap <<= 1 ){
		sort( sa , sa + n , sufCmp );
		REP( i , n - 1 ) tmp[ i + 1 ] = tmp[ i ] + sufCmp( sa[ i ] , sa[ i + 1 ] );
		REP( i , n ) pos[ sa[ i ] ] = tmp[ i ];
		if( tmp[ n - 1 ] == n - 1 ) break;
	}
	for( int i = 0 , k = 0 ; i < n ; ++i )
		if( pos[ i ] != n - 1 ){
			for( int j = sa[ pos[ i ] + 1 ] ; s[ i + k ] == s[ j + k ] ; ) ++k;
			lcp[ pos[ i ] ] = k;
			if( k ) --k;
		}
}

int main(){
	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout);
	while( sc( n ) == 1 ){
		vi A( n );
		REP( i , n ) sc( A[ i ] ) , A[ i ] --;
		s = string( n , '*' );
		REP( i , n ){
			if( n - 1 - i == A[ i ] ){
				s[ A[ i ] ] = '0';
				continue;
			}
			int ind = -1;
			for( int j = i ; j < n ; ++j )
				if( n - 1 - i == A[ j ] ){
					ind = j;
					break;
				}
			assert( ind != -1 );
			for( int j = i ; j < n ; ++j )
				if( j < ind ) s[ A[ j ] ] = '0';
				else s[ A[ j ] ] = '1';
			break;
		}
		assert( count( all( s ) , '*' ) == 0 );
		build();
		vi a( sa , sa + n );
		if( a != A ){
			puts( "Error" );
			continue;
		}
		printf( "%s\n" , s.c_str() );
	}
}



