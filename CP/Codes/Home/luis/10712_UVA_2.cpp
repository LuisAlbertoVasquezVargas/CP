#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define N 15

typedef vector< int > vi;
typedef long long ll;

string tos( ll x ){
	ostringstream out;
	out << x;
	return out.str();
}
string target , S;
bool used[ N + 5 ][ N + 5 ][ 2 ][ 2 ];
ll memo[ N + 5 ][ N + 5 ][ 2 ][ 2 ];

ll dp( int pos1 , int pos2 , int menor , int start ){
	//cout << pos1 << " " << pos2 << " " << menor << " " << start << endl;
	if( pos1 == SZ( target ) ) return ( start && term[ pos2 ] );
	if( used[ pos1 ][ pos2 ][ menor ][ start ] ) return memo[ pos1 ][ pos2 ][ menor ][ start ];
	used[ pos1 ][ pos2 ][ menor ][ start ] = 1;
	ll &dev = memo[ pos1 ][ pos2 ][ menor ][ start ] = 0;
	
	if( start ){
		if( menor ){
			for( int i = 0 ; i <= 9 ; ++i ){
				int sig = term[ pos2 ] ? pos2 : next[ pos2 ][ i ];
				dev += dp( pos1 + 1 , sig , 1 , 1 );
			}
		}else{
			for( int i = 0 ; i <= target[ pos1 ] ; ++i ){
				int sig = term[ pos2 ] ? pos2 : next[ pos2 ][ i ];
				dev += dp( pos1 + 1 , sig , i < target[ pos1 ] , 1 );
			}
		}
	}else{
		if( menor ){
			// 0000
			dev += dp( pos1 + 1 , pos2 , 1 , 0 );
			for( int i = 1 ; i <= 9 ; ++i ){
				int sig = term[ pos2 ] ? pos2 : next[ pos2 ][ i ];
				dev += dp( pos1 + 1 , sig , 1 , 1 );
			}
		}else{
			dev += dp( pos1 + 1 , pos2 , 1 , 0 );
			for( int i = 1 ; i <= target[ pos1 ] ; ++i ){
				int sig = term[ pos2 ] ? pos2 : next[ pos2 ][ i ];
				dev += dp( pos1 + 1 , sig , i < target[ pos1 ] , 1 );
			}
			//begin :P
		}
	}
	return dev;
}
void fix( string &s ){
	REP( i , SZ( s ) ) s[ i ] -= '0';
}
ll f( int x , int y ){
	if( y < 0 ) return 0;
	target = tos( y );
	S = tos( x );
	fix( S ) , fix( target );
	init();
	add( S );
	aho();
	clr( used , 0 );
	return (x == 0) + dp( 0 , 0 , 0 , 0 );
}
int main(){
	int n , A , B;
	while( cin >> A >> B >> n ){
		if( n == -1 && A == -1 && B == -1 ) break;
		//cout << f( n , A - 1 ) << " " << f( n , B ) << endl;
		cout << f( n , B ) - f( n , A - 1 ) << '\n';
	}
}


