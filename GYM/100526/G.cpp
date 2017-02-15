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

double f( double a , double b , double c , double x ){
	return - a * x * x + b * x + c;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		double best = -1e100;
		int ind = -1;
		REP( i , n ){
			int a , b , c;
			sc( a ) , sc( b ) , sc( c );
			double cur = (double)b / (2.0 * a);
			double eval = f( a , b , c , cur );
			if( eval > best ) best = eval , ind = i;
		}
		
		printf( "%d\n" , ind + 1 );
	}
}



