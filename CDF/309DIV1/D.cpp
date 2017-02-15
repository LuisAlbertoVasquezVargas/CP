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

#define N 100000

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef long double ld;

int n , m;
bool forb[ N + 5 ];
int orig[ N + 5 ] , dest[ N + 5 ];
int deg[ N + 5 ];
vi G[ N + 5 ];
void clear(){
	REP( i , n ) {
		G[ i ].clear();
		forb[ i ] = 0;
		deg[ i ] = 0;
	}
}
int can[ N + 5 ] , vis[ N + 5 ] , DEG[ N + 5 ];
bool f( ld &t ){
	REP( i , n ) can[ i ] = vis[ i ] = 0 , DEG[ i ] = 0;
	
	REP( i , n ) if( !forb[ i ] ) can[ i ] = 1;
	REP( i , m ){
		int u = orig[ i ];
		int v = dest[ i ];
		if( forb[ u ] || forb[ v ] ) continue;
		DEG[ u ] ++ , DEG[ v ] ++;
	}
	
	queue< int > Q;
	REP( u , n )
		if( can[ u ] ){
			if( !(DEG[ u ] >= deg[ u ] * t) ){
				can[ u ] = 0;
				Q.push( u );
			}
		}
	
	while( !Q.empty() ){
		int u = Q.front();
		Q.pop();
		for( auto v : G[ u ] ){
			DEG[ v ] --;
			if( can[ v ] ){
				if( !(DEG[ v ] >= deg[ v ] * t) ){
					Q.push( v );
					can[ v ] = 0;
				}
			}

		}
	}
	REP( u , n )
		if( can[ u ] ) return 1;
	return 0;
}

int main(){
	int K ;
	while( sc( n ) == 1 ){
		sc( m ) , sc( K );
		clear();
		REP( i,  K ) {
			int u;
			sc( u );
			u --;
			forb[ u ] = 1;
		}
		REP( i , m ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			orig[ i ] = u;
			dest[ i ] = v;
			deg[ u ] ++;
			deg[ v ] ++;
			G[ u ].pb( v );
			G[ v ].pb( u );
		}
		ld lo = 0 , hi = 1.0;
		REP( it , 100 ){
			ld med = (lo + hi)/2.0;
			//DEBUG2( med , f( med ) );
			if( f(med) ) lo = med;
			else hi = med;
		}
		f( lo );
		vi vec;
		REP( i , n )
			if( can[ i ] ) vec.pb( i );
		printf( "%d\n" , SZ(vec) );
		REP( i , SZ(vec) ) printf( "%d%c" , vec[ i ] + 1 , (i + 1 == SZ(vec)) ? 10 : 32 );
	}
}


