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
 
#define N 100000
 
typedef long long ll;
typedef long double ld;
typedef vector< ld > vld;
typedef pair< int , int > pii;
typedef vector< int > vi;

char cad[ N + 1 ];
int main(){
	int n , S , J , D;
	while( sc( n ) == 1 ){
		sc( S ) , sc( J ) , sc( D );
		scanf( "%s" , cad );
		int Ta = 0 , Tb = 0 , a = 0 , b = 0 ;
		REP( i , n ){
			(cad[ i ] == 'A') ? (a ++) : (b++);
			if( abs(a - b) >= D && max( a , b ) >= J ){
				a > b ? (Ta ++) : (Tb ++);
				a = 0 , b = 0;
			}
			if( Ta == S || Tb == S ){
				printf( "%d %d\n" , Ta , Tb );
				break;
			}
		}
	}
}


