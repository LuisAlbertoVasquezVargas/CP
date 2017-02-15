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

#define N 87

typedef long long ll;
typedef unsigned long long ull;
typedef vector< ll > vll;
typedef vector< int > vi;

ull F[ N + 5 ];

int main(){
	ios_base :: sync_with_stdio( 0 );
	F[ 1 ] = 1;
	F[ 2 ] = 2;
	
	for( int i = 3 ; i <= N ; ++i ){
		F[ i ] = F[ i - 1 ] + F[ i - 2 ];
	}	
	
	vll v;
	for( int i = 1 ; i <= N ; ++i ) v.pb( F[ i ] );
	
	int cases;
	cin >> cases;
	REP( tc , cases ){
		ll n;
		cin >> n;
		int pos = upper_bound( all( v ) , n ) - v.begin();
		cout << pos << '\n';
	}
}


