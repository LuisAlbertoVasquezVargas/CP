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

string S[] = { "!=" , "==" , "<" , "<=" , ">" , ">=" };

int main(){
	// { !=, ==, <, <=, >, >= }
	int cases;
	cin >> cases;
	REP( tc , cases ){
		int a , b ;
		string x;
		cin >> a >> x >> b;
		bool ans = 0;
		if( x == S[ 0 ] ) ans = (a != b);
		if( x == S[ 1 ] ) ans = (a == b);
		if( x == S[ 2 ] ) ans = (a < b);
		if( x == S[ 3 ] ) ans = (a <= b);
		if( x == S[ 4 ] ) ans = (a > b);
		if( x == S[ 5 ] ) ans = (a >= b);
		puts( ans ? "true" : "false" );
	}
}


