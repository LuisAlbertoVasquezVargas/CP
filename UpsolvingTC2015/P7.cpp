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

#define N 20000
#define M 50000

typedef vector< int > vi;
typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;

int n , timer , top;
vi G[ N + 5 ];
int dfsn[ N + 5 ] , pila[ N + 5 ] , inpila[ N + 5 ] , comp[ N + 5 ];

int dfs( int u ){
	int low = dfsn[ u ] = ++timer;
	inpila[ pila[ top ++ ] = u ] = 1;
	for( int v : G[ u ] ){
		if( dfsn[ v ] == 0 ) low = min( low , dfs( v ) );
		else if( inpila[ v ] ) low = min( low , dfsn[ v ] );
	}
	if( low == dfsn[ u ] ){
		int fin;
		do{
			fin = pila[ --top ];
			inpila[ fin ] = 0;
			comp[ fin ] = u;
		}while( fin != u );
	}
	return low;
}

void SCC(){
	clr( dfsn , 0 );
	top = timer = 0;
	REP( i , n ) if( !dfsn[ i ] ) dfs( i );
}
int orig[ M + 5 ] , dest[ M + 5 ];

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		sc( n );
		int m;
		sc( m );
		REP( i , n ) G[ i ].clear();	
		REP( i , m ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			G[ u ].pb( v );
			orig[ i ] = u;
			dest[ i ] = v;
		}
		SCC();
		vi ind( n ) , out( n ) , F( n );
		REP( i , n ) F[ comp[ i ] ] ++;
		REP( i , m ){
			int u = orig[ i ] , v = dest[ i ];
			if( comp[ u ] != comp[ v ] ){
				u = comp[ u ];
				v = comp[ v ];
				ind[ v ] ++;
				out[ u ] ++;
			}
		}
		if( F[ comp[ 0 ] ] == n ){
			puts( "0" );
			continue;
		}
		int a = 0 , b = 0;
		REP( i , n )
			if( comp[ i ] == i && ind[ i ] == 0 ) a ++;
		REP( i , n )
			if( comp[ i ] == i && out[ i ] == 0 ) b ++;
		printf( "%d\n" , max(a , b) );
	}
}




