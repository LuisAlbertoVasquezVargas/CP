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

int get( string &s ){
	REP( i , SZ(s) ) s[ i ] -= '0';
	int x = s[ 0 ] * 10 + s[ 1 ];
	int y = s[ 3 ] * 10 + s[ 4 ];
	int z = s[ 6 ] * 10 + s[ 7 ];
	return x * 60 * 60 + 60 * y + z;
}
int main(){
	int n;
	while( cin >> n ){
		bool ok = 1;
		REP( i , n ){
			string s , t;
			cin >> s >> t;
			int a = get( s ) , b = get( t );
			if( (b - a) >= 3 * 60 * 60 ) ok = 0;
		}
		puts( ok ? "Yes" : "No" );
	}
}

