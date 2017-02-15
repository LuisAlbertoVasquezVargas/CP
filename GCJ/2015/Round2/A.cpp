#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define DEBUG( x ) cout << #x << " " << (x) << endl;
#define INF (1LL<<30)

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< string > vs;
typedef long long ll;

bool valid( int a , int b ){ return a >= 0 && a < b;}
int dx[] = { 0 , 0 , 1 , -1 };
int dy[] = { 1 , -1 , 0 , 0 };

ll cost( int x , int y , vs &S , int n , int m ){
	if( S[ x ][ y ] == '.' ) return 0;
	int ddx = 0 , ddy = 0;
	if( S[ x ][ y ] == '^' ) {
		ddx = -1;
	}else if( S[ x ][ y ] == 'v' ) {
		ddx = +1;
	}else if( S[ x ][ y ] == '>' ) {
		ddy = +1;
	}else if( S[ x ][ y ] == '<' ) {
		ddy = -1;
	}
	ll mini = INF;
	REP( k , 4 ){
		for( int it = 1 ; it < 300 ; ++it ){
			int nx = x + dx[ k ] * it;
			int ny = y + dy[ k ] * it;
			if( !valid( nx , n ) ) break;
			if( !valid( ny , m ) ) break;
			if( S[ nx ][ ny ] == '.' ) continue;
			ll cur = 1;
			if( ddx == dx[ k ] && ddy == dy[ k ] ) cur = 0;
			mini = min( mini , cur );
			break;
		}
	}
	return mini;
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	int cases;
	cin >> cases;
	REP( tc , cases ){
		int n , m;
		cin >> n >> m;
		vs S( n );
		REP( i , n ) cin >> S[ i ];
		ll ans = 0;
		REP( i , n ) REP( j , m )
			ans += cost( i , j , S , n , m );
		if( ans >= INF ){
			cout << "Case #" << tc + 1 << ": "<<"IMPOSSIBLE\n";
			continue;
		}
		cout << "Case #" << tc + 1 << ": " << ans << "\n";
	}
}



