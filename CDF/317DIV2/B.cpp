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
typedef vector< pii > vpii;
typedef vector< int > vi;

int main(){
	ios_base :: sync_with_stdio( 0 );
	int n , L;
	while( cin >> n >> L ){
		
		map< int , int > bb , ss;
		REP( i , n ){
			char d;
			int p , q;
			cin >> d >> p >> q;
			if( d == 'S' ){
				ss[ p ] += q;
			}else{
				bb[ p ] += q;
			}
		}
		vpii B( all( bb ) ) , S( all( ss ) );
		if( SZ( S ) >= L ) S.resize( L );
		reverse( all( S ) );
		
		reverse( all( B ) );
		if( SZ( B ) >= L ) B.resize( L );
		REP( i , SZ( S ) ) printf( "S %d %d\n" , S[ i ].fi , S[ i ].se );
		REP( i , SZ( B ) ) printf( "B %d %d\n" , B[ i ].fi , B[ i ].se );
	}
}



