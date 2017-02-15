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

#define test() cerr << "hola q hace" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 100000

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int main(){
	ios_base :: sync_with_stdio( 0 ); 
	string s;
	while( cin >> s ){
		set< string > SET;
		int n = SZ(s);
		REP( pos , n + 1 ){
			for( char c = 'a' ; c <= 'z' ; c++ ){
				string t = s.substr( 0 , pos ) + string( 1 , c ) + s.substr( pos );
				SET.insert( t );
			}
		}
		printf( "%d\n" , SZ(SET) );
	}
}


