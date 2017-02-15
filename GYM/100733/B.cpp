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

#define M 40

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< string > vs;
typedef vector< vs > vvs;

int main(){
	ios_base :: sync_with_stdio( 0 );
	vi mapa( 1000 , -1 );
	int it = 0 ;
	for( char c = 'a' ; c <= 'z' ; ++c ) mapa[ c ] = it ++;
	for( char c = '0' ; c <= '9' ; ++c ) mapa[ c ] = it ++;
	
	int n;
	while( cin >> n ){
		vvs T( n );
		vvi P( n );
		REP( i , n ){
			vi F( M );
			REP( k , 2 ){
				string s;
				cin >> s;
				T[ i ].pb( s );
				for( auto c : s ) F[ mapa[ c ] ] ++;
			}
			P[ i ] = F;
		}
		int ind = -1 , best = -1;
		REP( k , n ){
			int R , C;
			cin >> R >> C;
			vi F( M );
			REP( i , R ){
				string s;
				cin >> s;
				for( auto c : s ) F[ mapa[ c ] ] ++;
			}
			int cnt = INT_MAX;
			REP( i , M )
				if( P[ k ][ i ] != 0 ) cnt = min( cnt , F[ i ] / P[ k ][ i ] );
			if( best < cnt ){
				best = cnt;
				ind = k;
			}
		}
		cout << T[ ind ][ 0 ] << " " << T[ ind ][ 1 ] << '\n';
	}
}


