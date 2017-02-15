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
#define DEBUG3( x , y , z ) cerr << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << endl;

#define N 1000

typedef long double ld;
typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< string > vs;

vs T( 256 );
string f( int x ){
	string s;
	REP( i , 5 ){
		s.pb( '0' + (x & 1) );
		x >>= 1;
	}
	reverse( all( s ) );
	return s;
}
int dx[] = { 0 , -1 , 0 , 1 };
int dy[] = { 1 , 0 , -1 , 0 };
int R , C;
bool valid( int a , int b ){ return a >= 0 && b >= 0 && a < R && b < C; }

void dfs( int x , int y , int dir , int cur , vs &mat , string s , vvi &vis ){
	//DEBUG3( x , y , cur );
	vis[ x ][ y ] = 1;
	mat[ x ][ y ] = s[ cur ];
	REP( k , 4 ){
		int ndir = (k + dir)%4;
		int nx = x + dx[ ndir ] , ny = y + dy[ ndir ];
		if( valid( nx , ny ) && !vis[ nx ][ ny ] ){
			dfs( nx , ny , ndir , cur + 1 , mat , s , vis );
			return;
		}
	}
}

int main(){
	T[ ' ' ] = f( 0 );
	for( int i = 1 ; i <= 26 ; ++i )
		T[ 'A' + i - 1 ] = f( i );
	
	int cases;
	cin >> cases;
	string dummy;
	getline( cin , dummy );
	REP( tc , cases ){
		string s;
		getline( cin , s );
		istringstream in( s );		
		in >> R >> C;
		int pos = s.find( " " );
		pos = s.find( " " , pos + 1 );
		string cad = s.substr( pos + 1 );
		
		s.clear();
		for( auto c : cad ) s += T[ c ];
		s.resize( R * C , '0' );
		
		vs mat( R , string( C , '0' ) );
		vvi vis( R , vi( C ) );
		//DEBUG( s );
		dfs( 0 , 0 , 0 , 0 , mat , s , vis );
		s.clear();
		
		//REP( i , R ) DEBUG( mat[ i ] );
		REP( i , R ) s += mat[ i ];
		cout << tc + 1 << " " << s << '\n';
	}
}




