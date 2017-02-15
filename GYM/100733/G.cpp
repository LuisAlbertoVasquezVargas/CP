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

int mapa[ 256 ][ 2 ];

string f( string s , int flag ){
	//DEBUG2( s , flag );
	vi STACK;
	REP( i , SZ( s ) ){
		if( s[ i ] == '(' || s[ i ] == '[' ){
			STACK.pb( s[ i ] );
		}else if( s[ i ] == ')' || s[ i ] == ']' ){
			STACK.pop_back();
		}else{
			if( (s[ i ] == '*' || s[ i ] == '+') && !SZ(STACK) ){
				return f( s.substr( 0 , i ) , flag ) + string( 1 , mapa[ s[ i ] ][ flag ] ) + 
						f( s.substr( i + 1 ) , flag );
			}
		}
	}
	int n = SZ(s);
	if( s[ 0 ] == '(' && s.back() == ')' ){
		return "(" + f( s.substr( 1 , n - 2 ) , flag ) + ")";
	}
	if( s[ 0 ] == '[' && s.back() == ']' ){
		return "(" + f( s.substr( 1 , n - 2 ) , flag ^ 1 ) + ")";
	}
	assert( n == 1 );
	
	return string( 1 , mapa[ s[ 0 ] ][ flag ] );
}

int main(){
	ios_base :: sync_with_stdio( 0 );
	REP( i , 26 ){
		mapa[ 'a' + i ][ 0 ] = 'a' + i;
		mapa[ 'a' + i ][ 1 ] = 'A' + i;	
		
		mapa[ 'A' + i ][ 0 ] = 'A' + i;
		mapa[ 'A' + i ][ 1 ] = 'a' + i;
	}
	mapa[ '*' ][ 0 ] = '*';
	mapa[ '*' ][ 1 ] = '+';
	mapa[ '+' ][ 0 ] = '+';
	mapa[ '+' ][ 1 ] = '*';
	string s;
	while( cin >> s ){
		cout << f( s , 0 ) << '\n';
	}
}


