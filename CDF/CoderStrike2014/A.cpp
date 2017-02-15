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

string cad = "AHIMOTUVWXY";
int main(){
	ios_base :: sync_with_stdio(0);
	vi vis( 256 );
	REP( i , SZ( cad ) ) vis[ cad[ i ] ] = 1;
	string s;
	while( cin >> s ){
		bool possible = 1;
		for( auto c : s ){
			if( !vis[ c ] ){
				possible = 0;
				break;
			}
		}
		string t = s;
		reverse( all( t ) );
		if( t != s ) possible = 0;
		cout << (possible ? "YES": "NO" ) << '\n';
	}
}


