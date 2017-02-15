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
#define DEBUG3( x , y , z ) cerr << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << endl;

#define N 5000
#define NODES (N * N)

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;

bool used[ N + 5 ][ N + 5 ];
bool memo[ N + 5 ][ N + 5 ];
bool dp( int lo , int hi , string &s ){
	if( lo >= hi ) return 1;
	if( used[ lo ][ hi ] ) return memo[ lo ][ hi ];
	used[ lo ][ hi ] = 1;
	bool &dev = memo[ lo ][ hi ] = 0;
	if( s[ lo ] == s[ hi ] ) dev |= dp( lo + 2 , hi - 2 , s );
	return dev;
}
int node;
int F[ NODES + 5 ];
int NEXT[ 2 ][ NODES + 5 ];
void clear(){
	node = 1;
	clr( F , 0 );
	clr( NEXT , 0 );
}
int AC[ NODES + 5 ];
int dfs( int u ){
	AC[ u ] = F[ u ];
	REP( i , 2 ){
		int v = NEXT[ i ][ u ];
		if( v ){
			dfs( v );
			AC[ u ] += AC[ v ];
		}
	}
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	string s;
	int K;
	while( cin >> s >> K ){
		clear();
		clr( used , 0 );
		int n = SZ(s);
		for( int i = 0 ; i < n ; ++i ){
			int p = 0;
			for( int j = i ; j < n ; ++j ){
				int cur = s[ j ] - 'a';
				if( !NEXT[ cur ][ p ] ) NEXT[ cur ][ p ] = node ++;
				p = NEXT[ cur ][ p ];
				if( dp( i , j , s ) ) F[ p ]++;
			}
		}
		dfs( 0 );
		int u = 0;
		s.clear();
		while( 1 ){
			if( K <= F[ u ] )
				break;
			int v = NEXT[ 0 ][ u ];
			int w = NEXT[ 1 ][ u ];
			if( v && K <= AC[ v ] + F[ u ] ){
				K -= F[ u ];
				u = v;
				s.pb( 'a' );
				continue;
			}
			K -= F[ u ];
			if( v ) K -= AC[ v ];
			if( w ){
				u = w;
				s.pb( 'b' );
			}else break;
		}
		cout << s << '\n';
	}
}

