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
#define DEBUG3( x , y , z ) cerr << #x << "=" << x << " " << #y << "=" << y << " " << #z << " " << z << endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;


int main(){
	//freopen( "magic.in" , "r" , stdin );
	//freopen( "magic.out" , "w" , stdout );
	int n;
	while( sc( n ) == 1 ){
		set< pii > SET;
		REP( i , n ){
			int x;
			sc( x );
			SET.insert( mp( x , i ) );
		}
		vi x , y , z;
		while( SZ( SET ) > 1 ){
			auto it1 = SET.begin() , it2 = --SET.end();
			pii a = *it1;
			pii b = *it2;
			SET.erase( it1 );
			SET.erase( it2 );
			int f = min( a.fi , b.fi );
			int u = a.se , v = b.se;
			if( u > v ) swap( u , v );
			x.pb( u ) , y.pb( v ) , z.pb( f );
			a.fi -= f;
			b.fi -= f;
			if( a.fi ) SET.insert( a );
			if( b.fi ) SET.insert( b );
		}
		printf( "%d\n" , SZ( x ) );
		REP( i , SZ( x ) ) printf( "%d %d %d\n" , x[ i ] + 1 , y[ i ] + 1 , z[ i ] );
	}
}



