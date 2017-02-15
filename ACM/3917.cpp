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

typedef unsigned long long ull;
typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

/*
F(n) = F(n-1) + 5*F(n-2) + F(n-3) - F(n-4)
f(n)=0 n<0
f(0)=1 Trivial
f(1)=1
f(2)=5
f(3)=11

*/
ull F[ N + 1 ];
int main(){
	F[ 0 ] = 1;
	F[ 1 ] = 1;
	F[ 2 ] = 5;
	F[ 3 ] = 11;
	for( int i = 4 ; i <= N ; ++i )
		F[ i ] = F[ i - 1 ] + 5LL * F[ i - 2 ] + F[ i - 3 ] - F[ i - 4 ];
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		cout << tc + 1 << " " << F[ n ] << '\n';
	}
}



