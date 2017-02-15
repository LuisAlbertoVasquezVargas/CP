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
typedef long double ld;


int main(){
	ll a , b , c;
	while( cin >> a >> b >> c ){
		if( a == 0 ){
			if( b == 0 ){
				if( c == 0 ){
					puts( "-1" );
				}else{
					puts( "0" );
				}
			}else{
				ld r = - (ld)c / (ld)b;
				puts( "1" );
				printf( "%.15f\n" ,(double)(r) );
			}
		}else{
			ll d = b * b - 4 * a * c;
			if( d < 0 ){
				puts( "0" );
				continue;
			}
			if( d == 0 ){
				ld r = - (ld)b / (ld)(2 * a);
				puts( "1" );
				printf( "%.15f\n" ,(double)(r) );
			}else{
				ld r1 = (ld)( - b - sqrt( d ) ) / (ld)(2 * a);
				ld r2 = (ld)( - b + sqrt( d ) ) / (ld)(2 * a);
				puts( "2" );
				if( r1 > r2 ) swap( r1 , r2 );
				printf( "%.15f\n" ,(double)(r1) );
				printf( "%.15f\n" ,(double)(r2) );
			}
		}
	}
}



