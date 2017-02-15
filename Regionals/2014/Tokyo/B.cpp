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

ll f( string s ){//left right
	ll cur = s[ 0 ] - '0';
	for( int i = 1 ; i < SZ(s) ; i += 2 ){
		ll dig = s[ i + 1 ] - '0';
		if( s[ i ] == '+' ){
			cur += dig;
		}else cur *= dig;
	}
	return cur;
}

ll g( string s ){
	vll STACK( 1 , s[ 0 ] - '0' );
	for( int i = 1 ; i < SZ(s) ; i += 2 ){
		ll dig = s[ i + 1 ] - '0';
		if( s[ i ] == '+' ){
			STACK.pb( dig );
		}else {
			ll b = STACK.back();
			STACK.pop_back();
			STACK.pb( b * dig );
		}
	}
	return accumulate( all( STACK ) , 0LL );
}
/*
M — When only the multiplication-first rule results Bob’s answer.
L — When only the left-to-right rule results Bob’s answer.
U — When both of the rules result Bob’s answer.
I — When neither of the rules results Bob’s answer.
*/
int main(){
	string s;
	ll target;
	while( cin >> s >> target ){
		ll a = f( s ) , b = g( s );
		if( a == b && a == target ){
			cout << "U" << '\n';
			continue;
		}
		if( target != a && target != b ){
			cout << "I" << '\n';
			continue;
		}
		if( a == target ){
			cout << "L" << '\n';
			continue;
		}
		cout << "M" << '\n';
	}
}


