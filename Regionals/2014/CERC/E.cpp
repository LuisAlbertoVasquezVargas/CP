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

#define N 1000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef unsigned short tipo;


bool valid( deque< tipo > &v ){
	while( SZ(v) >= 2 ){
		if( v[ SZ(v) - 1 ] == v[ SZ(v) - 2 ] ){
			int x = v.back();
			v.pop_back();
			v.pop_back();
			v.push_back( x + 1 );
		}else break;
	}
	while( SZ(v) >= 2 ){
		if( v[ 0 ] == v[ 1 ] ){
			int x = v.front();
			v.pop_front();
			v.pop_front();
			v.push_front( x + 1 );
		}else break;
	}
	REP( i , SZ(v) - 2 )
		if( v[ i ] < v[ i + 1 ] && v[ i + 1 ] < v[ i + 2 ] ) return 0;
	return 1;
}
int n;
int A[ N + 5 ];
map< deque< tipo > , bool > memo;
bool dp( int pos , deque< tipo > vec ){
	if( pos == n )
		return SZ( vec ) == 1;
	
	deque< tipo > state = vec;
	state.pb( pos );

	if( memo.count( state ) ) return memo[ state ];
	bool &dev = memo[ state ] = 0;
	deque< tipo > nvec = vec;
	nvec.push_front( A[ pos ] );
	
	if( valid( nvec ) ) dev |= dp( pos + 1 , nvec );
	if( dev ) return 1;

	
	nvec = vec;
	nvec.push_back( A[ pos ] );
	if( valid( nvec ) ) dev |= dp( pos + 1 , nvec );
	return dev;
}
string S;
void rec( int pos , deque< tipo > vec ){
	if( pos == n )
		return;
	
	deque< tipo > nvec = vec;
	nvec.push_front( A[ pos ] );
	
	if( valid( nvec ) && dp( pos + 1 , nvec ) ){
		S.pb( 'l' );
		rec( pos + 1 , nvec );
		return;
	}
	

	nvec = vec;
	nvec.push_back( A[ pos ] );
	if( valid( nvec ) && dp( pos + 1 , nvec ) ){
		S.pb( 'r' );
		rec( pos + 1 , nvec );
		return;
	}
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		sc( n );
		REP( i , n ) sc( A[ i ] ) , A[ i ] = 31 - __builtin_clz( A[ i ] );
		memo.clear();
		bool ok = dp( 0 , deque< tipo > () );
		if( !ok ){
			puts( "no" );
			continue;
		}
		S.clear();
		rec( 0 , deque< tipo > () );
		printf( "%s\n" , S.c_str() );
	}
}





