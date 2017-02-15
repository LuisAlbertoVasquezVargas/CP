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
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef vector< int > vi;

ull POT[ 80 ];
ull get( string &s ){
	ull ans = 0;
	REP( i , SZ(s) ){
		if( s[ i ] == '.' ) continue;
		ans = ans * 10 + (s[ i ] - '0');
	}
	return ans;
}
int main(){
	POT[ 0 ] = 1;
	for( int i = 1 ; i < 80 ; ++i ) POT[ i ] = POT[ i - 1 ] * 10ULL;
	string s;
	while( cin >> s ){
		int pot = 2;
		int n = SZ( s );
		int pos = (int)s.find( '.' );
		if( pos != -1 ){
			pot += n - pos - 1;
		}
		ull num = get( s );
		ull den = POT[ pot ];
		ull g = __gcd( num , den );
		cout << den / g << '\n';
	}
}


