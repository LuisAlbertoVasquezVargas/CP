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

bool solve( int a1 , int b1 , int a2 , int b2 , int a3 , int b3 ){
	if( a1 >= a2 + a3 && b1 >= max( b2 , b3 ) ) return 1;
	if( a1 >= a2 + b3 && b1 >= max( b2 , a3 ) ) return 1;
	if( a1 >= max( a2 , a3 ) && b1 >= b2 + b3 ) return 1;
	if( a1 >= max( a2 , b3 ) && b1 >= b2 + a3 ) return 1;
	return 0;
}

int main(){
	pii P[ 3 ];
	while( cin >> P[ 0 ].fi >> P[ 0 ].se ){
		REP( i , 3 ){
			if( !i ) continue;
			cin >> P[ i ].fi >> P[ i ].se;
		}
		bool ok = 0;
		REP( k , 2 ){
			if( k ) swap( P[ 1 ] , P[ 2 ] );
			REP( f1 , 2 ){
				if( f1 ) swap( P[ 1 ].fi , P[ 1 ].se );
				REP( f2 , 2 ){
					if( f2 ) swap( P[ 2 ].fi , P[ 2 ].se );
					ok |= solve( P[ 0 ].fi , P[ 0 ].se , P[ 1 ].fi , P[ 1 ].se , P[ 2 ].fi , P[ 2 ].se );
				}			
			}
		}
		puts( ok ? "YES" : "NO" );
	}
}


