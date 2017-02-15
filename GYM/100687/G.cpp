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
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef long double ld;

int main(){
	int n;
	while( cin >> n ){
		vll vec;		
		ll S = 0;
		REP( i , n ){
			ll a , b;
			cin >> a >> b;
			vec.pb( a + b );
			S += vec.back();
		}
		ld ans = 0;
		REP( i , n ){
			ld dif = abs( (ld)vec[ i ] - (ld)S/(ld)n );
			ans += dif;
		}
		printf( "%.15f\n" , (double)ans );
	}
}



