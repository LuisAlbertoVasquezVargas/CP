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

#define N 100
#define M 10

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

bool used[ N + 5 ][ M + 5 ];
bool memo[ N + 5 ][ M + 5 ];

int n , MOD;
bool dp( int pos , int mod ){
	if( pos == n ) return mod == 0;
	if( used[ pos ][ mod ] ) return memo[ pos ][ mod ];
	
	used[ pos ][ mod ] = 1;
	
	bool &ans = memo[ pos ][ mod ] = 0;
	for( int i = ( (pos == 0) ? 1 : 0 ) ; i <= 9 ; ++i ){
		ans |= dp( pos + 1 , (mod * 10 + i)%MOD );
	}
	return ans;
}
string v;
void rec( int pos , int mod ){
	if( pos == n ) return;
	
	for( int i = ( (pos == 0) ? 1 : 0 ) ; i <= 9 ; ++i ){
		if( dp( pos + 1 , (mod * 10 + i)%MOD ) ){
			v.pb( '0' + i );
			rec( pos + 1 , (mod * 10 + i)%MOD );
			return;
		}
	}
}
int main(){
	while( cin >> n >> MOD ){
		clr( used , 0 );
		bool ok = dp( 0 , 0 );
		if( !ok ){
			cout << -1 << '\n';
			continue;
		}
		v.clear();
		rec( 0 , 0 );
		cout << v << '\n';
	}
}


