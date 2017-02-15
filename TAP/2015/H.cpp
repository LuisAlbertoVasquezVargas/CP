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
typedef long double ld;
typedef vector< ld > vld;
typedef pair< int , int > pii;
typedef vector< int > vi;

string tos( ll x ){
	ostringstream out;
	out << x;
	return out.str();
}
ll toi( string s ){
	istringstream in( s );
	ll x;
	in >> x;
	return x;
}
ll f( int m ){
	if( m == 0 ) return 0;
	string cad = tos( m );
	sort( all( cad ) );
	return 1 + f( m - toi( cad ) );
}
int main(){
	int n;
	while( sc( n ) == 1 ){
		printf( "%d\n" , f( n ) );
	}
}
