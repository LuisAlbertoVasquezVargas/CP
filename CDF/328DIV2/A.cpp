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
typedef vector< string > vs;


const int n = 8;

int get( vs S , char c , int posX , int dir ){
	int ans = INT_MAX/3;
	REP( i , n )REP( j , n ){
		if( S[ i ][ j ] == c ){
			int ind = i;
			for( int k = 0 ; k <= 8 ; ++k ){
				int ni = i + dir * k;
				int nj = j;
				if( ni >= 0 && ni < n && (S[ ni ][ nj ] == c || S[ ni ][ nj ] == '.' ) )
					ind = ni;
				else break;
			}
			if( ind == posX ) ans = min( ans , abs( ind - i ) );
		}
	}
	return ans;
}
int main(){
	vs S( n );
	while( cin >> S[ 0 ] ){
		REP( i , n ){
			if( !i ) continue;
			cin >> S[ i ];
		}
		int tA = get( S , 'W' , 0 , -1 );
		int tB = get( S , 'B' , 7 , +1 );
		//DEBUG2( tA , tB );
		if( tA <= tB ){
			puts( "A" );
			continue;
		}
		puts( "B" );
	}	
}




