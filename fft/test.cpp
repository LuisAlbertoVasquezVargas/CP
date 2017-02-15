#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test puts("************test************");
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

#define PI acos( -1.0 )

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

//e-maxx
//fourier0 19.0678
//fourier1 8.86447
//fourier2 7.66956
//fourier3 5.28442

//fourierMariovo 1.07436

int main(){
	int cases = 100;
	int n = 10000;
	cout << cases << endl;
	REP( tc , cases ){
		string a( n , '0' ) , b( n , '0' );
		REP( i , n ) a[ i ] += rand() % 10;
		REP( i , n ) b[ i ] += rand() % 10;
		cout << a << " " << b << endl;
	}
}
