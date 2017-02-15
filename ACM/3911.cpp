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

#define N 1000

typedef long double ld;
typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

vector< string > a = { "kg" , "lb" , "l" , "g" };
vector< string > b = { "lb" , "kg" , "g" , "l" };
vector< ld > C = { 2.2046 , 0.4536 , 0.2642 , 3.7854 };
int main(){
	map< string , string > mapa;
	map< string , int > ID;
	REP( i , SZ( a ) ) {
		mapa[ a[ i ] ] = b[ i ];
		ID[ a[ i ] ] = i;
	}
	
	int cases;
	cin >> cases;
	REP( tc , cases ){
		ld x;
		string s;
		cin >> x >> s;
		
		string t = mapa[ s ];
		int pos = ID[ s ];
		
		printf( "%d %.4f %s\n" , tc + 1 , (double)(C[ pos ] * x) , t.c_str() );
	}
}




