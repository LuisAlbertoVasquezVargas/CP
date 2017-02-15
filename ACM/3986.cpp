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

#define N 1000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int n , m;
int S[ N + 1 ] , T[ N + 1 ];
int idS[ N + 1 ] , idT[ N + 1 ];
bool used[ N + 5 ][ N + 5 ];
pii memo[ N + 5 ][ N + 5 ];
pii dp( int a , int b ){
	if( a == n || b == m ) return mp( 0 , 0 );
	if( used[ a ][ b ] ) return memo[ a ][ b ];
	used[ a ][ b ] = 1;
	
	pii &dev = memo[ a ][ b ] = max( dp( a + 1 , b ) , dp( a , b + 1 ) );
	if( idS[ a ] == idT[ b ] ) {
		pii cur = dp( a + 1 , b + 1 );
		cur.fi += S[ a ];
		cur.fi += T[ b ];
		cur.se --;
		dev = max( dev , cur );
	}
	return dev;
}

int main(){
	ios_base :: sync_with_stdio( 0 );
	int cases;
	cin >> cases;
	REP( tc , cases ){
		cin >> n;
		map< string , int > mapa;
		int it = 0;
		REP( i , n ){
			string a , b;
			cin >> a >> b >> S[ i ];
			if( !mapa.count( b ) ) mapa[ b ] = it ++;
			idS[ i ] = mapa[ b ];
		}
		cin >> m;
		REP( i , m ){
			string a , b;
			cin >> a >> b >> T[ i ];
			if( !mapa.count( b ) ) mapa[ b ] = it ++;
			idT[ i ] = mapa[ b ];
		}
		clr( used , 0 );
		auto p = dp( 0 , 0 );
		cout << p.fi << " " << (-p.se) << '\n';
	}
}


