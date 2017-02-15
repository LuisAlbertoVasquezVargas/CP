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

#define N 100000
#define ALP 26

struct trie{
	int next[ N + 5 ][ ALP ] , node, F[ 2 ][ N + 5 ];
	trie(){}
	void init(){
		node = 1;
		clr( next , 0 );
		clr( F , 0 );
	}
	void add( string &s , int id ){
		int p = 0 , n = SZ(s);
		REP( i , n ){
			int c = s[ i ] - 'A';
			if( !next[ p ][ c ] ) next[ p ][ c ] = node++;
			p = next[ p ][ c ];
			F[ id ][ p ] ++;
		}
	}
}T;
int main(){
	ios_base :: sync_with_stdio( 0 );
	int n;
	while( cin >> n ){
		if( n == -1 ) break;
		T.init();
		REP( k , 2 ){
			REP( i , n ){
				string s;
				cin >> s;
				T.add( s , k );
			}
		}
		ll ans = 0;
		REP( i , T.node )
			ans += min( T.F[ 0 ][ i ] , T.F[ 1 ][ i ] );
		cout << ans << '\n';
	}
}



