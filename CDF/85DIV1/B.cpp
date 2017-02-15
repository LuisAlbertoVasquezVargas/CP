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
typedef pair< int , int > pii;
typedef vector< int > vi;

int id[ N + 1 ] , len[ N + 1 ];
int Find( int x ){ return id[ x ] = (id[ x ] == x ? x : Find( id[ x ] ) );}
void Union( int u , int v ){
	int pu = Find( u ) , pv = Find( v );
	if( pu != pv ){
		len[ pv ] += len[ pu ];
		id[ pu ] = pv;
	}
}
struct Edge{
	int u , v , maxi , mini ;
	Edge(){}
	Edge( int _u , int _v , int cu , int cv ){
		u = _u;
		v = _v;
		mini = min( cu , cv );
		maxi = max( cu , cv );
	}
};

bool operator < ( const Edge &e1 , const Edge &e2 ){
	return e1.mini > e2.mini;
}

int n;
void init(){
	REP( i , n ) id[ i ] = i , len[ i ] = 1;
}
int main(){
	int m;
	while( sc( n ) == 1 ){
		sc( m );
		vi A( n );
		REP( i , n ) sc( A[ i ] );
		init();
		
		vector< Edge > E , E2;
		REP( i , m ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			E.pb( Edge( u , v , A[ u ] , A[ v ] ) );
		}
		sort( all( E ) );
		for( auto e : E ){
			int u = e.u , v = e.v , w = e.mini;
			if( Find( u ) == Find( v ) ) continue;
			Union( u , v );
			E2.pb( e );
		}
		init();
		ld ans = 0;
		for( auto e : E2 ){
			int u = e.u , v = e.v , w = e.mini;
			if( Find( u ) == Find( v ) ) continue;
			int pu = Find( u ) , pv = Find( v );
			ans += (ll)len[ pu ] * (ll)len[ pv ] * (ll)w;
			Union( u , v );
		}
		ans /= (ld)(n);
		ans /= (ld)(n - 1);
		ans *= 2.0;
		printf( "%.15f\n" , (double)ans );
	}
}


