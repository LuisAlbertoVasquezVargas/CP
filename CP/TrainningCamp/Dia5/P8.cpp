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

#define N 100000
#define NEUTRAL 0
#define v1 ( ( node << 1 ) + 1 )
#define v2 ( v1 + 1 )
#define med ( (a + b) >> 1 )
#define LEFT v1 , a , med
#define RIGHT v2 , med + 1 , b


typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int T[ 4 * N ];

void update( int node , int a , int b , int x , int val ){
	if( x > b || a > x ) return;
	if( a == b ){
		T[ node ] = val;
		return;
	}
	update( LEFT , x , val );
	update( RIGHT , x , val );
	T[ node ] = __gcd( T[ v1 ] , T[ v2 ] );
}
int query( int node , int a ,  int b , int lo , int hi ){
	if( lo > b || a > hi ) return 0;
	if( a >= lo && hi >= b ) return T[ node ];
	return __gcd( query( LEFT , lo , hi ) , query( RIGHT , lo , hi ) );
}
int get( int x ){
	return x == 0 ? 1 : x;
}
int getId( vi &a , int x ){
	return lower_bound( all( a ) , x ) - a.begin();
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	int Q;
	cin >> Q;
	vi OP , vec;
	vi mapa;
	int id = 0;
	REP( i , Q ){
		char c;
		int x;
		cin >> c >> x;
		OP.pb( (c == '-') ? -1 : +1 );
		vec.pb( x );
		//cout << c << " " << x << endl;
		mapa.pb( x );
	}
	sort( all( mapa ) );
	mapa.resize( unique( all( mapa ) ) - mapa.begin() );
	vi freq = vi( SZ( mapa ) );
	int n = SZ( mapa );
	REP( i , Q ){
		int c = OP[ i ];
		int x = vec[ i ];
		int pos = getId( mapa , x );
		if( c == +1 ){
			if( freq[ pos ] >= 1 ){
				freq[ pos ] ++;
				cout << get( T[ 0 ] ) << '\n';
			}else{
				update( 0 , 0 , n - 1 , pos , x );
				freq[ pos ]++;
				cout << get( T[ 0 ] ) << '\n';
			}
		}else{ // c == -1
			if( freq[ pos ] >= 2 ){
				freq[ pos ] --;
				cout << get( T[ 0 ] ) << '\n';
			}else{
				freq[ pos ] --;
				update( 0 , 0 , n - 1 , pos , 0 );
				cout << get( T[ 0 ] ) << '\n';
			}
			
		}
	}	
}

 
