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

#define N 18
#define INF (1<<20)

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

inline int ones( int x ){ return __builtin_popcount( x );}
int n;
int A[ N + 5 ];
int DP[ N + 5 ][ N + 5 ];
bool used[ N + 1 ][ 1 << N ];
int memo[ N + 1 ][ 1 << N ];
vi G[ N + 5 ];
/*
int dp( int u , int mask ){
	if( mask == (1 << n) - 1 ) return A[ u ] * n;
	if( used[ u ][ mask ] ) return memo[ u ][ mask ];
	used[ u ][ mask ] = 1;
	int &dev = memo[ u ][ mask ] = -INF;
	for( auto v : G[ u ] )
		if( !(mask & (1 <<v)) ) 
			dev = max( dev , ones( mask ) * A[ u ] + dp( v , mask | (1 << v) ) );
	return dev;
}
*/
int get( string s ){
	istringstream in( s );
	int x;
	in >> x;
	return x;
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	int cases;
	cin >> cases;
	string dumm;
	string pattern = " --> ";
	REP( tc , cases ){
		int m;
		cin >> n >> m;
		getline( cin , dumm );
		map< string , int > mapa;
		REP( i , n ){
			string s;
			getline( cin , s );
			int last = -1;
			for( int j = SZ(s) - 1 ; j >= 0 ; --j )
				if( s[ j ] == ' ' || isdigit( s[ j ] ) ) last = j;
				else break;
			assert( last != -1 );
			string a = s.substr( 0 , last );
			int val = get( s.substr( last ) );
			mapa[ a ] = i;
			A[ i ] = val;
		}
		clr( DP , 0 );
		REP( i , n ) DP[ i ][ i ] = 1;
		REP( i , m ){
			string s;
			getline( cin , s );
			int pos = s.find( pattern );
			string a = s.substr( 0 , pos );
			string b = s.substr( pos + SZ(pattern) );
			int u = mapa[ a ] , v = mapa[ b ];
			DP[ v ][ u ] = 1;
		}
		REP( k , n ) REP( i , n ) REP( j , n ) DP[ i ][ j ] |= (DP[ i ][ k ] & DP[ k ][ j ]);
		REP( i , n ) G[ i ].clear();
		REP( i , n ) REP( j , n )
			if( !DP[ i ][ j ] ) G[ i ].pb( j );
		clr( used , 0 );
		int ans = 0;
		REP( u , n ) ans = max( ans , dp( u , (1 << u) ) );
		cout << ans << '\n';
	}
}


