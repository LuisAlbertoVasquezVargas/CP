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

int main(){
	ios_base :: sync_with_stdio( 0 );
	int n , m;
	while( cin >> n >> m ){
		string s;
		cin >> s;
		vi mapa( 256 );
		REP( i , 256 ) mapa[ i ] = i;
		REP( i , m ){
			char a , b;
			cin >> a >> b;
			a -= 'a' , b -= 'a';
			int posa = -1 , posb = -1;
			REP( k , 26 )
				if( mapa[ k ] == a ) posa = k;
			REP( k , 26 )
				if( mapa[ k ] == b ) posb = k;
			swap( mapa[ posa ] , mapa[ posb ] );
		}
		REP( i , SZ( s ) ) s[ i ] = 'a' + mapa[ s[ i ] - 'a' ];
		cout << s << '\n';
	}
}



