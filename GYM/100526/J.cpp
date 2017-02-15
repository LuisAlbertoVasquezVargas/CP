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
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef vector< string > vs;

vi dx = { 0 , -1 , 0 , 1 };
vi dy = { 1 , 0 , -1 , 0 };

int main(){
	ios_base :: sync_with_stdio( 0 );
	int cases;
	cin >> cases;
	cout << cases << '\n';
	REP( tc , cases ){
		string s;
		cin >> s;
		int maxX = 0 , maxY = 0 , minX = 0 , minY = 0 , x = 0 , y = 0 , dir = 0;
		vpii V;
		for( auto c : s ){//left = -1 , right +1  , turn = +2/-2
			V.pb( mp( x ,  y ) );
			//DEBUG2( x , y );
			maxX = max( maxX , x );
			maxY = max( maxY , y );
			
			minX = min( minX , x );
			minY = min( minY , y );
			if( c == 'F' ){
				//nothing
			}else if( c == 'L' ){
				dir = (dir + 1) % 4;
			}else if( c == 'R' ){
				dir = (dir - 1 + 4) % 4;
			}else{
				dir = (dir + 2) % 4;
			}
			x += dx[ dir ];
			y += dy[ dir ];
		}
		
		int lenX = maxX - minX + 1;
		int lenY = maxY - minY + 1;
		lenX += 2 , lenY ++;
		vs S( lenX , string( lenY , '#' ) );
		for( auto p : V ){
			S[ p.fi - minX + 1 ][ p.se - minY ] = '.';
		}
		cout << SZ( S ) << " " << SZ( S[ 0 ] ) << '\n';
		for( auto cad : S ) cout << cad << '\n';
		
	}
}




