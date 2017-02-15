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

#define test() cerr << "hola q hace" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 100

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef vector< vvpii > vvvpii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector< vvvi > vvvvi;

ll F[ N + 5 ];
void impr( vi &v ){
	REP( i , SZ( v ) ) printf( "%d%c" , v[ i ] , (i + 1 == SZ(v) ? 10 : 32 ) ); 
}
int main(){
	F[ 1 ] = 1;
	F[ 2 ] = 2;
	for( int i = 3 ; i <= N ; ++i )
		F[ i ] = F[ i - 1 ] + F[ i - 2 ];
	//REP( i , 11 ) DEBUG( F[ i ] );
	ll n , K;
	while( cin >> n >> K ){
		vi ans;
		int cur = 1;
		while( n ){
			
			/*
			DEBUG( n );
			DEBUG( cur );
			DEBUG( K );
			*/
			//impr( ans );
			assert( K <= F[ n ] );
			
			if( n >= 2 && K > F[ n - 1 ] ){
				ans.pb( cur + 1 );
				ans.pb( cur );
				cur += 2;
				K -= F[ n - 1 ];
				n -= 2;
			}else{
				ans.pb( cur ++ );
				n --;
			}
		}
		//DEBUG( K );
		//DEBUG( n );
		impr( ans );
	}	
}


