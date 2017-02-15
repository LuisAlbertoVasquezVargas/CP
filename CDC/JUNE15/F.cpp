#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
 
#define sc(x) scanf( "%d" , &x )
#define REP(i , n) for( int i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )
 
#define pb push_back
#define all(v) v.begin() , v.end()
#define SZ(v) ((int)(v).size())
 
#define mp make_pair
#define fi first
#define se second

#define N 1000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;

int X[ N + 5 ][ N + 5 ];

vvi G;
vvi memo , used;
int dp( int pos , int zeroes , int ones , vvvi &v ){
	if( pos == SZ( v ) ) return 0;
	if( used[ pos ][ zeroes ] ) return memo[ pos ][ zeroes ];
	used[ pos ][ zeroes ] = 1;
	int &dev = memo[ pos ][ zeroes ] = 0;
	REP( k , 2 ){
		int lenZeroes = SZ( v[ pos ][ k ] );
		int lenOnes = SZ( v[ pos ][ k ^ 1 ] );
		dev = max( dev , lenZeroes * ones +  lenOnes * zeroes
			+ dp( pos + 1 , zeroes + lenZeroes , ones + lenOnes , v ) );
	}
	return dev;
}
void Fill( vi vec , int value , vi &v ){
	for( int x : vec ) v[ x ] = value;
}
void rec( int pos , int zeroes , int ones , vvvi &v , vi &cur ){
	if( pos == SZ( v ) ) return;
	REP( k , 2 ){
		int lenZeroes = SZ( v[ pos ][ k ] );
		int lenOnes = SZ( v[ pos ][ k ^ 1 ] );
		if( dp( pos , zeroes , ones , v ) == lenZeroes * ones +  lenOnes * zeroes
			+ dp( pos + 1 , zeroes + lenZeroes , ones + lenOnes , v ) ){
			Fill( v[ pos ][ k ] , 0 , cur );
			Fill( v[ pos ][ k ^ 1 ] , 1 , cur );
			rec( pos + 1 , zeroes + lenZeroes , ones + lenOnes , v , cur );
			return;
		}
	}
}

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		
		int n;
		sc( n );
		G = vvi( n );
		
		REP( i , n ) REP( j , n ) sc( X[ i ][ j ] );
		
		REP( i , n ) REP( j , n )
			if( X[ i ][ j ] ) G[ i ].pb( j );

		vvvi vec;
		
		bool possible = 1;
		vi color( n , -1 );
		REP( s , n ){
			if( !possible ) break;
			if( color[ s ] != -1 ) continue;
			queue< int > Q;
			vvi groups( 2 );
			Q.push( s );
			color[ s ] = 0;
			groups[ 0 ].pb( s );
			while( !Q.empty() ){
				int u = Q.front(); Q.pop();
				for( int v : G[ u ] ){
					if( color[ v ] == -1 ){
						Q.push( v );
						color[ v ] = color[ u ] ^ 1;
						groups[ color[ v ] ].pb( v );
					}else if( color[ v ] == color[ u ] ){
						possible = 0;
						break;
					}
				}
			}
			vec.pb( groups );
		}
		if( !possible ){
			puts( "-1" );
			continue;
		}
		used = memo = vvi( SZ( vec ) , vi( n ) );
		//cout << dp( 0 , 0 , 0 , vec ) << endl;
		dp( 0 , 0 , 0 , vec );
		vi cur( n , - 1 );
		rec( 0 , 0 , 0 , vec , cur );
		REP( i , n ) printf( "%d%c" , cur[ i ] , (i + 1 == n) ? 10 : 32 );
	}
}


