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

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int LIS( vi &a ){
	vi b;
	for( auto x : a ){
		int j = upper_bound( all( b ) , x ) - b.begin();
		if( j == SZ(b) ) b.pb( x );
		else b[ j ] = x;
	}
	return SZ(b);
}
int get( vi &v , int last , int op ){
	vi w;
	for( auto x : v )
		if( op == 0 ){
			if( x <= last ) w.pb( x );
		}else{
			if( x >= last ) w.pb( x );
		}
	return LIS( w );
}
int main(){
	int n , L;
	while( sc( n ) == 1 ){
		sc( L );
		vi x( n );
		REP( i , n ) sc( x[ i ] );
		
		if( L * n <= 200000 ){
			vi w;
			REP( k , L ) REP( i , n ) w.pb( x[ i ] );
			printf( "%d\n" , LIS( w ) );
			continue;
		}
		vi y = x;
		sort( all( y ) );
		y.resize( unique( all( y ) ) - y.begin() );
		REP( i , n ) x[ i ] = lower_bound( all( y ) , x[ i ] ) - y.begin();
		for( auto a : x ) cout << a << " " ; cout << endl;
		
		
	}
}


