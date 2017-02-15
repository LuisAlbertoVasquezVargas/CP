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
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< string > vs;

vs lista;
int n;
string cad;
void dfs( int pos , string &s ){
	if( pos == n ){
		lista.pb( cad );
		return;
	}
	for( auto c : s ){
		cad.pb( c );
		dfs( pos + 1 , s );
		cad.pop_back();
	}
}
vs doit( string s , int lvl ){
	n = lvl;
	cad.clear();
	lista.clear();
	dfs( 0 , s );
	return lista;
}
void impr( vs &v ){
	for( auto s : v ) cout << s << " "; cout << endl;
}
void generate( string abc , int a , int b , vs &x , vs &y ){
	x = doit( abc , a );
	y = doit( "0123456789" , b );
	//impr( x );
	//impr( y );
	//DEBUG2( SZ(x) , SZ(y) );
}
vi R = { 3 , 5 }; 
vector< vs > A( 2 ) , B( 2 );//3-4   5-2
bool isCorrect( string &s , vs &a , vs &b ){
	
	REP(i , SZ(R) ){
		string x = s.substr( 0 , R[ i ] ) , y = s.substr( R[ i ] );
		if( binary_search( all( a ) , x ) && binary_search( all( b ) , y ) ) return 1;
	}
	return 0;
}
bool isCorrect( string &s ){
	REP(i , SZ(R))
		if( isCorrect( s , A[ i ] , B[ i ] ) ) return 1;
	return 0;
}
ll getPos( string &s ){
	ll cur = 0;
	REP(i , SZ(R)){
		string x = s.substr( 0 , R[ i ] ) , y = s.substr( R[ i ] );
		if( binary_search( all( A[ i ] ) , x ) && binary_search( all( B[ i ] ) , y ) ){
			ll posx = lower_bound( all( A[ i ] ) , x ) - A[ i ].begin();
			ll posy = lower_bound( all( B[ i ] ) , y ) - B[ i ].begin();
			cur += (ll) posx * SZ( B[ i ] ) + posy;
			return cur;
		}else{
			cur += (ll)SZ( A[ i ] ) * SZ( B[ i ] );
		}
	}
	assert( 0 );
}

int main(){
	ios_base :: sync_with_stdio( 0 );
	string s , t;
	for( char c = 'A' ; c <= 'Z' ; ++c ) s.pb( c );
	for( char c = 'A' ; c <= 'Z' ; ++c ) {
		if( c == 'A' || c == 'C' || c == 'M' || c == 'I' || c == 'P' ) continue;
		t.pb( c );
	}
	vs ss = { s , t };
	REP( i , SZ( R ) ) generate( ss[ i ] , R[ i ] , 7 - R[ i ] , A[ i ] , B[ i ] );
	
	ll C;
	while( cin >> s >> t >> C ){
		if( s == "*" && t == "*" && C == 0 ) break;
		if( !isCorrect( t ) ) cout << "N\n";
		else {
			ll ps = getPos( s ) , pt = getPos( t );
			if( pt <= ps ){
				cout << "N\n";
				continue;
			}
			if( pt - ps > C ){
				cout << "N\n";
				continue;
			}
			cout << "Y\n";
		}
	}
}


