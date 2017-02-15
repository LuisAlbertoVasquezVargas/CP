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

#define N 150

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef vector< string > vs;

int id[ N + 1 ];
int Find( int x ){ return id[ x ] = (id[ x ] == x ? x : Find( id[ x ] ) );}
void Union( int u , int v ){
	int pu = Find( u ) , pv = Find( v );
	if( pu != pv ) id[ pu ] = pv;
}
int main(){
	//points.in 
	freopen( "points.in" , "r" , stdin );
	freopen( "points.out" , "w" , stdout );
	int n , m ;
	while( sc( n ) == 1 ){
		sc( m );
		REP( i , n ) id[ i ] = i;
		REP( i , m ){
			int u , v;
			sc( u ) , sc( v );
			u -- ,v --;
			Union( u , v );
		}
		int cnt = 0;
		REP( i , n ) if( Find( i ) == i ) cnt ++;
		puts( !(cnt & 1) ? "Andrew" : "Betty" );
	}
}

