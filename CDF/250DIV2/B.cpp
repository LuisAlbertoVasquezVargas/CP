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

int main(){
	int S , L;
	while( sc( S ) == 1 ){
		sc( L );
		priority_queue< pii > Q;
		for( int i = 1 ; i <= L ; ++i )
			Q.push( mp( __builtin_ctz( i ) , i ) );
		
		vi v;
		while( !Q.empty() ){
			if( !S ) break;
			pii p = Q.top() ; Q.pop();
			int bit = p.fi , num = p.se;
			if( S >= (1 << bit) ){
				S -= (1 << bit);
				v.pb( num );
			}
		}
		if( S ){
			puts( "-1" );
			continue;
		}
		printf( "%d\n" , SZ(v) );
		REP( i , SZ(v) ) printf( "%d%c" , v[ i ] , (i + 1 == SZ(v)) ? 10 : 32 );
	}
}



