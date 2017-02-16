#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define SZ( v ) ((int)(v).size())
#define all( v ) v.begin() , v.end()

#define mp make_pair
#define fi first
#define se second

#define N 1000

typedef vector< int > vi;
typedef long double ld;

int main(){
	ios_base :: sync_with_stdio( 0 );
	string s;
	int cases;
	cin >> cases;
	getline( cin , s );
	getline( cin , s );
	REP( tc , cases ){
		if( tc ) puts( "" );
		getline( cin , s );
		ld ans = 0;
		while( getline( cin , s ) ){
			if( s == "" ) break;
			//cout << s << endl;
			istringstream in( s );
			double x1 , y1 , x2 , y2;
			in >> x1 >> y1 >> x2 >> y2;
			ans += hypot( x1 - x2 , y1 - y2 );
		}
		ans /= 10000;
		int mm = (int)round( ans * 60 );
		printf( "%d:%02d\n" , mm / 60 , mm % 60 );
	}
}


