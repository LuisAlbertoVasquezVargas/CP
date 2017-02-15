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

int main(){
	int S;
	while( cin >> S ){
		vi d( 10 );
		for( int i = 1 ; i <= 9 ; ++i ) cin >> d[ i ];
		vpii v;
		for( int i = 1 ; i <= 9 ; ++i )
			v.pb( mp( d[ i ] , -i ) );
		sort( all( v ) );
		REP( i , SZ( v ) ) v[ i ].se *= -1;
		int len = S / v[ 0 ].fi;
		string cad( len , '0' + v[ 0 ].se );
		
		S -= len * v[ 0 ].fi;
		REP( i , len ){
			S += v[ 0 ].fi;
			cad[ i ] = '0';
			for( int j = 9 ; j >= 1 ; --j )
				if( S >= d[ j ] ){
					S -= d[ j ];
					cad[ i ] += j;
					break;
				}
			
		}
		if( !SZ(cad) ) cad = "-1";
		cout << cad << '\n';
	}
}


