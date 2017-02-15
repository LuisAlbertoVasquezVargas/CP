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
typedef vector< pii > vpii;

struct data{
	int u , v , w;
	data(){}
	data( int u , int v , int w ) : u( u ) , v( v ) , w( w ){}
};
bool operator < ( const data &a , const data &b ){
	return a.w > b.w;
}

int main(){
	int n;
	while( sc( n ) == 1 ){
		vector< data > V;
		REP( i , 2 * n ){
			REP( j , i ){
				int w;
				sc( w );
				V.pb( data( i , j , w ) );
			}
		}
		vi vis( 2 * n );
		sort( all( V ) );
		vi teammate( 2 * n , -1 );
		for( auto e : V ){
			int u = e.u , v = e.v , w = e.w;
			if( vis[ u ] || vis[ v ] ) continue;
			vis[ u ] = vis[ v ] = 1;
			teammate[ u ] = v;
			teammate[ v ] = u;
		}
		REP( i , 2 * n ) printf( "%d%c" , teammate[ i ] + 1 , (i +1 == SZ(teammate)) ? 10 : 32 );
	}
}


