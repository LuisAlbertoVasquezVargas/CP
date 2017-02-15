#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define SZ( v ) ((int)(v).size())
#define all( v ) v.begin() , v.end()

#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef vector< int > vi;

int main(){
	ios_base :: sync_with_stdio( 0 );
	int n , m;
	while( cin >> n >> m ){
		vector< string > S( n );
		REP( i , n ) cin >> S[ i ];
		int cnt = 0;
		REP( i , n - 1 ) REP( j , m - 1 ){
			string cad;
			REP( a , 2 ) REP( b , 2 ) cad.pb( S[ i + a ][ j + b ] );
			sort( all( cad ) );
			if( cad == "acef" ) cnt ++;
		}
		cout << cnt << '\n';
	}
}


