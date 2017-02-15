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

#define N 1000000

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

void safeErase( map< int , int > &mapa , int x ){
	map< int , int > :: iterator it = mapa.find( x );
	mapa.erase( it );
}
int main(){
	vll A , B;
	for( ll x = 0 ; x * x <= N ; ++x ) A.pb( x * x );
	for( ll x = 0 ; x * x <= N ; ++x ) B.pb( 3LL * x * x );
	int n;
	while( sc( n ) == 1 ){
		map< int , int > mapa;
		int maxi = 0;
		REP( i , n * n ){
			int x;
			sc( x );
			maxi = max( maxi , x );
			mapa[ x ] ++;
		}
		
		vi ans;
		ans.pb( maxi );
		mapa[ maxi ] --;
		if( mapa[ maxi ] == 0 ) safeErase( mapa , maxi );
		int last = maxi;
		//DEBUG( maxi );
		while( 1 ){
			if( !SZ( mapa ) ) break;
			map< int , int > :: iterator it = mapa.end();
			it --;
			int pen = (*it).fi;
			mapa[ pen ] --;
			if( mapa[ pen ] == 0 ) safeErase( mapa , pen );
			for( auto x : ans ){
				int g = __gcd( x , pen );
				mapa[ g ] -= 2;
				if( mapa[ g ] == 0 ) safeErase( mapa , g );
			}
			ans.pb( pen );
		}
		for( auto x : ans ) printf( "%d " , x );
		puts( "" );
	}
}


