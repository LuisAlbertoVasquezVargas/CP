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

#define N 10

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef long double ld;
typedef vector< ld > vld;

int n , m;
vector< string > T;
string cad;
bool valid( int x , int y ){ return x >= 0 && y >= 0 && x < n && y < m ;}
int dx[] = { 0 , 1 };
int dy[] = { 1 , 0 };
string S = "VH";
void back( int x , int y ){
	if( x == n - 1 && y == m - 1 ){
		T.pb( cad );
		return;
	}
	REP( k , 2 ){
		int nx = x + dx[ k ];
		int ny = y + dy[ k ];
		if( valid( nx , ny ) ){
			cad.pb( S[ k ] );
			back( nx , ny );
			cad.pop_back();
		}
	}
}
string solve( int x , int y , int k ){
	n = x + 1 , m = y + 1;
	T.clear();
	back( 0 , 0 );
	sort( all( T ) );
	return T[ k ];
}
int main(){
	int cases;
	cin >> cases;
	REP( tc , cases ){
		int x , y , k;
		cin >> x >> y >> k;
		cout << solve( x , y , k ) << '\n';
	}
}


