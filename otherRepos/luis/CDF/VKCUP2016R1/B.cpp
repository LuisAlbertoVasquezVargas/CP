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

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int main(){
	int n , K , Q;
	while( sc( n ) == 1 ){
		sc( K ) , sc( Q );
		map< int , int > mapa;
		vi x( n );
		REP( i , n ){
			sc( x[ i ] );
			mapa[ x[ i ] ] = i;
		}
		set< int > SET;
		REP( it , Q ){
			int type;
			sc( type );
			if( type == 1 ){
				int id;
				sc( id );
				id --;
				SET.insert( x[ id ] );
				while( SZ( SET ) > K )
					SET.erase( SET.begin() );
			}else{
				int id;
				sc( id );
				id --;
				bool found = 0;
				for( auto x : SET )
					if( mapa[ x ] == id ){
						found = 1;
						break;
					}
				puts( found ? "YES" : "NO" );
			}
		}
	}
}





