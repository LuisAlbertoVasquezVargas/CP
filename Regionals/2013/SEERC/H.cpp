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

vi dx = { -1 , 0 , 1 , 0 };
vi dy = { 0 , 1 , 0 , -1 };
void safeErase( set< pii > &SET , pii p ){
	set< pii > :: iterator it = SET.lower_bound( p );
	SET.erase( it );
}
map< set< pii > , int > memo;
int f( set< pii > SET ){
	if( memo.count( SET ) ) return memo[ SET ];
	int &dev = memo[ SET ] = 0;
	if( SZ( SET ) == 1 ) return dev = 1;
	for( auto p : SET ){
		int x = p.fi , y = p.se;
		REP( k , 4 ){
			int nx = x + dx[ k ] , ny = y + dy[ k ];
			int nnx = x + 2 * dx[ k ] , nny = y + 2 * dy[ k ];
			if( SET.count( mp( nx , ny ) ) && !SET.count( mp( nnx , nny ) ) ){
				set< pii > nSET = SET;
				safeErase( nSET , mp( x , y ) );
				safeErase( nSET , mp( nx , ny ) );
				nSET.insert( mp( nnx , nny ) );
				if( f( nSET ) ) return dev = 1;
			}
		}
	}
	return dev = 0;
}

int main(){
	int n;
	while( cin >> n ){
		set< pii > SET;
		REP( i , n ) REP( j , n ) SET.insert( mp( i , j ) );
		cout << f( SET ) << '\n'; 
	}
}



