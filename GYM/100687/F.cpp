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
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef long double ld;
typedef vector< string > vs;

bool doit( string &S , vector< char > &resp , vs &lista , int n ){
	int cnt = 0;
	for( int a = 0 ; a < 8 ; ++a )
		for( int b = 8 ; b < 2 * 8 ; ++b )
			for( int c = 2 * 8 ; c < 3 * 8 ; ++c )
				for( int d = 3 * 8 ; d < 4 * 8 ; d ++ )
					for( int e = 4 * 8 ; e < 5 * 8 ; ++e )
						for( int f = 5 * 8 ; f < 6 * 8 ; ++f ){
							vi v = {a , b , c , d , e , f};
							bool match = 1;
							REP( i , n ){
								int temp = 0;
								REP( j , 6 )
									if( S[ v[ j ] ] != lista[ i ][ v[ j ] ] ) temp ++;
								char caracter = (temp >= 3 ? '-' : '+');
								if( resp[ i ] != caracter ){
									match = 0;
									break;
								}
							}
							if( match ) cnt ++;
							if( cnt >= 2 ) return 0;
						}
	return cnt == 1;
}
int main(){
	string S;
	while( cin >> S ){
		int n;
		cin >> n;
		vector< char > resp( n );
		vs lista( n );
		REP( i , n ) cin >> lista[ i ] >> resp[ i ];
		puts( doit( S , resp , lista , n ) ? "Yes" : "No" );
	}
}



