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

#define test() cout << "hola que hace ?" << endl;
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 25
#define INI 0

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;
int n;
vi vec;
map< vi , vvi > F;
vi get( vi v ){
	vi ans;
	for( int i = 0 ; i < n ; ++i )
		for( int j = i + 1 ; j < n ; ++j )
			ans.pb( vec[ i ] + vec[ j ] );
	sort( all( ans ) );
	return ans;
}
void impr( vi v ){
	for( auto x : v ) cout << x << " ";
	cout << endl;
}
void doit( int pos , int last ){
	if( pos == n ){
		if( SZ(vec) == n ) {
			//test();
			//impr( vec );
			//impr( get( vec ) );
			
			F[ get( vec ) ].pb( vec );
			if( SZ( F[ get( vec ) ] ) > 1 ){
				vvi T = F[ get( vec ) ];
				test();
				for( auto x : T ){
					for( auto y : x ) cout << y << " ";
					cout << endl;
				}
			}
		}
		return;
	}
	for( int i = last + 1 ; i <= INI + N ; ++i ){
		vec.pb( i );
		doit( pos + 1 , i );
		vec.pop_back();
	}
}
void solve( int len ){
	F.clear();
	n = len;
	vec.clear();
	doit( 0 , INI );
	for( auto p : F )
		if( SZ( p.se ) > 1 ){
			vvi T = p.se;
			test();
			for( auto x : T ){
				for( auto y : x ) cout << y << " ";
				cout << endl;
			}
			//return;
		}
}
int main(){
	int n;
	cin >> n;
	solve( n );	
}


