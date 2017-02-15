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

#define N 256

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int solve( int X , int Y , int t ){
	for( int cx = 0 ; 2 * cx <= X ; ++cx ){
		int cy = X - 2 * cx;
		int cv = t - (cx + cy);
		int cu = Y - cv;
		if( cy >= 0 && cv >= 0 && cu >= 0 ) return cx;
	}
	return -1;
}
int mat[ N + 1 ][ N + 1 ]; 
int main(){
	for( char x = 'a' ; x <= 'z' ; ++x )
		for( char y = 'a' ; y <= 'z' ; ++y ){
			for( char z = 'a' ; z <= 'z' ; ++z )
				if( x != z && y != z ){
					mat[ x ][ y ] = z;
					break;
				}
		}
			
	ios_base :: sync_with_stdio( 0 );
	int n , target;
	while( cin >> n >> target ){
		string a , b;
		cin >> a >> b;
		vi X , Y;
		REP( i , n )
			if( a[ i ] != b[ i ] ) X.pb( i );
			else Y.pb( i );
		int cx = solve( SZ(X) , SZ(Y) , target );
		if( cx == -1 ){
			cout << -1 << '\n';
			continue;
		}
		int cy = SZ(X) - 2 * cx;
		int cv = target - (cx + cy);
		int cu = SZ(Y) - cv;
		string ans( n , '*' );
		REP( i , SZ(X) )
			if( i < cx ) ans[ X[ i ] ] = a[ X[ i ] ];
			else if( i < 2 * cx ) ans[ X[ i ] ] = b[ X[ i ] ];
			else ans[ X[ i ] ] = mat[ a[ X[ i ] ] ][ b[ X[ i ] ] ];
		
		REP( i , SZ( Y ) )
			if( i < cu ) ans[ Y[ i ] ] = a[ Y[ i ] ];
			else ans[ Y[ i ] ] = mat[ a[ Y[ i ] ] ][ b[ Y[ i ] ] ];
		cout << ans << '\n';
	}
}


