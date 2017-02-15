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

vi mapa(1000 , -1);
ll tos( string s ){
	istringstream in( s );
	ll ans;
	in >> ans;
	return ans;
}

ll mulmod(ll a, ll b, ll c){
	ll x = 0, y = a % c;
	while(b > 0){
		if(b & 1){
			x += y;
			if(x >= c) x -= c;
		}
		y = y + y;
		if(y >= c) y -= c;
		b >>= 1;
	}
	return x % c;
}
ll modulo(ll a, ll b, ll c){
	ll x = 1, y = a;
	while(b){
		if(b & 1) x = mulmod(x, y, c);
		y = mulmod(y, y, c);
		b >>= 1;
	}
	return x % c;
}
bool f(ll p, int it = 20){
	if(p < 2) return 0;
	if(p != 2 && (p & 1) == 0) return 0;
	ll s = p - 1;
	while( (s & 1) == 0) s >>= 1;
	while( it-- ){
		ll a = rand() % (p - 1) + 1, temp = s;
		ll mod = modulo(a, temp, p);
		while(temp != p - 1 && mod != 1 && mod != p - 1){
			mod = mulmod(mod, mod, p);
			temp <<= 1;
		}
		if(mod != p - 1 && temp % 2 == 0) return 0;
	}
	return 1;
}

int main(){
	for( auto x : { 0 , 1 , 2 , 5 , 8 } )
		mapa[ '0' + x ] = '0' + x;
	mapa[ '0' + 6 ] = '0' + 9;
	mapa[ '0' + 9 ] = '0' + 6;
	string s;
	while( cin >> s ){
		if( !f( tos( s ) ) ){
			puts( "no" );
			continue;
		}
		bool ok = 1;
		for( auto &x : s )
			if( mapa[ x ] == -1 ) ok = 0;
			else x = mapa[ x ];
		if( !ok ) {
			puts( "no" );
			continue;
		}	
		reverse( all( s ) );
		if( !f( tos( s ) ) ){
			puts( "no" );
			continue;
		}
		puts( "yes" );
	}
}


