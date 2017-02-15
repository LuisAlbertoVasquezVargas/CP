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

#define N 100000

#define DEBUG( x ) cout << #x << " " << ( x ) << endl;

typedef long long ll;
typedef vector< ll > vll;
typedef vector< int > vi;
typedef vector< vi > vvi;

int n , timer , top;
vi pa;
vi dfsn , pila , inpila , comp;

int dfs( int u ){
	int low = dfsn[ u ] = ++timer;
	inpila[ pila[ top ++ ] = u ] = 1;
	int v = pa[ u ];
	if( dfsn[ v ] == 0 ) low = min( low , dfs( v ) );
	else if( inpila[ v ] ) low = min( low , dfsn[ v ] );
	
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
	dfsn = pila = inpila = comp = vi( n );
	top = timer = 0;
	REP( i , n ) if( !dfsn[ i ] ) dfs( i );
}

vi A , F ;
vi used;
vll DP , S;
vvi G;
ll dp( int u ){
	if( used[ u ] ) return DP[ u ];
	used[ u ] = 1;
	ll &dev = DP[ u ] = S[ u ];
	for( int v : G[ u ] )
		dev += max( 0LL , dp( v ) );
	return dev;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		sc( n );
		A = pa = F = vi( n );
		REP( i , n ) {
			sc( F[ i ] );
			F[ i ] --;
			pa[ i ] = F[ i ];
		}
		REP( i , n ) sc( A[ i ] );

		SCC();
		
		vi freq( n );
		REP( i , n ) freq[ comp[ i ] ] ++;
		
		S = vll( n );
		REP( i , n ) if( freq[ comp[ i ] ] > 1 ){
			S[ comp[ i ] ] += A[ i ];
		}else S[ i ] = A[ i ];
		G = vvi( n );
		REP( v , n ){
			int u = comp[ F[ v ] ];
			if( comp[ u ] != comp[ v ] ) G[ u ].pb( v );
		}
		DP = vll( n );
		used = vi( n );
		ll ans = 0;
		REP( i , n )
			if( comp[ i ] == i && freq[ comp[ i ] ] > 1 ) {
				ans += max( 0LL , dp( i ) );
			}
		printf( "%lld\n" , ans );
	}
}


