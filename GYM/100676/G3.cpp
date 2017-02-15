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
bool T[ N + 5 ][ 1 << N ];
bool used[ 1 << N ];
int memo[ 1 << N ];
vi G[ N + 5 ];

int dp( int mask ){
	if( !mask ) return 0;
	if( used[ mask ] ) return memo[ mask ];
	used[ mask ] = 1;
	int &dev = memo[ mask ] = -INF;
	REP( u , n )
		if( (mask & (1 << u)) && T[ u ][ mask ^ (1 << u) ] ) 
			dev = max( dev , (n - ones( mask ) + 1) * A[ u ] + dp( mask ^ (1 << u) ) );
	return dev;
}

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
		clr( T , 0 );
		REP( u , n ) REP( mask , (1<<n) ){
			if( mask == 0 ){
				T[ u ][ mask ] = 1;
			}else{
				int v = 31 - __builtin_clz( mask );
				if( T[ u ][ mask ^ (1 << v) ] && !DP[ u ][ v ] )
					T[ u ][ mask ] = 1;
				else T[ u ][ mask ] = 0;
			}
		}
		clr( used , 0 );
		cout << dp( (1<<n) - 1 ) << '\n';
	}
}


